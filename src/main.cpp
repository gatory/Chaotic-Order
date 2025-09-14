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
    bool humanTurn = randomNextTurn % 2 == 0;

    cout << "Starting the game..." << endl;
    InitAudioDevice();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chaotic-Order");
    SetTargetFPS(60);
    
    GameBoard game = GameBoard(10, SCREEN_HEIGHT);    
    Human humanPlayer = Human(randomObjective % 2 == 0 ? ObjectiveType::ORDER : ObjectiveType::CHAOS);
    Computer computerPlayer = Computer(randomObjective % 2 == 0 ? ObjectiveType::CHAOS : ObjectiveType::ORDER, game);

    // Checks
    assert(humanPlayer.getObjective() != computerPlayer.getObjective());
    
    while (!WindowShouldClose()) {
        if (game.checkGameOver()) {
            break;
        }

        if (humanTurn) {
            cout << "Human Turn" << endl;
            Decision dec = humanPlayer.makingDecision();
            int gridX = (dec.pos.x / game.getCellSize()) - 1;
            int gridY = (dec.pos.y / game.getCellSize()) - 1;
            
            if (dec.piece != Piece::na && game.checkValidMove(gridX, gridY)) {
                game.setPlayerMove(dec.pos, dec.piece);
                humanTurn = false;
                // cout << gridX << ", " << gridY << endl;
            }
        } else {
            cout << "Computer Turn" << endl;
            Decision dec = computerPlayer.makingDecision();

            if (dec.piece != Piece::na && game.checkValidMove(dec.pos.x, dec.pos.y)) {
                dec.pos.x = (dec.pos.x + 1) * game.getCellSize();
                dec.pos.y = (dec.pos.y + 1) * game.getCellSize();
                game.setPlayerMove(dec.pos, dec.piece);
                humanTurn = true;
            }
            // Decision dec = computerPlayer.makingDecision();
            
            // if (dec.piece != Piece::na && game.checkValidMove(dec.pos.x, dec.pos.y)) {
            //     // humanPlayer.setHasNextTurn(true);
            //     // computerPlayer.setHasNextTurn(false);
            //     dec.pos.x *= game.getCellSize();
            //     dec.pos.y *= game.getCellSize();
            //     game.setPlayerMove(dec.pos, dec.piece);
            // }
        }

        BeginDrawing();
        ClearBackground(Constants::BG_COLOR);
        game.drawCurrentPanel();
        game.drawLogoAndWords(humanPlayer.getObjective());
        cout << GetMousePosition().x << ", " << GetMousePosition().y << endl;
        // game.setPlayerMove(GetMousePosition(), Piece::na);
        // cout << game.checkOrderWin() << endl;
        // game.checkOrderWin();
        EndDrawing();
        game.printBoard();
    }

    CloseWindow();
    
    return 0;
}
