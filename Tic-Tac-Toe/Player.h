#ifndef PLAYER_H
#define PLAYER_H

#include "global.h"

class Board;

class Player
{
public:
    Player();
    Player(Marker marker)
    {
        marker_ = marker;
    }
    ~Player();
    Marker get_marker()
    {
        return marker_;
    }
    void place_marker(Board& board);

private:
    Marker marker_;
};

#endif // PLAYER_H
