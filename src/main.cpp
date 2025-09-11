#include <raylib.h>
#include <iostream>
#include "../include/GameBoard.h"
#include "../include/Constants.h"
// #include "../include/CheckPiece.h"

using namespace std;

int main() {
    
    const static int SCREEN_WIDTH = 1000;
    const static int SCREEN_HEIGHT = 720;

    GameBoard game = GameBoard(10, SCREEN_HEIGHT);
    
    cout << "Starting the game..." << endl;
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chaotic-Order");
    SetTargetFPS(60);


    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Constants::BG_COLOR);
        game.drawCurrentBoard();
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
