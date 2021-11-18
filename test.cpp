#include <string>
#include "catch.hpp"

unsigned short calculateTotalScore(std::string) {
    return 301;
}

SCENARIO("A function calculates total bowling score from frame scores", "[bowling]") {
    GIVEN("the frame scores {\"X|X|X|X|X|X|X|X|X|X||XX\"}") {
        std::string frameScores{"X|X|X|X|X|X|X|X|X|X||XX"};

        WHEN("total score is calculated") {
            auto totalScore = calculateTotalScore(frameScores);

            THEN("the expected total score is") {
                unsigned short expectedTotalScore{300};
                REQUIRE(totalScore == expectedTotalScore);
            }
        }
    }
}

//     GIVEN("a vector") {
//         auto v = GENERATE(std::vector{1, 2, 3},
//                           std::vector{1, 3, 2},
//                           std::vector{2, 1, 3},
//                           std::vector{2, 3, 1},
//                           std::vector{3, 1, 2},
//                           std::vector{3, 2, 1});

//         WHEN("vector " << v[0] << v[1] << v[2] << "is sorted") {
//             std::sort(begin(v), end(v));

//             THEN("the sorted vector is") {
//                 std::vector expectedV {1, 2, 3};
//                 REQUIRE(v == expectedV);
//                 REQUIRE(std::is_sorted(cbegin(v), cend(v)));
//             }
//         }
//     }
