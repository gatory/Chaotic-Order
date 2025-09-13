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
    bool hasNextTurn;
public:
    Player();
    
    Player(ObjectiveType objective, bool hasNextTurn);

    ObjectiveType getObjective();

    bool getHasNextTurn();

    void setHasNextTurn(bool value);

    virtual struct Decision makingDecision() = 0;

    virtual ~Player() = default;

};

#endif
