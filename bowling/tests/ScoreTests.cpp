#include <array>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "../src/Score.hpp"
#include "catch.hpp"

SCENARIO("Score::addResult validation check", "[addResult][Score]") {
    for (uint8_t i = 0; i <= 10; ++i) {
        Score scores;
        GIVEN("Valid result to add = " + std::to_string(i)) {
            WHEN("Adding") {
                THEN("Score::addResult shall not throw an exception") {
                    REQUIRE_NOTHROW(scores.addResult(i));
                }
            }
        }
    }
    std::array<int64_t, 5> badArgsArr{-1, -10, 423432423, -42343242, 11};
    for (const auto& arg : badArgsArr) {
        Score scores;
        GIVEN("Not valid result to add = " + std::to_string(arg)) {
            WHEN("Adding") {
                THEN("Score::addResult should throw an exception") {
                    REQUIRE_THROWS_AS(scores.addResult(arg), std::invalid_argument);
                }
            }
        }
    }
}

SCENARIO("Score::addResult overflow check", "[addResult][Score]") {
    Score scores;
    GIVEN("23 valid arguments") {
        WHEN("Adding arguments") {
            for (uint8_t i = 0; i < 22; ++i) {
                THEN("First 22 arguments should not throw an exception, argument no: " + std::to_string(i + 1)) {
                    REQUIRE_NOTHROW(scores.addResult(5));
                }
            }
            THEN("The last argument should thrown an exception, argument no: 23") {
                REQUIRE_THROWS_AS(scores.addResult(5), std::invalid_argument);
            }
        }
    }
}

SCENARIO("Score::resultsToString check - partial results", "[resultsToString][Score]") {
    std::array<std::pair<std::vector<uint8_t>, std::string>, 6> arr1{{
        {{9, 0}, "9-|  |  |  |  |  |  |  |  |  ||"},
        {{10, 0, 10, 0, 10, 0}, "X|X|X|  |  |  |  |  |  |  ||"},
        {{0, 0, 0, 0, 0, 0}, "--|--|--|  |  |  |  |  |  |  ||"},
        {{7, 3, 0, 10, 5}, "7/|-/|5 |  |  |  |  |  |  |  ||"},
        {{3}, "3 |  |  |  |  |  |  |  |  |  ||"},
        {{}, "  |  |  |  |  |  |  |  |  |  ||"}
    }};

    for (uint8_t testCaseNo = 0; testCaseNo < arr1.size(); ++testCaseNo) {
        GIVEN(arr1[testCaseNo].second) {
            Score scores;
            WHEN("Adding partial results " + arr1[testCaseNo].second) {
                for (const auto arg : arr1[testCaseNo].first) {
                    scores.addResult(arg);
                }
                THEN("Computed string should be " + arr1[testCaseNo].second) {
                    REQUIRE(scores.resultsToString() == arr1[testCaseNo].second);
                }
            }
        }
    }
}

SCENARIO("Score::resultsToString check - complete results", "[resultsToString][Score]") {
    using CheckArray = std::array<std::pair<std::array<std::pair<uint8_t, uint8_t>, 11>, std::string>, 9>;
    CheckArray arr1{{
        {{{{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 10}}}, "X|X|X|X|X|X|X|X|X|X||XX"},
        {{{{9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {0, 0}}}, "9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"},
        {{{{5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 0}}}, "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5"},
        {{{{10, 0}, {7, 3}, {9, 0}, {10, 0}, {0, 8}, {8, 2}, {0, 6}, {10, 0}, {10, 0}, {10, 0}, {8, 1}}}, "X|7/|9-|X|-8|8/|-6|X|X|X||81"},
        {{{{8, 0}, {7, 0}, {5, 3}, {9, 1}, {9, 1}, {10, 0}, {8, 0}, {5, 1}, {3, 7}, {9, 0}, {0, 0}}}, "8-|7-|53|9/|9/|X|8-|51|3/|9-||"},
        {{{{8, 2}, {9, 0}, {4, 4}, {7, 2}, {9, 0}, {10, 0}, {10, 0}, {8, 0}, {3, 5}, {9, 1}, {7, 0}}}, "8/|9-|44|72|9-|X|X|8-|35|9/||7"},
        {{{{8, 2}, {5, 4}, {9, 0}, {10, 0}, {10, 0}, {5, 5}, {5, 3}, {6, 3}, {9, 1}, {9, 1}, {10, 0}}}, "8/|54|9-|X|X|5/|53|63|9/|9/||X"},
        {{{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}}, "--|--|--|--|--|--|--|--|--|--||"},
        {{{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 5}, {0, 0}}}, "--|--|--|--|--|--|--|--|--|-5||"},
    }};

    for (uint8_t testCaseNo = 0; testCaseNo < arr1.size(); ++testCaseNo) {
        Score scores;
        for (uint8_t frame = 0; frame < arr1[testCaseNo].first.size(); ++frame) {
            scores.addResult(arr1[testCaseNo].first[frame].first);
            scores.addResult(arr1[testCaseNo].first[frame].second);
        }
        GIVEN(arr1[testCaseNo].second) {
            WHEN("Score class is filled with correct arguments") {
                THEN("Computed string should be: " + arr1[testCaseNo].second) {
                    CHECK(scores.resultsToString() == arr1[testCaseNo].second);
                }
            }
        }
    }
}

SCENARIO("Score check - partial results", "[geScore][Score]") {
    std::array<std::pair<std::vector<uint8_t>, uint16_t>, 6> arr1{{
        {{9, 0}, 9},
        {{10, 0, 10, 0, 10, 0}, 50},
        {{0, 0, 0, 0, 0, 0}, 0},
        {{7, 3, 0, 10, 5}, 30},
        {{3}, 3},
        {{}, 0},
    }};

    for (uint8_t testCaseNo = 0; testCaseNo < arr1.size(); ++testCaseNo) {
        Score scores;
        for (const auto arg : arr1[testCaseNo].first) {
            scores.addResult(arg);
        }
        GIVEN(scores.resultsToString()) {
            WHEN("Partial throw results are added") {
                THEN("The result should be " + std::to_string(arr1[testCaseNo].second)) {
                    REQUIRE(scores.getScore() == arr1[testCaseNo].second);
                }
            }
        }
    }
}

SCENARIO("Score check - complete results", "[geScore][Score]") {
    using CorrectArray = std::array<std::pair<std::array<std::pair<uint8_t, uint8_t>, 11>, uint16_t>, 9>;
    CorrectArray arr1{{
        {{{{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 10}}}, 300},
        {{{{9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {9, 0}, {0, 0}}}, 90},
        {{{{5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 5}, {5, 0}}}, 150},
        {{{{10, 0}, {7, 3}, {9, 0}, {10, 0}, {0, 8}, {8, 2}, {0, 6}, {10, 0}, {10, 0}, {10, 0}, {8, 1}}}, 167},
        {{{{8, 0}, {7, 0}, {5, 3}, {9, 1}, {9, 1}, {10, 0}, {8, 0}, {5, 1}, {3, 7}, {9, 0}, {0, 0}}}, 122},
        {{{{8, 2}, {9, 0}, {4, 4}, {7, 2}, {9, 0}, {10, 0}, {10, 0}, {8, 0}, {3, 5}, {9, 1}, {7, 0}}}, 133},
        {{{{8, 2}, {5, 4}, {9, 0}, {10, 0}, {10, 0}, {5, 5}, {5, 3}, {6, 3}, {9, 1}, {9, 1}, {10, 0}}}, 149},
        {{{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}}}, 0},
        {{{{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 5}, {0, 0}}}, 5},
    }};

    for (uint8_t testCaseNo = 0; testCaseNo < arr1.size(); ++testCaseNo) {
        Score scores;
        for (uint8_t frame = 0; frame < arr1[testCaseNo].first.size(); ++frame) {
            scores.addResult(arr1[testCaseNo].first[frame].first);
            scores.addResult(arr1[testCaseNo].first[frame].second);
        }
        GIVEN(scores.resultsToString()) {
            WHEN("Score class is filled with correct arguments") {
                THEN("Final score should be " + std::to_string(arr1[testCaseNo].second)) {
                    CHECK(scores.getScore() == arr1[testCaseNo].second);
                }
            }
        }
    }
}
