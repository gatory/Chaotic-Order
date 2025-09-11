#include <raylib.h>
#pragma once

class Constants
{
public:
    const static int SCREEN_WIDTH = 800;
    const static int SCREEN_HEIGHT = 600;
    const static Color BG_COLOR;
    const static Color CELL_COLOR;
    const static int CELL_SIZE = 30;
    static int gridSize;
};

const Color Constants::BG_COLOR = {173, 204, 96, 255};
const Color Constants::CELL_COLOR = {255, 219, 172, 255};
int Constants::gridSize = 10;
