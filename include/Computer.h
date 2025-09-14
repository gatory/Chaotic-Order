#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <iostream>
#include "GameBoard.h"


class Computer: public Player
{
private:
    GameBoard &game;
public:
    Computer();

    Computer(ObjectiveType objective, GameBoard &game);
    
    bool wouldCreateWinningSequence(int row, int col, Piece piece, int targetAlign);

    Decision considerObjective(ObjectiveType objective, Decision decision);

    struct Decision makingDecision() override;

    int getPotential(int row, int col, Piece piece, int targetAlign);
};

#endif
