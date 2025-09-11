#pragma once
#include <raylib.h>

class Constants {
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    const static int CELL_SIZE = 30;
    
    const static Color BG_COLOR;
    const static Color CELL_COLOR;
    const static Color GRID_BORDER_COLOR;
    static int gridSize;
};