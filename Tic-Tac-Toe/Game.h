#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Player.h"
#include "global.h"

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    Board board_;
    Player player_1_, player_2_;
    int turn_;
};

#endif // GAME_H
