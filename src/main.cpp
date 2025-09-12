#include <raylib.h>
#include <iostream>
#include "../include/GameBoard.h"
#include "../include/Constants.h"
#include "../include/Cell.h"
#include "../include/PieceType.h"
// #include "../include/CheckPiece.h"

using namespace std;

int main() {
    
    const static int SCREEN_WIDTH = 1000;
    const static int SCREEN_HEIGHT = 720;

    
    cout << "Starting the game..." << endl;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chaotic-Order");
    SetTargetFPS(60);
    
    GameBoard game = GameBoard(10, SCREEN_HEIGHT);    

    while (!WindowShouldClose()) {
        // if (game.checkGameOver()) {
        //     break;
        // }

        BeginDrawing();
        ClearBackground(Constants::BG_COLOR);
        game.drawCurrentPanel();
        game.setPlayerMove(GetMousePosition(), Piece::na);
        if (game.checkGameOver()) {
            break;
        }
        // cout << game.checkOrderWin() << endl;
        // game.checkOrderWin();
        game.printBoard();
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
