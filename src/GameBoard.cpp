#include "../include/GameBoard.h"
#include "../include/PieceType.h"
#include "../include/Constants.h"
#include "./GameManage/Cell.cpp"
#include <cstdlib>
#include <ctime>

using namespace std;

std::vector<std::vector<Piece>> GameBoard::GAME_BOARD;

GameBoard::GameBoard(int size, int windHeight): 
    CHAOS_WIN(false),
    ORDER_WIN(false),
    RESIGNATION(false),
    boardSize(size + 2)
{
    cellSize = windHeight / boardSize;
    // Initialize board state
    for (int row = 0; row < size; row++) {
        vector<Piece> temp;
        for (int col = 0 ; col < size; col++) {
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

void GameBoard::drawCurrentBoard() {
    srand(time(0));
    cout << random << endl;
    for (int row = 0; row < boardSize; row++) {
        for (int col = 0; col < boardSize; col++) {
            int random = rand();
            Cell cell = Cell(row * cellSize, col* cellSize, random);
            cell.drawCell(cellSize);
        }
    }
}