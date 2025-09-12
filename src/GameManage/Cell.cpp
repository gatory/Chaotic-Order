#include "../../include/Cell.h"

Cell::Cell(float x, float y, int cellSize, int random) {
    vec = {x * cellSize, y * cellSize};
    size = cellSize;

    if (x == 0 || y == 0 || x == 11 || y == 11 ) {
        ratio = 1;
        color = Constants::GRID_BORDER_COLOR;
    } else if (random % 2 == 0) {
        ratio = 0.9;
        color = Constants::CELL_COLOR1;
    } else {
        ratio = 0.9;
        color = Constants::CELL_COLOR2;
    }
}

void Cell::drawCell() {
    DrawRectangle(vec.x, vec.y, size * ratio, size * ratio, color);
}

void Cell::drawPiece(Piece piece, Texture check, Texture cross) {
    switch (piece)
    {
    case Piece::o:
        DrawText("O", vec.x, vec.y, size, WHITE);
        // DrawTexture(check, vec.x, vec.y, WHITE);
        break;
    case Piece::x:
        DrawText("X", vec.x, vec.y, size, WHITE);
        // DrawTexture(cross, vec.x, vec.y, WHITE);
        break;
    
    default:
        break;
    }
}

Cell::~Cell(){}