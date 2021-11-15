
#define CATCH_CONFIG_MAIN
#include <algorithm>
#include <exception>
#include <vector>

#include "catch_amalgamated.hpp"

int result(int number) {
    return number;
}

SCENARIO("Miss in every game") {
    GIVEN("Ten turns") {
        std::vector<int> game(0);
        WHEN("Missing in every turn") {
            int gameresult = result(0);
            THEN("result = 0 points") {
                REQUIRE(gameresult == 0);
                }
        }
    }
}

SCENARIO("Get 1 points in every game") {
    GIVEN("Ten turns") {
        std::vector<int> game;
        for (size_t i = 0; i < 10; i++) {
            game.emplace_back(1);
            game.emplace_back(0);
        }

        WHEN("Missing in last turn") {
            int gameresult = result(20);
            THEN("result = 20 points") {
                REQUIRE(gameresult == 20);
                }
        }
    }
}

SCENARIO("Ten strikes") {
    GIVEN("Ten turns") {
        std::vector<int> game(10, 10);
        WHEN("Get strike in every turn") {
            int gameresult = result(300);
            THEN("result = 300 points") {
                REQUIRE(gameresult == 300);
                }
        }
    }
}

SCENARIO("One strike") {
    GIVEN("Ten turns") {
        std::vector<int> game(9, 0);
        game.push_back(10);
        auto turnsBeforeRolling = game.size();
        game.push_back(5);
        game.push_back(5);

        WHEN("Getting strike in last turn") {
            int turnsAfterRolling = game.size();
            THEN("Should be 2 more rolls") {
                REQUIRE(turnsBeforeRolling + 2 == turnsAfterRolling); }
        }
    }
}

SCENARIO("One spare") {
    GIVEN("Ten turns") {
        std::vector<int> game(9, 0);
        game.push_back(10);
        auto lengthBeforeRolling = game.size();
        game.push_back(5);

        WHEN("Getting spare in last turn") {
            int lengthAfterRolling = game.size();
            THEN("Should be 1 more roll") { REQUIRE(lengthBeforeRolling + 1 == lengthAfterRolling); }
        }
    }
}

SCENARIO("First ball - 1, Second - 0") {
    GIVEN("Ten turns") {
        std::vector<int> game(10, 1);
        WHEN("1 hit with first ball and 0 with second") {
            auto gameResult = result(10);
            THEN("result = 10") {
                REQUIRE(gameResult == 10);
                }
        }
    }
}

SCENARIO("Spare every turn") {
    GIVEN("Ten turns") {
        std::vector<int> game(20, 5);
        WHEN("5 hit with the first ball, spare with the second") {
            auto gameResult = result(150);
            THEN("result = 150") {
                REQUIRE(gameResult == 150);
                }
        }
    }
}

SCENARIO("Spare") {
    GIVEN("Two turns") {
        int firstShot = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 9);
        int secondTurn = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9, 9);
        WHEN("first ball 1/9 pins, second ball - rest") {
            auto firstTurnresult = result(10 + secondTurn);
            THEN("Spare") {
                REQUIRE(firstTurnresult == 10 + secondTurn);
                }
        }
    }
}

SCENARIO("Strike") {
    GIVEN("Two turns") {
        int secondTurn = GENERATE(1, 2, 3, 4, 5, 6, 7, 8, 9);
        WHEN("first ball 10") {
            auto firstTurnresult = result(10 + secondTurn + 1);
            THEN("Strike") {
                REQUIRE(firstTurnresult == 10 + secondTurn + 1);
                }
        }
    }
}

SCENARIO("Game without strike and spare") {
    GIVEN("Game without strike and spare") {
        std::vector<int> game{1, 3, 2, 4, 3, 6, 4, 1, 5, 0, 6, 2, 4, 1, 3, 2, 2, 7, 3, 5};
        WHEN("Count result") {
            auto gameresult = result(64);
            THEN("Result") {
                REQUIRE(gameresult == 64);
                }
        }
    }
}
