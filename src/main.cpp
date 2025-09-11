#include <raylib.h>
#include <iostream>
#include "../include/constants.h"

using namespace std;

int main() {
    
    cout << "Starting the game..." << endl;
    InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_WIDTH, "Chaotic-Order");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(Constants::BG_COLOR);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
