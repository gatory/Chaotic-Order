#include "../../include/Computer.h"
#include <random>
#include <cstdlib>
#include <ctime>

Computer::Computer(): Player(ObjectiveType::DEFAULT, false) {}

Computer::Computer(ObjectiveType objective, bool hasNextTurn, GameBoard game): Player(objective, hasNextTurn), game(game) {}

struct Decision Computer::makingDecision() {
    Decision decision;

    int countToBeat = 0;
    vector<int> vec;


    return decision;
}