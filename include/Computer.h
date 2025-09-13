#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <iostream>
#include "GameBoard.h"


class Computer: public Player
{
private:
    GameBoard game;
public:
    Computer();

    Computer(ObjectiveType objective, bool hasNextTurn, GameBoard game);

    struct Decision makingDecision() override;
    bool getVecOnBoard(int rowStart, int rowEnd, int col, int dx, int dy);
};

#endif
