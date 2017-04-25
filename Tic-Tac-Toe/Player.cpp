#include <iostream>
#include "Board.h"

using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

void Player::place_marker(Board& board)
{
    char position;
    int row, col;

    cin >> position;
    row = (position - '1') / BOARD_SIZE;
    col = (position - '1') % BOARD_SIZE;
    while(!('1' <= position && position <= '9') || board.get_marker(row, col) == CROSS ||
        board.get_marker(row, col) == CIRCLE) {
        cout << "Invalid input. Please try another one: ";
        cin >> position;
        row = (position - '1') / BOARD_SIZE;
        col = (position - '1') % BOARD_SIZE;
    }
    board.set_marker(row, col, marker_);
}