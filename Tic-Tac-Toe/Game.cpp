#include <iostream>
#include "Game.h"

using namespace std;

Game::Game()
    : board_()
    , player_1_(CROSS)
    , player_2_(CIRCLE)
    , turn_(1)
{
}

Game::~Game()
{
}

void Game::run()
{
    board_.print_board();
    bool player_1_win = false, player_2_win = false;
    do {
        if(turn_ == 1) {
            cout << "Player 1, enter a number: ";
            player_1_.place_marker(board_);
            player_1_win = board_.is_winner(player_1_);
        } else {
            cout << "Player 2, enter a number: ";
            player_2_.place_marker(board_);
            player_2_win = board_.is_winner(player_2_);
        }
        board_.print_board();
        turn_ = turn_ == 1 ? 2 : 1;
    } while(!player_1_win && !player_2_win);
    cout << "Player " << (player_1_win ? 1 : 2) << " win!" << endl;
}