#include "../include/GameBoard.h"
#include "../include/PieceType.h"
#include "../include/Constants.h"
#include "../include/Cell.h"
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
    cellSize = windHeight / gamePanel;
    
    Image check = LoadImage("./assets/textures/checkImg.png");
    ImageResize(&check, cellSize-15, cellSize-15);
    checkTexture = LoadTextureFromImage(check);
    UnloadImage(check);

    Image cross = LoadImage("./assets/textures/crossImg.png");
    ImageResize(&cross, cellSize-15, cellSize-15);
    crossTexture = LoadTextureFromImage(cross);
    UnloadImage(cross);

    if (checkTexture.id == 0) {
        std::cerr << "Failed to load check texture!" << std::endl;
    }
    if (crossTexture.id == 0) {
        std::cerr << "Failed to load cross texture!" << std::endl;
    }
    
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
    cout << endl;
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
                // DrawTexture(checkTexture, row, col, WHITE);
                // Vector2 center = {(row * cellSize) + (cellSize/2), (col * cellSize) + (cellSize/2)};
                cell.drawPiece(GAME_BOARD.at(col - 1).at(row - 1), checkTexture, crossTexture);
            }
        }
    }
}

void GameBoard::setPlayerMove(Vector2 mousePos, Piece piece) {
    int row_idx = (mousePos.x / cellSize);
    int col_idx = (mousePos.y / cellSize);
    if (row_idx == 0 || col_idx == 0 || row_idx > boardSize || col_idx > boardSize) {
        row_idx = -1;
        col_idx = -1;
    } else {
        row_idx -= 1;
        col_idx -= 1;
    }

    if (row_idx != -1 && col_idx != -1) {
        GAME_BOARD[col_idx][row_idx] = piece;
    }
}

void GameBoard::printVectorValue(vector<Piece> vec) {
    cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            cout << static_cast<int>(vec.at(i)) << "]";
            break;    
        }
        cout << static_cast<int>(vec.at(i)) << ", ";
    }

    cout << checkVecForAligned(vec) << endl;;
}

bool GameBoard::checkVecForAligned(vector<Piece> vec, int max) {
    int count = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec.at(i) == vec.at(i+1) && vec.at(i) != Piece::na) {
            count++;
            if (count >= max) {
                return true;
            }
        }
        else {
            count = 0;
        }
    }

    return false;
}

bool GameBoard::getAndCheckDiagonal(int rowStart, int rowEnd, int col, int dx, int dy, int max) {
    // Vector2 initalPos = {col, rowStart};
    int vecSize = 4;
    int step = (rowStart <= rowEnd) ? 1 : -1;

    // printVectorValue(vec);
    for (int row = rowStart; 
        (step > 0) ? (row <= rowEnd) : (row >= rowEnd); 
        row += step) {
        vector<Piece> vec;
        for (int i = 0 ; i < vecSize ;i++) {
            int checkRow = row + (dy * i);
            int checkCol = col + (dx * i);
            
            if (checkRow >= 0 && checkRow < boardSize && 
                checkCol >= 0 && checkCol < boardSize) {
                vec.push_back(GAME_BOARD[checkRow][checkCol]);
            } else {
                // Skip this diagonal if it goes out of bounds
                break;
            }
        }
        if (vec.empty()) {
            cout << "empty" << endl;
        }
        // printVectorValue(vec);
        if (checkVecForAligned(vec)) {
            return true;
        }
        vecSize++;
    }

    return false;
}

bool GameBoard::checkOrderWin(int max) {
    // Check the rows
    for (int row = 0; row < boardSize; row++) {
        if (checkVecForAligned(GAME_BOARD[row], max)) {
            return true;
        }
    }

    // Check the cols
    int row = 0;
    while (row != boardSize) {
        vector<Piece> vec;
        for (int col = 0 ; col < boardSize; col++) {
            vec.push_back(GAME_BOARD[col][row]);
        }
        // printVectorValue(vec);

        if (checkVecForAligned(vec, max)) {
            return true;
        }
        row++;
    }

    // Check Diags
    if (getAndCheckDiagonal(3, 9, 0, +1, -1, max) || getAndCheckDiagonal(6, 1, 9, -1, +1, max) 
        || getAndCheckDiagonal(6, 0, 0, 1, 1, max) || getAndCheckDiagonal(3, 8, 9, -1, -1, max)) {
        return true;
    }
    
    
    return false;
}

bool GameBoard::checkChaosWin() {
    for (vector<Piece> vec : GAME_BOARD) {
        for (Piece piece : vec) {
            if (piece == Piece::na) {
                return false;
            }
        }
    }
    
    return !checkOrderWin();
}

bool GameBoard::checkGameOver() {
    if (checkChaosWin()) {
        cout << "GGs, Chaos Wins!" << endl;
        return true;
    } else if (checkOrderWin())
    {
        cout << "GGs, Order Wins" << endl;
        return true;
    } else if (IsKeyPressed(KEY_Q)) {
        cout << "You Resigned" << endl;
        return true;
    }

    return false;
}

bool GameBoard::checkValidMove(int x, int y) {
    if (x < 0 || y < 0 || x >= boardSize || y >= boardSize) {
        // cout << "NOT VALID" << x << y;
        return false;
    }
    return GAME_BOARD[y][x] == Piece::na;
}

int GameBoard::getCellSize() {
    return cellSize;
}

vector<vector<Piece>>& GameBoard::getGameBoard() {
    return GAME_BOARD;
};

bool GameBoard::testOrderWin(vector<vector<Piece>>& testBoard, int max) {
    // Check the rows
    for (int row = 0; row < boardSize; row++) {
        if (checkVecForAligned(testBoard[row], max)) {
            return true;
        }
    }

    // Check the cols
    int row = 0;
    while (row != boardSize) {
        vector<Piece> vec;
        for (int col = 0 ; col < boardSize; col++) {
            vec.push_back(testBoard[col][row]);
        }
        // printVectorValue(vec);

        if (checkVecForAligned(vec, max)) {
            return true;
        }
        row++;
    }

    // Check Diags
    if (testGetAndCheckDiagonal(testBoard,3, 9, 0, +1, -1, max) || testGetAndCheckDiagonal(testBoard, 6, 1, 9, -1, +1, max) 
        || testGetAndCheckDiagonal(testBoard,6, 0, 0, 1, 1, max) || testGetAndCheckDiagonal(testBoard, 3, 8, 9, -1, -1, max)) {
        return true;
    }
    
    return false;
}

bool GameBoard::testGetAndCheckDiagonal(vector<vector<Piece>>& testBoard, 
                            int rowStart, int rowEnd, int col, 
                            int dx, int dy, int max = 3) 
{
    // Vector2 initalPos = {col, rowStart};
    int vecSize = 4;
    int step = (rowStart <= rowEnd) ? 1 : -1;

    // printVectorValue(vec);
    for (int row = rowStart; 
        (step > 0) ? (row <= rowEnd) : (row >= rowEnd); 
        row += step) {
        vector<Piece> vec;
        for (int i = 0 ; i < vecSize ;i++) {
            int checkRow = row + (dy * i);
            int checkCol = col + (dx * i);
            
            if (checkRow >= 0 && checkRow < boardSize && 
                checkCol >= 0 && checkCol < boardSize) {
                vec.push_back(testBoard[checkRow][checkCol]);
            } else {
                // Skip this diagonal if it goes out of bounds
                break;
            }
        }
        if (vec.empty()) {
            cout << "empty" << endl;
        }
        // printVectorValue(vec);
        if (checkVecForAligned(vec, max)) {
            return true;
        }
        vecSize++;
    }

    return false;
}

GameBoard::~GameBoard() {
    UnloadTexture(checkTexture);
    UnloadTexture(crossTexture);
}

