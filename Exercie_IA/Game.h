#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game {
public:
    Game(Player* p1, Player* p2);
    void play();

private:
    Board board;
    Player* player1;
    Player* player2;
};

#endif // GAME_H
