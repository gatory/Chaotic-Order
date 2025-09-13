#include "../../include/Computer.h"
#include "../../include/GameBoard.h"
#include <random>
#include <cstdlib>
#include <ctime>

Computer::Computer(ObjectiveType objective, bool hasNextTurn, GameBoard &game): 
    Player(objective, hasNextTurn), game(game) {}

struct Decision Computer::makingDecision() {
    Decision decision;
    vector<vector<Piece>> GAMBOARD_COPY = game.getGameBoard();
    for (int row = 0; row < GAMBOARD_COPY.size(); row++) {
        for (int col = 0; col < GAMBOARD_COPY.size(); col++) {
            cout << row << ", " << col << endl;
            if (GAMBOARD_COPY[row][col] == Piece::na) {
                GAMBOARD_COPY[row][col] = Piece::o;
                cout << game.checkOrderWin(1);
                if (game.checkOrderWin(1)) {
                    Vector2 pos = {row, col};
                    decision.pos = pos;
                    decision.piece = Piece::o;
                    return decision;
                }
                cout << game.checkOrderWin(1) << endl;
                GAMBOARD_COPY[row][col] = Piece::x;
                if (game.checkOrderWin(1)) {
                    Vector2 pos = {row, col};
                    decision.pos = pos;
                    decision.piece = Piece::x;
                    return decision;
                }
            }
        }
    }
    
    srand(time(0));
    int randRow = rand() % 9;
    int randCol = rand() % 9;
    int randomPiece = rand() % 2;
    if (randomPiece == 0) {
        decision.piece = Piece::o;
    } else {
        decision.piece = Piece::x;
    }
    Vector2 vec = {randRow, randCol};
    decision.pos = vec;

    return decision;
}