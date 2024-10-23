#include "Board.h"
#include <iostream>

Board::Board() : grid(3, std::vector<char>(3, ' ')) {}

void Board::print() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "---------\n";
    }
}

bool Board::isFull() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

bool Board::isWin(char player) const {
    // Vérification des lignes, colonnes et diagonales
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;
    return false;
}

bool Board::makeMove(int row, int col, char player) {
    if (grid[row][col] == ' ') {
        grid[row][col] = player;
        return true;
    }
    return false;
}

void Board::undoMove(int row, int col) {
    grid[row][col] = ' ';
}

std::vector<std::vector<char>> Board::getBoard() const {
    return grid;
}
