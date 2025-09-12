#include "../../include/Cell.h"

Cell::Cell(float x, float y, int cellSize, int random) {
    vec = {x * cellSize, y * cellSize};
    size = cellSize;
    piece = Piece::na;
    
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

Piece Cell::getPiece() {
    return piece;
}

Cell::~Cell(){}