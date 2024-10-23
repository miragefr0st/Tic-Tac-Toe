#include "Menu.h"
#include <iostream>

void Menu::displayMenu() {
    int choice = 0;

    while (true) {
        std::cout << "\n=== Menu Principal ===\n";
        std::cout << "1. Jouer contre un autre joueur\n";
        std::cout << "2. Jouer contre l'IA\n";
        std::cout << "3. IA contre IA\n";
        std::cout << "4. Quitter\n";
        std::cout << "Choisissez une option : ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            playHumanVsHuman();
            break;
        case 2:
            playHumanVsAI();
            break;
        case 3:
            playAIvsAI();
            break;
        case 4:
            std::cout << "Merci d'avoir joue !\n";
            return;
        default:
            std::cout << "Choix invalide. Veuillez reessayer.\n";
            break;
        }
    }
}

void Menu::playHumanVsHuman() {
    HumanPlayer p1('X');
    HumanPlayer p2('O');
    Game game(&p1, &p2);
    game.play();
}

void Menu::playHumanVsAI() {
    HumanPlayer human('X');
    AIPlayer ai('O', 'X');
    Game game(&human, &ai);
    game.play();
}

void Menu::playAIvsAI() {
    AIPlayer ai1('X', 'O');
    AIPlayer ai2('O', 'X');
    Game game(&ai1, &ai2);
    game.play();
}
