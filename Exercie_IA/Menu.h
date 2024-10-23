#ifndef MENU_H
#define MENU_H

#include "Game.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"

class Menu {
public:
    void displayMenu();

private:
    void playHumanVsHuman();
    void playHumanVsAI();
    void playAIvsAI();
};

#endif // MENU_H
