#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();

    // Affichage du plateau
    void print() const;

    // V�rification de l'�tat du jeu
    bool isFull() const;
    bool isWin(char player) const;

    // Effectuer un mouvement
    bool makeMove(int row, int col, char player);

    // Annuler un mouvement
    void undoMove(int row, int col);

    // Acc�s au plateau
    std::vector<std::vector<char>> getBoard() const;

private:
    std::vector<std::vector<char>> grid; // Plateau 3x3
};

#endif // BOARD_H
