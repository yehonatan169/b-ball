#include "Team.hpp"
#include <random>


namespace basketball {
    Team::Team(string nam, double talent) : name(nam), talent(talent) {
        if (talent < 0 || talent > 1) {
            throw runtime_error("talent must be between 0 and 1");
        }
        Check_name(name);
        this->talent = talent;
        this->wins = 0;
        this->loses = 0;
        this->total_Score=0;

    }

    Team::Team(string nam) : name(nam) {
        Check_name(name);
        this->talent = ((double) rand() / (RAND_MAX));
        this->wins = 0;
        this->loses = 0;
        this->total_Score=0;
    }

    //check for valid string
    void Team::Check_name(string name) {
        bool valid_letter = false;
        if (name.empty() || name == " ") {
            throw std::invalid_argument("no valid name");
        }
        for (size_t i = 0; i < name.length(); i++) {
            if (name.at(i) >= 33 && name.at(i) <= 126) {
                valid_letter = true;
            }
            if (name.at(i) < 32 || !isprint(name.at(i))) {
                throw std::invalid_argument("non valid name");
            }
        }
    }

    //getter and setters
    string Team::getName() {
        return this->name;
    }

    double Team::getTalent() {
        return this->talent;
    }

    void Team::setTalent(double value) {
        this->talent = value;
    }

    void Team::addWin() {
        this->wins++;
    }

    void Team::addLose() {
        this->loses++;
    }

    void Team::add_to_total_score(int score){
        this->total_Score += score;
    }

    bool Team::operator<(Team t) {
        if ((double) this->wins / this->loses == (double) t.wins / t.loses) {
            return (this->total_Score > t.total_Score);
        }
        return (double) (double) this->wins / this->loses > (double) t.wins / t.loses;
    }

}