#define CATCH_CONFIG_MAIN
#include <vector>
#include "catch.hpp"

int score(int number) {
    return number;
}

SCENARIO("Miss in every game") {
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

SCENARIO("Ten strikes - perfect game") {
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