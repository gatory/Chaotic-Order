#include "../../include/Cell.h"

Cell::Cell(float x, float y, int random){
    vec = {x, y};
    if (x == 0 || y == 0 || x == 720 * (11/12) || y == 720 * (11/12)) {
        color = Constants::GRID_BORDER_COLOR;
    }
    else if (random % 2 == 0) {
        color = Constants::CELL_COLOR1;
    } else {
        color = Constants::CELL_COLOR2;
    }
}


void Cell:: drawCell(int cellSize) {
    float ratio = 0.9;
    DrawRectangle(vec.x, vec.y, cellSize * ratio, cellSize * ratio, color);

}

Cell::~Cell(){}