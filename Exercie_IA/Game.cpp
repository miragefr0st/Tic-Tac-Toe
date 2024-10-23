#include "Game.h"
#include <iostream>

Game::Game(Player* p1, Player* p2) : player1(p1), player2(p2) {}

void Game::play() {
    Player* currentPlayer = player1;
    int turn = 0;

    while (true) {
        std::cout << "\n\n--- Tour " << ++turn << " ---\n";
        std::cout << "C'est au joueur " << currentPlayer->getSymbol() << " de jouer.\n\n";
        board.print();

        currentPlayer->makeMove(board);

        if (board.isWin(currentPlayer->getSymbol())) {
            std::cout << "\n";
            std::cout << "\n\n--- resulat ---\n";
            board.print();
            std::cout << "Le joueur " << currentPlayer->getSymbol() << " a gagne apres " << turn << " tours !\n";
            break;
        }
        else if (board.isFull()) {
            std::cout << "\n";
            std::cout << "\n\n--- resulat ---\n";
            board.print();
            std::cout << "Match nul apres " << turn << " tours !\n";
            break;
        }

        currentPlayer = (currentPlayer == player1) ? player2 : player1;
    }

    std::cout << "\nRetour au menu principal.\n";
}