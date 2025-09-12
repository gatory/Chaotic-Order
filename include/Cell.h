#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <raylib.h>
#include <vector>
#include "Constants.h"
#include "PieceType.h"

class Cell
{
private:
    Vector2 vec;
    Color color;
    int size;
    float ratio;

public:

    Cell(float x, float y, int cellSize, int random);

    void drawCell();

    void drawPiece(Piece piece, Texture check, Texture cross);

    ~Cell();
};

#endif
