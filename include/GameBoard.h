#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <raylib.h>
#include <vector>
#include "PieceType.h"

using namespace std;

class GameBoard {
private:
    bool CHAOS_WIN;
    bool ORDER_WIN;
    bool RESIGNATION;
    int boardSize;
    int cellSize;
    static vector<vector<Piece>> GAME_BOARD;
    

public:
    GameBoard(int size, int windowWidth);

    void printBoard();

    void drawCurrentBoard();

    // void checkChaosWin();

    // void checkOrderWin();

    // void checkResignation();

    // void checkValidMove();

    // void setPlayerMove();

};

#endif
