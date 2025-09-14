#include "../../include/Player.h"

Player::Player(ObjectiveType objective): objective(objective) {}

ObjectiveType Player::getObjective() {
    return objective;
}