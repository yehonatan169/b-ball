#include "doctest.h"
#include "sources/Game.hpp"
#include "sources/Team.hpp"
#include "sources/Leauge.hpp"
using namespace basketball;

TEST_CASE("teamMaker"){
    std::vector<Team*> allTeams;
    CHECK_THROWS(allTeams.emplace_back(new Team("")));
    CHECK_THROWS(allTeams.emplace_back(new Team("\r")));
    CHECK_THROWS(allTeams.emplace_back(new Team("\n")));
    CHECK_THROWS(allTeams.emplace_back(new Team("\t")));
    CHECK_THROWS(allTeams.emplace_back(new Team("\r")));
    CHECK_THROWS(allTeams.emplace_back(new Team(" ")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("amosi")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("amociiii")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("fdsfds2 dsfds")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("maccabi tel aviv")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("hiffa")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("chelsi")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("usa")));
    CHECK_NOTHROW(allTeams.emplace_back(new Team("japan")));

}

TEST_CASE("league1"){
    vector<Team*> NBA = {};
    vector<string> name = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t"};
    for(size_t i = 0; i < 20; i++){
        NBA.emplace_back(new Team{name.at(i)});
    }

    League NBA2 = League{NBA};
            CHECK_EQ(NBA2.get_Teams().size(), 20);
    CHECK_THROWS(NBA2.run_Statistics(3));
    NBA2.Games_run();
    CHECK_THROWS(NBA2.run_Statistics(21));
    CHECK_NOTHROW(NBA2.run_Statistics(3));
}

TEST_CASE("league2"){

    League NBA = League{};
            CHECK_EQ(NBA.get_Teams().size(), 20);
    CHECK_THROWS(NBA.run_Statistics(3));
    NBA.Games_run();
    CHECK_THROWS(NBA.run_Statistics(21));
    CHECK_NOTHROW(NBA.run_Statistics(3));
}
