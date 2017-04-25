#include <iostream>
#include "Board.h"

using namespace std;

Board::Board()
{
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            game_board_[i][j] = i * BOARD_SIZE + j + '1';
        }
    }
}

Board::~Board()
{
}

void Board::print_board()
{
    system("clear");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    for(int i = 0; i < BOARD_SIZE; i++) {

        for(int j = 0; j < BOARD_SIZE - 1; j++) {
            cout << "     |";
        }
        cout << "     " << endl;

        for(int j = 0; j < BOARD_SIZE - 1; j++) {
            cout << "  " << game_board_[i][j] << "  |";
        }
        cout << "  " << game_board_[i][BOARD_SIZE - 1] << endl;

        for(int j = 0; j < BOARD_SIZE - 1; j++) {
            if(i < BOARD_SIZE - 1) {
                cout << "_____|";
            } else {
                cout << "     |";
            }
        }
        if(i < BOARD_SIZE - 1) {
            cout << "_____" << endl;
        } else {
            cout << "     " << endl;
        }
    }
    cout << endl;
}

bool Board::is_winner(Player player)
{
    // check for row or column wins
    for(unsigned i = 0; i < BOARD_SIZE; i++) {
        bool row_win = true;
        bool col_win = true;
        for(unsigned j = 0; j < BOARD_SIZE; j++) {
            row_win &= (game_board_[i][j] == player.get_marker());
            col_win &= (game_board_[j][i] == player.get_marker());
        }
        if(col_win || row_win) {
            return true;
        }
    }
    // check for diagonal wins
    bool diag_win = true;
    for(unsigned i = 0; i < BOARD_SIZE; i++) {
        diag_win &= game_board_[i][i] == player.get_marker();
    }
    if(diag_win) {
        return true;
    }

    diag_win = true;
    for(unsigned i = 0; i < BOARD_SIZE; i++) {
        diag_win &= game_board_[i][BOARD_SIZE - i - 1] == player.get_marker();
    }
    return diag_win;
}

void Board::set_marker(int row, int col, Marker marker)
{
    game_board_[row][col] = marker;
}

char Board::get_marker(int row, int col)
{
    return game_board_[row][col];
}