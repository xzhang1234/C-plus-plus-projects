#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "global.h"

const int BOARD_SIZE = 3;
class Board
{
public:
    Board();
    ~Board();
    void print_board();
    bool is_winner(Player player);
    void set_marker(int row, int col, Marker marker);
    char get_marker(int row, int col);

private:
    char game_board_[BOARD_SIZE][BOARD_SIZE];
};

#endif // BOARD_H
