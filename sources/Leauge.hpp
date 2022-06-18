#pragma once
#include "Schedule.hpp"
using namespace std;

namespace basketball{
    class League
    {
    public:
        vector<Team*> teams;
        vector<Team> copy_teams = {};

        bool gameStarted;
        League();
        League(vector<Team*>);
        void Games_run();
        void run_Statistics(int);
        vector<Team*> get_Teams();
        double get_random_zero_to_one();

    };
}