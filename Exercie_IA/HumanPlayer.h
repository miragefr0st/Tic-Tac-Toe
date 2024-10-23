#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include <iostream>

class HumanPlayer : public Player {
public:
    HumanPlayer(char symb) { symbol = symb; }

    void makeMove(Board& board) override;
};

#endif // HUMANPLAYER_H
