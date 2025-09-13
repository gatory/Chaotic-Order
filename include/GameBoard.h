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
    int gamePanel;

    Texture2D checkTexture;
    Texture2D crossTexture;
    static vector<vector<Piece>> GAME_BOARD;
    

public:
    GameBoard(int size, int windowHeight);

    void printBoard();

    void drawCurrentPanel();

    bool checkChaosWin();

    bool checkOrderWin();

    bool checkGameOver();

    bool checkValidMove(int x, int y);

    bool getAndCheckDiagonal(int rowStart, int rowEnd, int col, int dx, int dy);

    bool checkVecForAligned(vector <Piece> vec);

    void printVectorValue(vector<Piece> vec);

    void setPlayerMove(Vector2 mousePos, Piece piece);

    int getCellSize();

    ~GameBoard();
};

#endif
