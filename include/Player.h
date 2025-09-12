#include <iostream>
#include "ObjectiveType.h"
#include "PieceType.h"

using namespace std;

struct Decision {
    int xIndx;
    int yIndx;
    Piece piece;
};

class Player
{
private:
    ObjectiveType objective;
    bool hasNextTurn;
    /* data */
public:
    Player(ObjectiveType objective, bool hasNextTurn);

    virtual struct Descision makeDecision() = 0;

    ~Player();
};