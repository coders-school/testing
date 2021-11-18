#define CATCH_CONFIG_MAIN

#include <string>
#include "catch.hpp"

enum class ResultCode {
    OK,
    BadCharacter,
    BadFormat,
    UndefinedError
};

struct FramesAndResults {
    std::string frames;
    int totalScore;
    ResultCode resultCode;
};

// dummy function to be tested
ResultCode calculateTotalScore(const std::string& frames, int* totalScore) {
    *totalScore = -1;  // result impossible to achieve
    return ResultCode::UndefinedError;
}

SCENARIO("The calculateTotalScore() function calculates a total bowling score for given frame scores", "[bowling][totalScore]") {
    GIVEN("the frame scores") {
        FramesAndResults framesAndResults = GENERATE(FramesAndResults{"X|X|X|X|X|X|X|X|X|X||XX", 300, ResultCode::OK},
                                                     FramesAndResults{"9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||", 90, ResultCode::OK},
                                                     FramesAndResults{"5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5", 150, ResultCode::OK},
                                                     FramesAndResults{"-|-|-|-|-|-|-|-|-|-||--", 0, ResultCode::OK},
                                                     FramesAndResults{"--|4/|71|X|45|8-|X|9-|54|32||", 103, ResultCode::OK},
                                                     FramesAndResults{"X|53|4/|9/|25|7/|9-|X|53|7/||X", 138, ResultCode::OK},
                                                     FramesAndResults{"X|7/|9-|X|-8|8/|-6|X|X|X||81", 167, ResultCode::OK});
        WHEN("total score is calculated") {
            int totalScore{-1};
            ResultCode resultCode = calculateTotalScore(framesAndResults.frames, &totalScore);

            THEN("the expected total score for:\n\"" << framesAndResults.frames << "\"\nis: " << framesAndResults.totalScore) {
                REQUIRE(totalScore == framesAndResults.totalScore);
                REQUIRE(resultCode == framesAndResults.resultCode);
            }
        }
    }

    GIVEN("the frame scores with white spaces") {
        FramesAndResults framesAndResults = GENERATE(FramesAndResults{"X | X|X| X|X|X |X| X |X| X     ||XX", 300, ResultCode::OK},
                                                     FramesAndResults{" X|X| X |X |   X |X|X|X |X|X || XX", 300, ResultCode::OK},
                                                     FramesAndResults{"   X|X|X|      X | X  |X|X|X|X|X| |   X  X   ", 300, ResultCode::OK});
        WHEN("total score is calculated") {
            int totalScore{-1};
            ResultCode resultCode = calculateTotalScore(framesAndResults.frames, &totalScore);

            THEN("the expected total score for:\n\"" << framesAndResults.frames << "\"\nis: " << framesAndResults.totalScore) {
                REQUIRE(totalScore == framesAndResults.totalScore);
                REQUIRE(resultCode == framesAndResults.resultCode);
            }
        }
    }

    GIVEN("the frame scores with lower case 'x'") {
        FramesAndResults framesAndResults = GENERATE(FramesAndResults{"x|x|x|x|x|x|x|x|x|x||xx", 300, ResultCode::OK},
                                                     FramesAndResults{"X|X|X|x|X|x|x|x|x|x||xx", 300, ResultCode::OK});
        WHEN("total score is calculated") {
            int totalScore{-1};
            ResultCode resultCode = calculateTotalScore(framesAndResults.frames, &totalScore);

            THEN("the expected total score for:\n\"" << framesAndResults.frames << "\"\nis: " << framesAndResults.totalScore) {
                REQUIRE(totalScore == framesAndResults.totalScore);
                REQUIRE(resultCode == framesAndResults.resultCode);
            }
        }
    }

    GIVEN("the frame scores with disallowed characters") {
        FramesAndResults framesAndResults = GENERATE(FramesAndResults{"?|X|X|X|X|X|X|X|X|X||XX", 0, ResultCode::BadCharacter},
                                                     FramesAndResults{"X\\X|X|X|X|X|X|X|X|X||XX", 0, ResultCode::BadCharacter},
                                                     FramesAndResults{"_|X|X|X|X|X|X|X|X|X||XX", 0, ResultCode::BadCharacter});
        WHEN("total score is calculated") {
            int totalScore{-1};
            ResultCode resultCode = calculateTotalScore(framesAndResults.frames, &totalScore);

            THEN("the expected total score for:\n\"" << framesAndResults.frames << "\"\nis: " << framesAndResults.totalScore) {
                REQUIRE(totalScore == framesAndResults.totalScore);
                REQUIRE(resultCode == framesAndResults.resultCode);
            }
        }
    }

    GIVEN("the frame scores with wrong frame format") {
        FramesAndResults framesAndResults = GENERATE(FramesAndResults{"X||X|X|X|X|X|X|X|X|X||XX", 0, ResultCode::BadFormat},
                                                     FramesAndResults{"X|||X|X|X|X|X|X|X|X|X||XX", 0, ResultCode::BadFormat},
                                                     FramesAndResults{"X|X|X|X|X|X|X|X|X|X||XX|", 0, ResultCode::BadFormat},
                                                     FramesAndResults{"X|X|X|X|X|X|X|X|X|X|X||XX|", 0, ResultCode::BadFormat},
                                                     FramesAndResults{"|X|X|X|X|X|X|X|X|X|X|X||XX|", 0, ResultCode::BadFormat},
                                                     FramesAndResults{"XX||X|X|X|X|X|X|X|X||XX", 0, ResultCode::BadFormat},
                                                     FramesAndResults{"X|X|X|X|X|", 0, ResultCode::BadFormat},
                                                     FramesAndResults{"X|X|X|X|X|X|X|X||XX", 0, ResultCode::BadFormat});

        WHEN("total score is calculated") {
            int totalScore{-1};
            ResultCode resultCode = calculateTotalScore(framesAndResults.frames, &totalScore);

            THEN("the expected total score for:\n\"" << framesAndResults.frames << "\"\nis: " << framesAndResults.totalScore) {
                REQUIRE(totalScore == framesAndResults.totalScore);
                REQUIRE(resultCode == framesAndResults.resultCode);
            }
        }
    }
}
