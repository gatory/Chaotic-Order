#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <raylib.h>
#include "Constants.h"

class Cell
{
private:
    Vector2 vec;
    Color color;
    int cellSize;

public:
    // Normal cell
    Cell(float x, float y, int randm);

    void drawCell(int cellSize);

    ~Cell();
};

#endif
