#include "../include/GameBoard.h"
#include "../include/PieceType.h"
#include "../include/Constants.h"
#include "./GameManage/Cell.cpp"
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

std::vector<std::vector<Piece>> GameBoard::GAME_BOARD;

GameBoard::GameBoard(int size, int windHeight): 
    CHAOS_WIN(false),
    ORDER_WIN(false),
    RESIGNATION(false),
    gamePanel(size + 2),
    boardSize(size)
{

    Image check = LoadImage("./assets/textures/checkImg.png");
    ImageResize(&check, cellSize, cellSize);
    checkTexture = LoadTextureFromImage(check);
    UnloadImage(check);

    Image cross = LoadImage("./assets/textures/crossImg.png");
    ImageResize(&cross, cellSize, cellSize);
    crossTexture = LoadTextureFromImage(cross);
    UnloadImage(cross);

    cellSize = windHeight / gamePanel;
    for (int row = 0; row < boardSize; row++) {
        vector<Piece> temp;
        for (int col = 0 ; col < boardSize; col++) {
            temp.push_back(Piece::na);
        }
        GAME_BOARD.push_back(temp);
    }
}

void GameBoard::printBoard() {
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            if (col == boardSize - 1) {
                cout << static_cast<int>(GAME_BOARD.at(row).at(col));
            } else {
                cout << static_cast<int>(GAME_BOARD.at(row).at(col)) << " ";
            }
        }
        cout << endl;
    }
}

void GameBoard::drawCurrentPanel() {
    srand(time(0));
    for (int row = 0; row < gamePanel; row++) {
        for (int col = 0; col < gamePanel; col++) {
            int random = rand();
            Cell cell = Cell(row, col, cellSize, random);
            cell.drawCell();

            std::string coord_str = "( " + std::to_string(row) + ", " + std::to_string(col) + " )";
            
            // cout << "( " << row << ", " << col << ")" << endl;
            if (row != 0 && col != 0 && row != 11 && col != 11) {
                cell.drawPiece(GAME_BOARD.at(col - 1).at(row - 1), checkTexture, crossTexture);
                // DrawText(coord_str.c_str(), row * cellSize, col * cellSize, 15, WHITE);
            }
        }
    }
}

void GameBoard::setPlayerMove(Vector2 mousePos, Piece p) {
    int row_idx = (mousePos.x / cellSize);
    int col_idx = (mousePos.y / cellSize);
    if (row_idx == 0 || col_idx == 0 || row_idx > boardSize || col_idx > boardSize) {
        row_idx = -1;
        col_idx = -1;
    } else {
        row_idx -= 1;
        col_idx -= 1;
    }

    if (row_idx != -1 && col_idx != -1 && IsMouseButtonDown(0)) {
        GAME_BOARD[col_idx][row_idx] = p;
    }
}

GameBoard::~GameBoard() {
    UnloadTexture(checkTexture);
    UnloadTexture(crossTexture);
}

