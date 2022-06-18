#pragma once
#include <string>
#include "Team.hpp"
#include <random>
////got inspiration and ideas from Amit Goffer
using namespace std;
namespace basketball{
    class Game
    {
    private:
        random_device rd{};
        mt19937 gen{rd()};
        normal_distribution<double> homeP{90,4};
        normal_distribution<double> awayP{86,4};
    public:
        Team* home_team;
        Team* away_team;

        int home_score;
        int away_score;

        Game(Team*, Team*);
        Team* getTeamHome();
        Team* getTeamAway();
        int getScoreHome();
        int getScoreAway();


    };
}