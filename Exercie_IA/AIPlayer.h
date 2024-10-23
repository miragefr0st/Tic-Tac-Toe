#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {
public:
    AIPlayer(char symb, char oppSymb, double errorRate = 0.1); // Ajout du taux d'erreur

    void makeMove(Board& board) override;

private:
    char opponentSymbol;
    double errorRate; // Probabilit� que l'IA fasse un mauvais choix

    int minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta);
    int evaluate(Board& board);
    bool shouldMakeMistake() const; // D�terminer si l'IA fait une erreur
};

#endif // AIPLAYER_H
