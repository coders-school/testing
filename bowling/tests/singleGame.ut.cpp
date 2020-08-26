#include "catch.hpp"

#include "singleGame.hpp"

#include <utility>


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
            {SingleGame(": -2|13|14|14|12|"), {"Anonymous"}}
        };

        WHEN("Constructor indirectly call private method readPlayerName() which store player name from game input")
        {
            
            THEN("You can get player name by using appropriate getter")
            {
                for(size_t i = 0; i < whosPlay.size(); i++){
                    REQUIRE(whosPlay[i].first.getPlayerName() == whosPlay[i].second);
                }
            }
        }
    }
}
