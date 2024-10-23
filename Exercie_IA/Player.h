#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"

class Player {
public:
    virtual ~Player() = default;

    // Doit être implémenté par HumanPlayer et AIPlayer
    virtual void makeMove(Board& board) = 0;

    char getSymbol() const { return symbol; }

protected:
    char symbol; // 'X' ou 'O'
};

#endif // PLAYER_H

