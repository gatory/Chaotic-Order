#include "../../include/Player.h"

Player::Player(ObjectiveType objective, bool hasNextTurn): objective(objective), 
                                                           hasNextTurn(hasNextTurn){}

ObjectiveType Player::getObjective() {
    return objective;
}

bool Player::getHasNextTurn() {
    return hasNextTurn;
}

void Player::setHasNextTurn(bool value) {
    hasNextTurn = value;
}
