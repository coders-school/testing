#include <string>
#include "catch.hpp"

enum class ResultCode {
    OK,
    BadCharacter,
    BadFormat,
    UndefinedError
};

// dummy function
ResultCode calculateTotalScore(const std::string& frameScores, int* totalScore) {
    *totalScore = -1;  // result impossible to achieve
    return ResultCode::UndefinedError;
}

SCENARIO("The calculateTotalScore() function calculates a total bowling score for given frame scores", "[bowling][totalScore]") {
    GIVEN("the frame scores: \"X|X|X|X|X|X|X|X|X|X||XX\"") {
        std::string frameScores{"X|X|X|X|X|X|X|X|X|X||XX"};
        int totalScore{-1};

        WHEN("total score is calculated") {
            ResultCode resultCode = calculateTotalScore(frameScores, &totalScore);

            THEN("the expected total score is") {
                int expectedTotalScore{300};
                REQUIRE(totalScore == expectedTotalScore);
                REQUIRE(resultCode == ResultCode::OK);
            }
        }
    }

    GIVEN("the frame scores: \"9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||\"") {
        std::string frameScores{"9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"};
        int totalScore{-1};

        WHEN("total score is calculated") {
            ResultCode resultCode = calculateTotalScore(frameScores, &totalScore);

            THEN("the expected total score is") {
                int expectedTotalScore{90};
                REQUIRE(totalScore == expectedTotalScore);
                REQUIRE(resultCode == ResultCode::OK);
            }
        }
    }

    GIVEN("the frame scores: \"5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5\"") {
        std::string frameScores{"5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5"};
        int totalScore{-1};

        WHEN("total score is calculated") {
            ResultCode resultCode = calculateTotalScore(frameScores, &totalScore);

            THEN("the expected total score is") {
                int expectedTotalScore{150};
                REQUIRE(totalScore == expectedTotalScore);
                REQUIRE(resultCode == ResultCode::OK);
            }
        }
    }

    GIVEN("the frame scores: \"X|7/|9-|X|-8|8/|-6|X|X|X||81\"") {
        std::string frameScores{"X|7/|9-|X|-8|8/|-6|X|X|X||81"};
        int totalScore{-1};

        WHEN("total score is calculated") {
            ResultCode resultCode = calculateTotalScore(frameScores, &totalScore);

            THEN("the expected total score is") {
                int expectedTotalScore{167};
                REQUIRE(totalScore == expectedTotalScore);
                REQUIRE(resultCode == ResultCode::OK);
            }
        }
    }

    GIVEN("the frame scores: \"-|-|-|-|-|-|-|-|-|-||--\"") {
        std::string frameScores{"-|-|-|-|-|-|-|-|-|-||--"};
        int totalScore{-1};

        WHEN("total score is calculated") {
            ResultCode resultCode = calculateTotalScore(frameScores, &totalScore);

            THEN("the expected total score is") {
                int expectedTotalScore{0};
                REQUIRE(totalScore == expectedTotalScore);
                REQUIRE(resultCode == ResultCode::OK);
            }
        }
    }

    GIVEN("the frame scores: \"X|X|X|X|X|X|X|X|X|X||XX\" (with white spaces)") {
        std::string frameScores = GENERATE(std::string{"X | X|X| X|X|X |X| X |X| X     ||XX"},
                                           std::string{" X|X| X |X |   X |X|X|X |X|X || XX"},
                                           std::string{"   X|X|X|      X | X  |X|X|X|X|X| |   X  X   "});

        int totalScore{-1};

        WHEN("total score is calculated") {
            ResultCode resultCode = calculateTotalScore(frameScores, &totalScore);

            THEN("the expected total score is") {
                int expectedTotalScore{300};
                REQUIRE(totalScore == expectedTotalScore);
                REQUIRE(resultCode == ResultCode::OK);
            }
        }
    }
}
