#include "../../include/Human.h"

Human::Human(): Player(ObjectiveType::DEFAULT, false) {}

Human::Human(ObjectiveType objective, bool hasNextTurn): Player(objective, hasNextTurn) {}

struct Decision Human::makingDecision() {
    Decision decision;
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        decision = {GetMousePosition(), Piece::o};
    } else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        decision = {GetMousePosition(), Piece::x};
    } else {
        decision.piece = Piece::na;
    }
    
    return decision;
}
