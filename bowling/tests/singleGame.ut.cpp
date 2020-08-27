#include "catch.hpp"

#include "singleGame.hpp"

#include <utility>
#include <vector>

SCENARIO("Reading names from game input in SingleGame class")
{
    GIVEN("Constructor takes a game input as string")
    {
        using somePairs = std::vector<std::pair<SingleGame, std::string>>;

        somePairs whosPlay{
            {SingleGame("Romek: X|13|14|14|12|"), {"Romek"}},
            {SingleGame("Zenon: X|13|14|14|12|"), {"Zenon"}},
            {SingleGame("Gienia: 1/|13|14|14|12|"), {"Gienia"}},
            {SingleGame("Matylda: 12|13|14|14|12|"), {"Matylda"}},
            {SingleGame("Eustachy: 33|13|14|14|12|"), {"Eustachy"}},
            {SingleGame("Zuzka:X|13|14|14|12|"), {"Zuzka"}},
            {SingleGame(": -2|13|14|14|12|"), {"Anonymous"}}};

        WHEN("Constructor indirectly call private method readPlayerName() which store player name from game input")
        {
            THEN("You can get player name by using appropriate getter")
            {
                for (size_t i = 0; i < whosPlay.size(); i++) {
                    REQUIRE(whosPlay[i].first.getPlayerName() == whosPlay[i].second);
                }
            }
        }
    }
}

SCENARIO("Reading scores from game input in SingleGame class")
{
    GIVEN("Constructor takes a game input as string")
    {
        using somePairs = std::vector<std::pair<SingleGame, std::vector<size_t>>>;

        somePairs whosPlay 
        {
            {SingleGame("Romek:X|X|X|X|X|X|X|X|X|X||XX"), {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}},
            {SingleGame("Zenon:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"), {9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0}},
            {SingleGame("Gienia:5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5"), {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}},
            {SingleGame("Matylda:X|7/|9-|X|-8|8/|-6|X|X|X||81"), {10, 7, 3, 9, 0, 10, 0, 8, 8, 2, 0, 6, 10, 10, 10, 8, 1}},
            {SingleGame("Eustachy:33|13|14|14|12|"), {3, 3, 1, 3, 1, 4, 1, 4, 1, 2}},
            {SingleGame("Zuzka:X|13|14|14|12|"), {10, 1, 3, 1, 4, 1, 4, 1, 2}},
            {SingleGame(":-2|13|14|14|12|"), {0, 2, 1, 3, 1, 4, 1, 4, 1, 2}}
        };

                WHEN("Constructor indirectly call private method putScoresToVector() which analize game input, transforms input to nums and store in vector")
                {
                    THEN("You can get stored nums by using appropriate getter")
                    {
                        for(size_t i = 0; i < whosPlay.size(); i++){
                            CHECK(whosPlay[i].first.getRolls() == whosPlay[i].second);
                        }
                    }
                }
            }
        }
