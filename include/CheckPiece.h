#ifndef CHECKPIECE_H
#define CHECKPIECE_H

#include <raylib.h>

class CheckPiece {
private:
    Vector2 position = {5, 6};
    Texture2D texture;

public:
    CheckPiece();
    void draw();
    ~CheckPiece();
};

#endif
