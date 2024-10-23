#include "AIPlayer.h"
#include <limits>
#include <cstdlib>
#include <ctime>

AIPlayer::AIPlayer(char symb, char oppSymb, double errorRate)
    : opponentSymbol(oppSymb), errorRate(errorRate) {
    symbol = symb;
    std::srand(static_cast<unsigned>(std::time(0))); // Initialisation pour la génération aléatoire
}

void AIPlayer::makeMove(Board& board) {
    int bestScore = std::numeric_limits<int>::min();
    int bestRow = -1;
    int bestCol = -1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board.getBoard()[i][j] == ' ') {
                board.makeMove(i, j, symbol);
                int score = minimax(board, 0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                board.undoMove(i, j);

                if (score > bestScore) {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    if (shouldMakeMistake()) {
        // Si l'IA décide de faire une erreur, elle choisit un mouvement aléatoire valide
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.getBoard()[i][j] == ' ') {
                    bestRow = i;
                    bestCol = j;
                    break;
                }
            }
        }
    }

    board.makeMove(bestRow, bestCol, symbol);
}

bool AIPlayer::shouldMakeMistake() const {
    return (static_cast<double>(std::rand()) / RAND_MAX) < errorRate;
}

// La logique minimax reste la même, avec coupure alpha-beta
int AIPlayer::minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta) {
    if (board.isWin(symbol)) return 10 - depth;
    if (board.isWin(opponentSymbol)) return depth - 10;
    if (board.isFull()) return 0;

    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.getBoard()[i][j] == ' ') {
                    board.makeMove(i, j, symbol);
                    int score = minimax(board, depth + 1, false, alpha, beta);
                    board.undoMove(i, j);
                    bestScore = std::max(score, bestScore);
                    alpha = std::max(alpha, score);
                    if (beta <= alpha) return bestScore; // Coupure alpha-beta
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = std::numeric_limits<int>::max();
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board.getBoard()[i][j] == ' ') {
                    board.makeMove(i, j, opponentSymbol);
                    int score = minimax(board, depth + 1, true, alpha, beta);
                    board.undoMove(i, j);
                    bestScore = std::min(score, bestScore);
                    beta = std::min(beta, score);
                    if (beta <= alpha) return bestScore; // Coupure alpha-beta
                }
            }
        }
        return bestScore;
    }
}
