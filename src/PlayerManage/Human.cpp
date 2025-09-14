#include "../../include/Human.h"

Human::Human(ObjectiveType objective): Player(objective) {}

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
