#include "HumanPlayer.h"

void HumanPlayer::makeMove(Board& board) {
    int row, col;
    bool validMove = false;

    while (!validMove) {
        std::cout << "Joueur " << symbol << ", entrez la ligne et la colonne (0, 1 ou 2) : ";
        std::cin >> row >> col;
        validMove = board.makeMove(row, col, symbol);
        if (!validMove) {
            std::cout << "Mouvement invalide, reessayez.\n";
        }
    }
}
