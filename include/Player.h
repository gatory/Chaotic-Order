#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "ObjectiveType.h"
#include "PieceType.h"
#include <raylib.h>

using namespace std;

struct Decision {
    Vector2 pos = {-10, -10};
    Piece piece;
};

class Player
{
protected:
    ObjectiveType objective;
public:
    Player();
    
    Player(ObjectiveType objective);

    ObjectiveType getObjective();

    virtual struct Decision makingDecision() = 0;

    virtual ~Player() = default;

};

#endif
