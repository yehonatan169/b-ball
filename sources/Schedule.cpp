#include "Schedule.hpp"

namespace basketball{
    Schedule::Schedule(vector<Team*> l)
    {
        const int twenty = 20;
        if(l.size() != twenty){
            throw runtime_error("teams number must be 20");
        }

        //add all possible game combination
        for(size_t i = 0; i < 20; i++){
            for(size_t j = 0; j < 20; j++){
                if(i != j){
                    this->allGames.emplace_back(new Game{l[i],l[j]});
                }

            }
        }
    }

    vector<Game*> Schedule::getAllGames(){
        return this->allGames;
    }


}