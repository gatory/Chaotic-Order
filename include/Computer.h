#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"
#include <iostream>


class Computer: public Player
{
public:
    Computer(ObjectiveType objective, bool hasNextTurn);

    struct Decision makingDecision() override;
};

#endif
