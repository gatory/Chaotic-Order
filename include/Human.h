#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"
#include <iostream>


class Human: public Player
{
public:
    Human();
    
    Human(ObjectiveType objective, bool hasNextTurn);

    struct Decision makingDecision() override;
};

#endif
