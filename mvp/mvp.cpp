#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class GameBoard
{
    vector<vector<string>> BOARD;
    int BOARD_SIZE;
    bool CHOAS_WIN = false;
    bool ORDER_WIN = false;
    bool RESIGNATION = false;

public:
    // initlaize board1
    GameBoard(int size) : BOARD_SIZE(size)
    {
        for (int row = 0; row < size; row++)
        {
            vector<string> temp;
            for (int col = 0; col < size; col++)
            {
                temp.push_back(".");
            }
            BOARD.push_back(temp);
        }
    }

    void print_current_board()
    {
        // print top numbers
        for (int i = 1; i < BOARD_SIZE + 1; i++)
        {
            if (i == 1)
            {
                cout << "   " << i << " ";
            }
            else if (i == BOARD_SIZE)
            {
                cout << i;
            }
            else
            {
                cout << i << " ";
            }
        }
        cout << endl;
        // print the rows
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            char ch = 'a' + row;
            cout << " " << ch << " ";
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (col == BOARD_SIZE - 1)
                {
                    cout << BOARD.at(row).at(col);
                }
                else
                {
                    cout << BOARD.at(row).at(col) << " ";
                }
            }
            cout << endl;
        }
    }

    bool check_CHAOS_win()
    {
        if (CHOAS_WIN != true && ORDER_WIN != true)
        {
            int counter = 0;
            for (vector<string> row : BOARD)
            {
                for (string SPACE : row)
                {
                    if (SPACE == ".")
                    {
                        counter++;
                    }
                }
            }
            if (counter == 0)
            {
                CHOAS_WIN = true;
                return true;
            }
        }
        return false;
    }

    bool check_ORDER_win()
    {
        // check row for Os
        // reusing counter var
        int counter = 0;
        for (vector<string> row : BOARD)
        {
            for (string SPACE : row)
            {
                if (SPACE != "o")
                {
                    counter = 0;
                }
                else
                {
                    counter++;
                }

                if (counter == 5)
                {
                    ORDER_WIN = true;
                    return true;
                }
            }
        }
        counter = 0;
        // check row for Xs
        for (vector<string> row : BOARD)
        {
            for (string SPACE : row)
            {
                if (SPACE != "x")
                {
                    counter = 0;
                }
                else
                {
                    counter++;
                }
                if (counter == 5)
                {
                    ORDER_WIN = true;
                    return true;
                }
            }
        }
        counter = 0;

        // check col for Os
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            for (int row = 0; row < BOARD_SIZE; row++)
            {
                if (BOARD.at(row).at(col) != "o")
                {
                    counter = 0;
                }
                else
                {
                    counter++;
                }

                if (counter == 5)
                {
                    ORDER_WIN = true;
                    return true;
                }
            }
        }
        counter = 0;
        // check col for Xs
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            for (int row = 0; row < BOARD_SIZE; row++)
            {
                if (BOARD.at(row).at(col) != "x")
                {
                    counter = 0;
                }
                else
                {
                    counter++;
                }

                if (counter == 5)
                {
                    ORDER_WIN = true;
                    return true;
                }
            }
        }

        // check diagonal ascending for Os
        counter = 0;
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (BOARD.at(row).at(col) == "o")
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row >= 0 && new_col < BOARD_SIZE)
                    {
                        if (BOARD.at(new_row).at(new_col) != "o")
                        {
                            break;
                        }
                        else
                        {
                            counter++;
                        }

                        if (counter == 5)
                        {
                            ORDER_WIN = true;
                            return true;
                        }

                        new_row--;
                        new_col++;
                    }
                    counter = 0;
                }
            }
        }
        counter = 0;
        // check descending for Os
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (BOARD.at(row).at(col) == "o")
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row < BOARD_SIZE && new_col < BOARD_SIZE)
                    {
                        if (BOARD.at(new_row).at(new_col) != "o")
                        {
                            break;
                        }
                        else
                        {
                            counter++;
                        }

                        if (counter == 5)
                        {
                            ORDER_WIN = true;
                            return true;
                        }

                        new_row++;
                        new_col++;
                    }
                    counter = 0;
                }
            }
        }

        // check diagonal ascending for Xs
        counter = 0;
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (BOARD.at(row).at(col) == "x")
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row >= 0 && new_col < BOARD_SIZE)
                    {
                        if (BOARD.at(new_row).at(new_col) != "x")
                        {
                            break;
                        }
                        else
                        {
                            counter++;
                        }

                        if (counter == 5)
                        {
                            ORDER_WIN = true;
                            return true;
                        }

                        new_row--;
                        new_col++;
                    }
                    counter = 0;
                }
            }
        }
        counter = 0;
        // check descending for Os
        for (int row = 0; row < BOARD_SIZE; row++)
        {
            for (int col = 0; col < BOARD_SIZE; col++)
            {
                if (BOARD.at(row).at(col) == "x")
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row < BOARD_SIZE && new_col < BOARD_SIZE)
                    {
                        if (BOARD.at(new_row).at(new_col) != "x")
                        {
                            break;
                        }
                        else
                        {
                            counter++;
                        }

                        if (counter == 5)
                        {
                            ORDER_WIN = true;
                            return true;
                        }

                        new_row++;
                        new_col++;
                    }
                    counter = 0;
                }
            }
        }
        return false;
    }

    bool check_valid_move(const int &row, int col, string value)
    {
        if (row < 0 || row >= BOARD_SIZE)
        {
            return false;
        }
        if (col < 0 || col >= BOARD_SIZE)
        {
            return false;
        }
        if (!(value == "o" || value == "x"))
        {
            return false;
        }
        if (BOARD.at(row).at(col) != ".")
        {
            return false;
        }
        return true;
    }

    bool check_valid_move(string player_input)
    {
        if (player_input == "-1")
        {
            RESIGNATION = true;
        }
        else if (player_input.size() != 3)
        {
            return false;
        }
        return true;
    }

    void set_player_move(int row, int col, string value)
    {
        BOARD.at(row).at(col) = value;
    }

    void make_user_move()
    {
        string PLAYER_MOVE;
        cout << "What would your move be? "
             << "(Format: (row)(col)(X or O) ex: a2x), (type -1 to resign)\n";
        cin >> PLAYER_MOVE;
        bool is_valid_move = check_valid_move(PLAYER_MOVE);

        if (!RESIGNATION && is_valid_move)
        {
            int row = PLAYER_MOVE.at(0) - 'a';
            int col = PLAYER_MOVE.at(1) - '1';
            string value;
            value += PLAYER_MOVE.at(2);
            is_valid_move = check_valid_move(row, col, value);

            while (!is_valid_move)
            {
                cout << endl;
                cout << "Invalid input! Please try again.\n";
                cout << endl;
                print_current_board();
                cout << "What would your move be? "
                     << "(Format: (row)(col)(X or O) ex: a2x), (type -1 to resign)\n";
                cin >> PLAYER_MOVE;
                is_valid_move = check_valid_move(PLAYER_MOVE);
                if (!RESIGNATION && is_valid_move)
                {
                    row = PLAYER_MOVE.at(0) - 'a';
                    col = PLAYER_MOVE.at(1) - '0' - 1;
                    value.clear();
                    value += PLAYER_MOVE.at(2);
                    is_valid_move = check_valid_move(row, col, value);
                }
            }
            if (!RESIGNATION)
            {
                set_player_move(row, col, value);
            }
        }
        else if (!RESIGNATION && !is_valid_move)
        {
            int row = 0;
            int col = 0;
            string value;
            while (!is_valid_move && !RESIGNATION)
            {
                cout << endl;
                cout << "Invalid input! Please try again.\n";
                cout << endl;
                print_current_board();
                cout << "What would your move be? "
                     << "(Format: (row)(col)(X or O) ex: a2x), (type -1 to resign)\n";
                cin >> PLAYER_MOVE;
                is_valid_move = check_valid_move(PLAYER_MOVE);
                if (!RESIGNATION && is_valid_move)
                {
                    row = PLAYER_MOVE.at(0) - 'a';
                    col = PLAYER_MOVE.at(1) - '0' - 1;
                    value.clear();
                    value += PLAYER_MOVE.at(2);
                    is_valid_move = check_valid_move(row, col, value);
                }
            }
            if (!RESIGNATION)
            {
                set_player_move(row, col, value);
            }
        }
    }

    bool check_valid_play_again_status(string input)
    {
        if (input != "yes" && input != "no" && input != "Yes" && input != "No")
        {
            return false;
        }
        return true;
    }

    bool get_resignation_status()
    {
        return RESIGNATION;
    }

    bool get_CHAOS_win_status()
    {
        return CHOAS_WIN;
    }

    bool get_ORDER_win_staus()
    {
        return ORDER_WIN;
    }

    vector<vector<string>> get_board()
    {
        return BOARD;
    }

    int get_board_size()
    {
        return BOARD_SIZE;
    }
};

struct Player
{
    string objective;
    bool go_first = false;
};

struct O_and_X_count
{
    int O = 0;
    int X = 0;
    int margin_space = 0;
    int start_idx = 0;
    string value;
};

class Computer
{
    string objective;
    bool go_first = false;

public:
    void set_random_idx(GameBoard &game)
    {
        int random_row = rand() % game.get_board_size();
        int random_col = rand() % game.get_board_size();
        int random_value = rand() % 2;
        string value;
        if (random_value == 0)
        {
            value = "o";
        }
        else
        {
            value = "x";
        }
        while (!game.check_valid_move(random_row, random_col, value))
        {
            random_row = rand() % game.get_board_size();
            random_col = rand() % game.get_board_size();
        }
        char ch = 'a' + random_row;
        cout << "Computer Move: Row (" << ch << ") "
             << "Col (" << random_col + 1 << ") "
             << "Value (" << value << ")";
        cout << endl;
        game.set_player_move(random_row, random_col, value);
    }

    void chaos_bot(GameBoard &game)
    {
        O_and_X_count counter;
        bool move_made = false;
        // ROW
        if (!move_made)
        {
            for (int row = 0; row < game.get_board_size(); row++)
            {
                for (int col = 0; col < game.get_board_size(); col++)
                {
                    string space = game.get_board().at(row).at(col);
                    if (space == "o")
                    {
                        counter.O++;
                        counter.X = 0;
                    }
                    else if (space == "x")
                    {
                        counter.X++;
                        counter.O = 0;
                    }
                    else if (space == "." && counter.O >= 3)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "x";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "x");
                        break;
                    }
                    else if (space == "." && counter.X >= 3)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "o";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "o");
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }

        // COLUM
        if (!move_made)
        {
            for (int col = 0; col < game.get_board_size(); col++)
            {
                for (int row = 0; row < game.get_board_size(); row++)
                {
                    string space = game.get_board().at(row).at(col);
                    if (space == "o")
                    {
                        counter.O++;
                        counter.X = 0;
                    }
                    else if (space == "x")
                    {
                        counter.X++;
                        counter.O = 0;
                    }
                    else if (space == "." && counter.O >= 2)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "x";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "x");
                        break;
                    }
                    else if (space == "." && counter.X >= 2)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "o";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "o");
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }
        if (!move_made)
        {
            // DIAGONAL ASCENDING
            for (int col = 0; col < game.get_board_size(); col++)
            {
                for (int row = 0; row < game.get_board_size(); row++)
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row >= 0 && new_col < game.get_board_size())
                    {
                        string space = game.get_board().at(new_row).at(new_col);
                        if (space == "o")
                        {
                            counter.O++;
                            counter.X = 0;
                        }
                        else if (space == "x")
                        {
                            counter.X++;
                            counter.O = 0;
                        }
                        else if (space == "." && counter.O >= 1)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "x";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "x");
                            break;
                        }
                        else if (space == "." && counter.X >= 1)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "o";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "o");
                            break;
                        }
                        new_row--;
                        new_col++;
                    }
                    if (move_made)
                    {
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }
        // DIAGONALL DESC
        if (!move_made)
        {
            for (int col = 0; col < game.get_board_size(); col++)
            {
                for (int row = 0; row < game.get_board_size(); row++)
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row < game.get_board_size() && new_col < game.get_board_size())
                    {
                        string space = game.get_board().at(new_row).at(new_col);
                        if (space == "o")
                        {
                            counter.O++;
                            counter.X = 0;
                        }
                        else if (space == "x")
                        {
                            counter.X++;
                            counter.O = 0;
                        }
                        else if (space == "." && counter.O >= 1)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "x";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "x");
                            break;
                        }
                        else if (space == "." && counter.X >= 1)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "o";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "o");
                            break;
                        }
                        new_row++;
                        new_col++;
                    }
                    if (move_made)
                    {
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }

        if (!move_made)
        {
            set_random_idx(game);
        }
    }

    void order_bot(GameBoard &game)
    {
        O_and_X_count counter;
        bool move_made = false;
        // ROW
        if (!move_made)
        {
            for (int row = 0; row < game.get_board_size(); row++)
            {
                for (int col = 0; col < game.get_board_size(); col++)
                {
                    string space = game.get_board().at(row).at(col);
                    if (space == "o")
                    {
                        counter.O++;
                        counter.X = 0;
                    }
                    else if (space == "x")
                    {
                        counter.X++;
                        counter.O = 0;
                    }
                    else if (space == "." && counter.O >= 3)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "o";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "o");
                        break;
                    }
                    else if (space == "." && counter.X >= 3)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "x";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "x");
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }

        // COLUM
        if (!move_made)
        {
            for (int col = 0; col < game.get_board_size(); col++)
            {
                for (int row = 0; row < game.get_board_size(); row++)
                {
                    string space = game.get_board().at(row).at(col);
                    if (space == "o")
                    {
                        counter.O++;
                        counter.X = 0;
                    }
                    else if (space == "x")
                    {
                        counter.X++;
                        counter.O = 0;
                    }
                    else if (space == "." && counter.O >= 3)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "o";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "o");
                        break;
                    }
                    else if (space == "." && counter.X >= 3)
                    {
                        move_made = true;

                        char ch = 'a' + row;
                        string value = "x";
                        cout << "Computer Move: Row (" << ch << ") "
                             << "Col (" << col + 1 << ") "
                             << "Value (" << value << ")";
                        cout << endl;

                        game.set_player_move(row, col, "x");
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }
        if (!move_made)
        {
            // DIAGONAL ASCENDING
            for (int col = 0; col < game.get_board_size(); col++)
            {
                for (int row = 0; row < game.get_board_size(); row++)
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row >= 0 && new_col < game.get_board_size())
                    {
                        string space = game.get_board().at(new_row).at(new_col);
                        if (space == "o")
                        {
                            counter.O++;
                            counter.X = 0;
                        }
                        else if (space == "x")
                        {
                            counter.X++;
                            counter.O = 0;
                        }
                        else if (space == "." && counter.O >= 2)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "o";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "o");
                            break;
                        }
                        else if (space == "." && counter.X >= 2)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "x";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "x");
                            break;
                        }
                        new_row--;
                        new_col++;
                    }
                    if (move_made)
                    {
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }
        // DIAGONALL DESC
        if (!move_made)
        {
            for (int col = 0; col < game.get_board_size(); col++)
            {
                for (int row = 0; row < game.get_board_size(); row++)
                {
                    int new_row = row;
                    int new_col = col;
                    while (new_row < game.get_board_size() && new_col < game.get_board_size())
                    {
                        string space = game.get_board().at(new_row).at(new_col);
                        if (space == "o")
                        {
                            counter.O++;
                            counter.X = 0;
                        }
                        else if (space == "x")
                        {
                            counter.X++;
                            counter.O = 0;
                        }
                        else if (space == "." && counter.O >= 2)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "o";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "o");
                            break;
                        }
                        else if (space == "." && counter.X >= 2)
                        {
                            move_made = true;

                            char ch = 'a' + new_row;
                            string value = "x";
                            cout << "Computer Move: Row (" << ch << ") "
                                 << "Col (" << new_col + 1 << ") "
                                 << "Value (" << value << ")";
                            cout << endl;

                            game.set_player_move(new_row, new_col, "x");
                            break;
                        }
                        new_row++;
                        new_col++;
                    }
                    if (move_made)
                    {
                        break;
                    }
                }
                if (move_made)
                {
                    break;
                }
            }
        }

        if (!move_made)
        {
            set_random_idx(game);
        }
    }

    string get_objective()
    {
        return objective;
    }
    void set_objective(string obj)
    {
        objective = obj;
    }

    bool get_go_first()
    {
        return go_first;
    }
    void set_go_first(bool status)
    {
        go_first = status;
    }
};

void print_general_instructions()
{
    cout << "ORDER AND CHAOS\n";
    cout << "---------------\n";

    cout << "This is a two player game played on a 6X6 (or bigger) "
            "grid where one player plays \"ORDER\" and the other \"CHAOS\".\n";
    cout << "Players take turns placing X or O in the empty squares.\n";
    cout << "ORDER wins if they make 5 Xs or Os in a line "
            "(horizontally, vertically, or diagonally), "
            "and CHAOS wins if they can prevent this. \n";
    cout << "For this game, you play against a computer.\n";
    cout << endl;
}
int get_grid_size()
{
    // allocates a temporary char space that can contain 100 elements
    char grid_size_str[100];

    cout << "What board size woud you like to play on? "
         << "(Note the board size must be a size of 6, 7, 8, or 9)\n";
    cin >> grid_size_str;
    // convert string to int
    int grid_size = atoi(grid_size_str);
    while (grid_size < 6 || grid_size > 9)
    {
        cout << endl;
        cout << "Invalid grid size, please try again!\n";
        cout << endl;
        cout << "What board size woud you like to play on? "
             << "(Note the board size must be a size of 6, 7, 8, or 9)\n";
        cin >> grid_size_str;
        grid_size = atoi(grid_size_str);
    }

    return grid_size;
}
void print_confirmation()
{
    cout << "Nice! This will be the layout of the baord.\n";
}
void assign_randomize_factor(Player &player, Computer &computer)
{
    int random_num = rand() % 2;
    if (random_num == 0)
    {
        player.objective = "ORDER";
        computer.set_objective("CHAOS");
    }
    else
    {
        player.objective = "CHAOS";
        computer.set_objective("ORDER");
    }

    random_num = rand() % 2;
    if (random_num == 0)
    {
        player.go_first = true;
    }
    else
    {
        computer.set_go_first(true);
    }
}
void print_objectives_and_priority(Player &player, Computer &computer)
{
    assign_randomize_factor(player, computer);
    cout << "For this game, you will play as: " << player.objective << endl;
    cout << "The computer will play as: " << computer.get_objective() << endl;
    cout << endl;
    if (player.go_first == true)
    {
        cout << "You will go first.\n";
    }
    else
    {
        cout << "The computer will go first.\n";
    }
}
void print_play_again_message()
{
    cout << "Play again?\n";
}

int main()
{
    srand(time(nullptr));

    // Introduction
    print_general_instructions();

    // Play Again Loop
    while (true)
    {
        int board_size = get_grid_size();
        GameBoard game(board_size);
        cout << endl;
        print_confirmation();
        game.print_current_board();
        cout << endl;

        Player player;
        Computer computer;
        print_objectives_and_priority(player, computer);

        // Game End Loop
        bool GAME_WIN = false;
        while (!GAME_WIN && !game.get_resignation_status())
        {
            if (player.go_first)
            {
                game.print_current_board();
                game.make_user_move();
                GAME_WIN = game.check_ORDER_win();

                if (!GAME_WIN && !game.get_resignation_status())
                {
                    GAME_WIN = game.check_CHAOS_win();
                }

                if (!GAME_WIN && !game.get_resignation_status())
                {
                    if (player.objective == "ORDER")
                    {
                        computer.chaos_bot(game);
                        GAME_WIN = game.check_ORDER_win();
                    }
                    else
                    {
                        computer.order_bot(game);
                        GAME_WIN = game.check_ORDER_win();
                    }
                }
                if (!GAME_WIN && !game.get_resignation_status())
                {
                    GAME_WIN = game.check_CHAOS_win();
                }
            }
            else if (computer.get_go_first())
            {
                if (player.objective == "ORDER")
                {
                    computer.chaos_bot(game);
                    GAME_WIN = game.check_ORDER_win();
                }
                else
                {
                    computer.order_bot(game);
                    GAME_WIN = game.check_ORDER_win();
                }
                if (!GAME_WIN && !game.get_resignation_status())
                {
                    GAME_WIN = game.check_CHAOS_win();
                }

                if (!GAME_WIN && !game.get_resignation_status())
                {
                    game.print_current_board();
                    game.make_user_move();
                    GAME_WIN = game.check_ORDER_win();
                }
                if (!GAME_WIN && !game.get_resignation_status())
                {
                    GAME_WIN = game.check_CHAOS_win();
                }
            }
            cout << endl;
        }

        game.print_current_board();

        cout << endl;

        if (game.get_ORDER_win_staus())
        {
            if (player.objective == "ORDER")
            {
                cout << "Good Game! YOU WIN!!!\n";
            }
            else
            {
                cout << "Good Game! COMPUTER WINS!!!\n";
            }
        }
        else if (game.get_CHAOS_win_status())
        {
            if (player.objective == "CHAOS")
            {
                cout << "Good Game! YOU WIN!!!\n";
            }
            else
            {
                cout << "Good Game! COMPUTER WINS!!!\n";
            }
        }
        else
        {
            cout << "Good Game! Computer wins.\n";
        }

        string play_again_status;
        print_play_again_message();
        cin >> play_again_status;
        bool is_valid_play_input = game.check_valid_play_again_status(play_again_status);
        while (!is_valid_play_input)
        {
            cout << "Could you repeat that?\n";
            play_again_status.clear();
            cin >> play_again_status;
            is_valid_play_input = game.check_valid_play_again_status(play_again_status);
        }

        if (play_again_status == "No" || play_again_status == "no")
        {
            break;
        }

        cout << endl;
        cout << endl;
    }
}

/*
Assignment 5 Report
===================

Description of Computers Playing Strategy
-----------------------------------------

(Describe the strategy your computer player uses. Include a discussion of how
well it plays, if there are any known weaknesses, and any other relevant
information.)

STRATEGY:
- Priorities goes from rows to columns to diagonal ascending and finally diagonal descending.
- However, the values are adjusted so that it will block or place if there
    are a certain amount of symbols already there.
- The bot does not block and connect 100% of the time due to it favouring 
    the priority but does it successfully fairly often.
- If there are no good option such as when it goes first, then a random location and
    symbol is picked and placed.

WEAKNESSES:
- If the player plays specifically to avoid detection or create a double interesecting
    connection, the bot gets overwhelmed and picks according the priority list
    which will lead to inaccurate placements.
- Particularly weak against diagonals.
- An example can be if player just puts a column of 'x' in the middle at the start.
- The bot has the potential to lose accidentally due to the random factor it carries.

Extra Features
--------------

(Describe all extra features your program has that were not required by the
assignment; if there are no extra features, then say that.)
- There are no extra features.


Known Bugs and Limitations
--------------------------
- Other than the weaknesses describe above, everything else should working as normal
(If your program is perfect and unlimited, then say so!)
- There should be no bugs to the extent of what it can do.

Acknowledgements of All Help
----------------------------
(Cite all websites, books, people, etc. that you got help from, including what
sort of help you got. Each citation should be about 1 to 2 lines long.)

- Help with the use of atoi
(https://cplusplus.com/reference/cstdlib/atoi/)
*/