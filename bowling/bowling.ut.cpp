#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"

int score(int number) {
    return number;
}

SCENARIO("Miss in every game", "[points]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(20, 0);
        WHEN("Missing in every turn") {
            int gameScore = score(0);
            THEN("Score should be 0 points") {
                REQUIRE(gameScore == 0);
            }
        }
    }
}

SCENARIO("Ten strikes - perfect game", "[points]") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(10, 10);
        WHEN("Getting strike in every turn") {
            int gameScore = score(300);
            THEN("Score should be 300 points") {
                REQUIRE(gameScore == 300);
            }
        }
    }
}

SCENARIO("Strike in last turn") {
    GIVEN("Ten turns of game") {
        std::vector<int> game(9, 0);
        game.push_back(10);
        auto lengthBeforeRolling = game.size();
        game.push_back(5);
        game.push_back(5);

        WHEN("Getting strike in every turn") {
            int lengthAfterRolling = game.size();
            THEN("Score should be 300 points") {
                REQUIRE(lengthBeforeRolling + 2 == lengthAfterRolling);
            }
        }
    }
}