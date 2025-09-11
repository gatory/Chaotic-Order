#include <raylib.h>
#include <iostream>
#include "../include/constants.h"
#include "../include/CheckPiece.h"

using namespace std;

int main() {
    
    cout << "Starting the game..." << endl;
    InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_WIDTH, "Chaotic-Order");
    SetTargetFPS(60);

    CheckPiece check = CheckPiece();

    while (!WindowShouldClose()) {
        BeginDrawing();
        check.draw();
        ClearBackground(Constants::BG_COLOR);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
