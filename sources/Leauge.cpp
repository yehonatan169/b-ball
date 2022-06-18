#include "Leauge.hpp"
#include <bits/stdc++.h>

namespace basketball{

    League::League(){
        this->gameStarted = false;
        for(int i =0; i<20; i++){
            this->teams.emplace_back(new Team{to_string(i), get_random_zero_to_one()});
        }
    }
    League::League(vector<Team*> v){
        const int twenty = 20;
        this->gameStarted = false;

        unsigned i = 0;
        if(v.size() > twenty){
            throw runtime_error("size cant be more than 20");
        }

        //first copy input
        for(i = 0; i < v.size(); i++){
            this->teams.emplace_back(v.at(i));
        }

        //then fill the blanks
        for(size_t k = i; k < 20; k++){
            this->teams.emplace_back(new Team{to_string(k), get_random_zero_to_one()});
        }
    }

    double League::get_random_zero_to_one(){
        return ((double) rand() / (RAND_MAX));
    }

    void League::Games_run(){
        this->gameStarted = true;
        Schedule t = Schedule{this->get_Teams()};

        for(size_t i = 0; i < this->get_Teams().size(); i++){
            this->copy_teams.emplace_back(*(this->get_Teams().at(i)));
        }
        sort(this->copy_teams.begin(),this->copy_teams.end());

    }

    //this functions print all league statitics
    void League::run_Statistics(int bestTeams){
        if(!this->gameStarted){
            throw runtime_error("no games started yet so cant print statistics");
        }
        if(bestTeams > 20){
            throw runtime_error("number of best teams cant be higher than 20");
        }

        cout << "the best " << bestTeams << " teams are (from best to worst): \n" << endl;
        for(size_t i = 0; i <  bestTeams; i++){
            cout << "team " << (i+1) << endl;
            cout << "team name: " << copy_teams.at(i).getName() << endl;
            cout << "victories: " << copy_teams.at(i).wins << endl;
            cout << "loses: " << copy_teams.at(i).loses << endl;
            cout << "total_Score: " << copy_teams.at(i).total_Score << endl;
            cout << "talent: " << copy_teams.at(i).talent << endl;
            cout << "\n" << endl;
        }

    }

    vector<Team*> League::get_Teams(){
        return this->teams;
    }
}