#include "../include/CheckPiece.h"
#include "../include/Constants.h"

CheckPiece::CheckPiece() {
    Image image = LoadImage("./assets/textures/checkImg.png");
    ImageResize(&image, Constants::CELL_SIZE, Constants::CELL_SIZE);
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

void CheckPiece::draw() {
    DrawTexture(texture, position.x * Constants::CELL_SIZE, position.x * Constants::CELL_SIZE, WHITE);
}

CheckPiece::~CheckPiece() {
    UnloadTexture(texture);
}