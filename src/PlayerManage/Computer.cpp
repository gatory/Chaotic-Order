#include "../../include/Computer.h"
#include "../../include/GameBoard.h"
#include <random>
#include <cstdlib>
#include <ctime>

Computer::Computer(ObjectiveType objective, GameBoard &game): 
    Player(objective), game(game) {}

bool Computer::wouldCreateWinningSequence(int row, int col, Piece piece, int targetAlign) {
    vector<vector<Piece>> GAME_BOARD = game.getGameBoard();

    if (GAME_BOARD[row][col] != Piece::na) {
        return false;
    }
    
    GAME_BOARD[row][col] = piece;
    
    bool isWinning = false;
    int count = 1;
    
    // Check horizontal
    // Check left & right
    for (int c = col - 1; c >= 0 && GAME_BOARD[row][c] == piece; c--) {
        count++;
    }
    for (int c = col + 1; c < GAME_BOARD.size() && GAME_BOARD[row][c] == piece; c++) {
        count++;
    }
    if (count >= targetAlign) isWinning = true;
    
    // Check vertical
    // Check up & down
    count = 1;
    for (int r = row - 1; r >= 0 && GAME_BOARD[r][col] == piece; r--) {
        count++;
    }
    for (int r = row + 1; r < GAME_BOARD.size() && GAME_BOARD[r][col] == piece; r++) {
        count++;
    }
    if (count >= targetAlign) isWinning = true;
    
    // Check diagonal (up-left to down-right)
    // Check up-left and down-right
    count = 1;
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0 && GAME_BOARD[r][c] == piece; r--, c--) {
        count++;
    }
    for (int r = row + 1, c = col + 1; r < GAME_BOARD.size() && c < GAME_BOARD.size() && GAME_BOARD[r][c] == piece; r++, c++) {
        count++;
    }
    if (count >= targetAlign) isWinning = true;
    
    // Check diagonal (up-right to down-left)
    // Check up-right and down-left
    count = 1;
    for (int r = row - 1, c = col + 1; r >= 0 && c < GAME_BOARD.size() && GAME_BOARD[r][c] == piece; r--, c++) {
        count++;
    }
    for (int r = row + 1, c = col - 1; r < GAME_BOARD.size() && c >= 0 && GAME_BOARD[r][c] == piece; r++, c--) {
        count++;
    }
    if (count >= targetAlign) isWinning = true;
    
    GAME_BOARD[row][col] = Piece::na;
    
    return isWinning;
}

Decision Computer::considerObjective(ObjectiveType objective, Decision decision) {
    if (objective == ObjectiveType::CHAOS) {
        decision.piece = decision.piece == Piece::o ? Piece::x : Piece::o;
    }

    return decision;
}

struct Decision Computer::makingDecision() {
    Decision decision;
        
    // Checks for immediate win
    for (int row = 0; row < game.getGameBoard().size(); row++) {
        for (int col = 0; col < game.getGameBoard()[0].size(); col++) {
            if (game.getGameBoard()[row][col] == Piece::na) {
                // Test O piece
                if (wouldCreateWinningSequence(row, col, Piece::o, 5)) {
                    decision.pos = {(float)col, (float)row};
                    decision.piece = Piece::o;
                    return considerObjective(objective, decision);
                }
                
                // Test X piece
                if (wouldCreateWinningSequence(row, col, Piece::x, 5)) {
                    decision.pos = {(float)col, (float)row};
                    decision.piece = Piece::x;
                    return considerObjective(objective, decision);
                }
            }
        }
    }

    // int smallestPotentialCountSoFar = -1;
    // Vector2 bestPos;
    // for (int row = 0; row < game.getGameBoard().size(); row++) {
    //     for (int col = 0; col < game.getGameBoard()[0].size(); col++) {
    //         if (game.getGameBoard()[row][col] == Piece::na) {
    //             // Test O piece
    //             int oSmallestPotential = getPotential(row, col, Piece::o, 5);
    //             int xSmallestPotential = getPotential(row, col, Piece::x, 5);
    //             cout << "[" << col << ", " << row << "]" << endl;
    //             cout << "O: " << oSmallestPotential  << " X: " << xSmallestPotential << endl;

    //             // if (oSmallestPotential != -1 ) {
    //             //     decision.pos = {(float)col, (float)row};
    //             //     decision.piece = Piece::o;
    //             //     return considerObjective(objective, decision);
    //             // }
                
    //             // // Test X piece
    //             // if (wouldCreateWinningSequence(row, col, Piece::x, 5)) {
    //             //     decision.pos = {(float)col, (float)row};
    //             //     decision.piece = Piece::x;
    //             //     return considerObjective(objective, decision);
    //             // }
    //         }
    //     }
    // }

    // If no winning move, make random valid move
    vector<pair<int, int>> validMoves;
    for (int row = 0; row < game.getGameBoard().size(); row++) {
        for (int col = 0; col < game.getGameBoard()[0].size(); col++) {
            if (game.getGameBoard()[row][col] == Piece::na) {
                validMoves.push_back({row, col});
            }
        }
    }
    
    if (!validMoves.empty()) {
        srand(time(0));
        int randomIndex = rand() % validMoves.size();
        int randRow = validMoves[randomIndex].first;
        int randCol = validMoves[randomIndex].second;
        int randomPiece = rand() % 2;
        
        decision.piece = (randomPiece == 0) ? Piece::o : Piece::x;
        decision.pos = {(float)randCol, (float)randRow};
    }

    return considerObjective(objective, decision);
}


int Computer::getPotential(int row, int col, Piece piece, int targetAlign) {
    vector<vector<Piece>> GAME_BOARD = game.getGameBoard();

    if (GAME_BOARD[row][col] != Piece::na) {
        return -1;
    }
    
    // bool isWinning = false;
    // int count = 1;
    int smallestPotentialCount = -1;

    int potentialCount = 1;
    // Check horizontal
    // Check left & right
    for (int c = col - 1; c >= 0; c--) {
        if (GAME_BOARD[row][c] == Piece::na) {
            potentialCount++;
        } else if (GAME_BOARD[row][c] != piece) {
            break;
        }
    }
    for (int c = col + 1; c < GAME_BOARD.size(); c++) {
        if (GAME_BOARD[row][c] == Piece::na) {
            potentialCount++;
        } else if (GAME_BOARD[row][c] != piece) {
            break;
        }
    }
    if (smallestPotentialCount == -1 || potentialCount < smallestPotentialCount)  {
        smallestPotentialCount = potentialCount;
    }
    
    // // Check vertical
    // // Check up & down
    // potentialCount = 1;
    // for (int r = row - 1; r >= 0; r--) {
    //     if (GAME_BOARD[r][col] == Piece::na) {
    //         potentialCount++;
    //     } else if (GAME_BOARD[r][col] != piece) {
    //         break;
    //     }
    // }
    // for (int r = row + 1; r < GAME_BOARD.size(); r++) {
    //     if (GAME_BOARD[r][col] == Piece::na) {
    //         potentialCount++;
    //     } else if (GAME_BOARD[r][col] != piece) {
    //         break;
    //     }
    // }
    // if (smallestPotentialCount == -1 || potentialCount < smallestPotentialCount)  {
    //     smallestPotentialCount = potentialCount;
    // }

    // // Check diagonal (up-left to down-right)
    // // Check up-left and down-right
    // potentialCount = 1;
    // for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; r--, c--) {
    //     if (GAME_BOARD[r][c] == Piece::na) {
    //         potentialCount++;
    //     } else if (GAME_BOARD[r][c] != piece) {
    //         break;
    //     }
    // }
    // for (int r = row + 1, c = col + 1; r < GAME_BOARD.size() && c < GAME_BOARD.size(); r++, c++) {
    //     if (GAME_BOARD[r][c] == Piece::na) {
    //         potentialCount++;
    //     } else if (GAME_BOARD[r][c] != piece) {
    //         break;
    //     }
    // }
    // if (smallestPotentialCount == -1 || potentialCount < smallestPotentialCount)  {
    //     smallestPotentialCount = potentialCount;
    // }

    
    // // Check diagonal (up-right to down-left)
    // // Check up-right and down-left
    // potentialCount = 1;
    // for (int r = row - 1, c = col + 1; r >= 0 && c < GAME_BOARD.size(); r--, c++) {
    //     if (GAME_BOARD[r][c] == Piece::na) {
    //         potentialCount++;
    //     } else if (GAME_BOARD[r][c] != piece) {
    //         break;
    //     }
    // }
    // for (int r = row + 1, c = col - 1; r < GAME_BOARD.size() && c >= 0; r++, c--) {
    //     if (GAME_BOARD[r][c] == Piece::na) {
    //         potentialCount++;
    //     } else if (GAME_BOARD[r][c] != piece) {
    //         break;
    //     }
    // }

    // if (smallestPotentialCount == -1 || potentialCount < smallestPotentialCount)  {
    //     smallestPotentialCount = potentialCount;
    // }
    
    return smallestPotentialCount;
}