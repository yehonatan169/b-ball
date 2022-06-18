#pragma once
#include "Game.hpp"
#include <vector>

namespace basketball
{
    class Schedule{
    public:
        vector<Game*> allGames;
        Schedule(vector<Team*>);
        vector<Game*> getAllGames();

    };
}