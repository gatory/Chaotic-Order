#include "../../include/Human.h"

Human::Human(ObjectiveType objective, bool hasNextTurn): Player(objective, hasNextTurn) {}

struct Decision Human::makingDecision() {
    Decision decision;

    
    decision.piece = Piece::na;
    
    return decision;
}
