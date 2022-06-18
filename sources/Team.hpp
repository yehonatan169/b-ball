
#pragma once
#include <string>
#include <iostream>
////got inspiration and ideas from Amit Goffer
using namespace std;
namespace basketball{
    class Team
    {
    public:
        string name;
        double talent;
        int wins;
        int loses;
        int total_Score;

        Team(string name, double talent);
        Team(string name);
        string getName();
        double getTalent();
        void setTalent(double value);
        void addWin();
        void addLose();
        void add_to_total_score(int score);
        bool operator < (Team);
        void Check_name(string);

    };
}