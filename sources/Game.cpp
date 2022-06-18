#include "Game.hpp"

namespace basketball{
    Game::Game(Team* home, Team* away) : home_team(home),away_team(away){
        this->home_score = 0;
        this-> away_score = 0;

        this->away_score = (int)(awayP(gen)+(10*this->away_team->talent));
        this->home_score = (int)(homeP(gen)+(10*this->home_team->talent));

        this->home_team->total_Score += this->home_score;
        this->away_team->total_Score += this->away_score;

        if(this->home_score >= this->away_score){
            this->home_team->wins++;
            this->away_team->loses++;

        }
        else{
            this->away_team->wins++;
            this->home_team->loses++;
        }
    }

    //getter
    Team* Game::getTeamHome(){
        return this->home_team;
    }

    Team* Game::getTeamAway(){
        return this->away_team;
    }

    int Game::getScoreHome(){
        return this->home_score;
    }

    int Game::getScoreAway(){
        return this->away_score;
    }
}