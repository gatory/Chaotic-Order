#include "../../include/Computer.h"

Computer::Computer(ObjectiveType objective, bool hasNextTurn): Player(objective, hasNextTurn) {}

struct Decision Computer::makingDecision() {
    Decision decision;

    
    decision.piece = Piece::na;
    
    return decision;
}
