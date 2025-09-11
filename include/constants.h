#pragma once
#include <raylib.h>

class Constants {
public:    
    const static int OFFSET_MOUSE = 15;

    const static Color BG_COLOR;
    const static Color CELL_COLOR1;
    const static Color CELL_COLOR2;
    const static Color GRID_BORDER_COLOR;
    static int gridSize;

    static Vector2 GameBoardCoords;

};