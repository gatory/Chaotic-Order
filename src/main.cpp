#include <raylib.h>
#include <iostream>

using namespace std;

int main() {
    const int screenWidth = 750;
    const int screenHeight = 750;
    
    cout << "Starting the game..." << endl;
    InitWindow(screenWidth, screenHeight, "Chaotic-Order");
    SetTargetFPS(60);

    CloseWindow();
    
    
}

// int main()
// {
//     // Initialization
//     const int screenWidth = 800;
//     const int screenHeight = 450;

//     InitWindow(screenWidth, screenHeight, "Chaotic-Order");
//     SetTargetFPS(60);

//     // Main game loop
//     while (!WindowShouldClose())
//     {
//         // Update
//         // TODO: Add your game logic here

//         // Draw
//         BeginDrawing();
//         ClearBackground(RAYWHITE);
//         DrawFPS(10, 10);
//         EndDrawing();
//     }

//     // De-Initialization
//     CloseWindow();
//     return 0;
// }
