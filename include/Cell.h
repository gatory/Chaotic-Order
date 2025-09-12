#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <raylib.h>
#include "Constants.h"
#include "PieceType.h"

class Cell
{
private:
    Vector2 vec;
    Color color;
    int size;
    float ratio;
    Piece piece;

public:

    Cell(float x, float y, int cellSize, int random);

    void drawCell();

    Piece getPiece();

    ~Cell();
};

#endif
