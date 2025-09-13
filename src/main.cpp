#include <raylib.h>
#include <iostream>
#include "../include/GameBoard.h"
#include "../include/Constants.h"
#include "../include/Cell.h"
#include "../include/PieceType.h"
// #include "../include/Player.h"
#include "../include/Human.h"
#include "../include/Computer.h"
#include <random>
#include <cstdlib>
#include <ctime>
#include <assert.h>

using namespace std;

int main() {
    
    const static int SCREEN_WIDTH = 1000;
    const static int SCREEN_HEIGHT = 720;

    srand(time(0));
    int randomObjective = rand();
    int randomNextTurn = rand();
    
    cout << "Starting the game..." << endl;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chaotic-Order");
    SetTargetFPS(60);
    
    GameBoard game = GameBoard(10, SCREEN_HEIGHT);    
    Human humanPlayer = Human(ObjectiveType::CHAOS, true);
    Computer computerPlayer = Computer(ObjectiveType::ORDER, false, game);

    
    // if (randomObjective % 2 == 0) {
    //     if (randomNextTurn % 2 == 0) {
    //         humanPlayer = Human(ObjectiveType::CHAOS, true);
    //         computerPlayer = Computer(ObjectiveType::ORDER, false);
    //     } else {
    //         humanPlayer = Human(ObjectiveType::CHAOS, false);
    //         computerPlayer = Computer(ObjectiveType::ORDER, true);
    //     }
    // } else {
    //     if (randomNextTurn % 2 == 0) {
    //         humanPlayer = Human(ObjectiveType::ORDER, true);
    //         computerPlayer = Computer(ObjectiveType::CHAOS, false);
    //     } else {
    //         humanPlayer = Human(ObjectiveType::ORDER, false);
    //         computerPlayer = Computer(ObjectiveType::CHAOS, true);
    //     }
    // }

    // Checks
    assert(humanPlayer.getObjective() != computerPlayer.getObjective());
    assert(humanPlayer.getHasNextTurn() != computerPlayer.getHasNextTurn());
    

    while (!WindowShouldClose()) {
        if (game.checkGameOver()) {
            break;
        }

        if (humanPlayer.getHasNextTurn()) {
            cout << "Human turn" << endl;
            Decision dec = humanPlayer.makingDecision();
            int gridX = dec.pos.x / game.getCellSize();
            int gridY = dec.pos.y / game.getCellSize();

            if (dec.piece != Piece::na && game.checkValidMove(gridX, gridY)) {
                humanPlayer.setHasNextTurn(false);
                computerPlayer.setHasNextTurn(true);
                game.setPlayerMove(dec.pos, dec.piece);
            }
        } else if (computerPlayer.getHasNextTurn()) {
            cout << "Computer turn" << endl;
            Decision dec = computerPlayer.makingDecision();
            
            if (dec.piece != Piece::na && game.checkValidMove(dec.pos.x, dec.pos.y)) {
                humanPlayer.setHasNextTurn(true);
                computerPlayer.setHasNextTurn(false);
                dec.pos.x *= game.getCellSize();
                dec.pos.y *= game.getCellSize();
                game.setPlayerMove(dec.pos, dec.piece);
            }
        }

        BeginDrawing();
        ClearBackground(Constants::BG_COLOR);
        game.drawCurrentPanel();
        // game.setPlayerMove(GetMousePosition(), Piece::na);
        // cout << game.checkOrderWin() << endl;
        // game.checkOrderWin();
        game.printBoard();
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
