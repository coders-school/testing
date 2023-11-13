#include <catch2/catch_all.hpp>
#include <algorithm>
#include <vector>
#include <iostream>

SCENARIO("Testing strike score", "[int][string][strike]"){

    GIVEN("Strike configuration"){
    std::string givenConfiguration = "X";

        WHEN("All 10 pins are hit"){
            int score = 10;

            THEN("Result score for such configuration should be 300"){
                std::string expectedConfiguration = "X";
                int expectedScore = 10;
                REQUIRE(expectedConfiguration == givenConfiguration);
                REQUIRE(expectedScore == score);
            }
        }
    }
}

SCENARIO("Testing spare scores", "[int][string][spare]"){

    GIVEN("Strike configuration"){
    std::string givenConfiguration1 = "1/|5-";
    std::string givenConfiguration2 = "3/|6-";
    std::string givenConfiguration3 = "8/|9-";

        WHEN("Second ball knocks down all ten pins"){      
            auto score = GENERATE(as<int>{},15,16,19);

            THEN("Result score for such configuration should be 300"){
                std::string expectedConfiguration1 = "1/|5-";
                std::string expectedConfiguration2 = "3/|6-";
                std::string expectedConfiguration3 = "8/|9-";

                REQUIRE(expectedConfiguration1 == givenConfiguration1);
                REQUIRE(expectedConfiguration2 == givenConfiguration2);
                REQUIRE(expectedConfiguration3 == givenConfiguration3);

                REQUIRE(score > 10);
            }
        }
    }
}
SCENARIO("Testing bonus ball", "[int][string][bonus]"){

    GIVEN("Last frame was ended by a spare"){
    std::string givenConfiguration1 = "...|5/|5";

        WHEN("There is bonus ball"){      
            int throws = 10 + 1;

            THEN("There should be one more throw"){
                std::string expectedConfiguration1 = "...|5/|5";
                int expectedThrows = 11;

                REQUIRE(expectedConfiguration1 == givenConfiguration1);

                REQUIRE(throws == 11);
            }
        }
    }
}

SCENARIO("Testing 2 bonus balls", "[int][string][bonus]"){

    GIVEN("Last frame was ended by a strike"){
    std::string givenConfiguration1 = "...|X|XX";

        WHEN("There are 2 bonus balls"){      
            int throws = 10 + 2;

            THEN("There should be one more throw"){
                std::string expectedConfiguration1 = "...|X|XX";
                int expectedThrows = 11;

                REQUIRE(expectedConfiguration1 == givenConfiguration1);

                REQUIRE(throws == 12);
            }
        }
    }
}

SCENARIO("Testing best possible result", "[int][string][best]"){

    GIVEN("Ten strikes configuration"){
    std::string givenConfiguration = "X|X|X|X|X|X|X|X|X|X||XX";

        WHEN("All 10 frames were over by a strike"){
            int strikes = 10;
            int balls = strikes * 3;
            int score = balls * 10;

            THEN("Result score for such configuration should be 300"){
                std::string expectedConfiguration = "X|X|X|X|X|X|X|X|X|X||XX";
                int expectedScore = 300;
                REQUIRE(expectedConfiguration == givenConfiguration);
                REQUIRE(expectedScore == score);
            }
        }
    }
}

SCENARIO("Testing worst possible result", "[int][string][worst]"){

    GIVEN("Ten misses configuration"){
    std::string givenConfiguration = "--|--|--|--|--|--|--|--|--|--||";

        WHEN("All 10 frames were over by a double miss"){
            int doubleMisses = 10;
            int balls = doubleMisses * 0;
            int score = balls * 10;

            THEN("Result score for such configuration should be 0"){
                std::string expectedConfiguration = "--|--|--|--|--|--|--|--|--|--||";
                int expectedScore = 0;
                REQUIRE(expectedConfiguration == givenConfiguration);
                REQUIRE(expectedScore == score);
            }
        }
    }
}


SCENARIO("Testing simple configurations", "[int][string][simple]"){

    GIVEN("Simple configurations are present"){
        std::string Configuration1 = "1-|1-|1-|1-|1-|1-|1-|1-|1-|1-||";
        std::string Configuration2 = "1/|1/|1/|1/|1/|1/|1/|1/|1/|1/||1";
        std::string Configuration3 = "5-|5-|5-|5-|5-|5-|5-|5-|5-|5-||";
        std::string Configuration4 = "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5";
        std::string Configuration5 = "7-|7-|7-|7-|7-|7-|7-|7-|7-|7-||";


        

        WHEN("Round is finished, scores are as follows:"){
            int frames = 10;
            int score1 = 1 * frames;
            int score2 = 11 * frames;
            int score3 = 5 * frames;
            int score4 = 15 * frames;
            int score5 = 7 * frames;

            THEN("Result score for such configuration should be:"){
                std::string expectedConfiguration1 = "1-|1-|1-|1-|1-|1-|1-|1-|1-|1-||";
                std::string expectedConfiguration2 = "1/|1/|1/|1/|1/|1/|1/|1/|1/|1/||1";
                std::string expectedConfiguration3 = "5-|5-|5-|5-|5-|5-|5-|5-|5-|5-||";
                std::string expectedConfiguration4 = "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5";
                std::string expectedConfiguration5 = "7-|7-|7-|7-|7-|7-|7-|7-|7-|7-||";

                int expectedScore1 = 10;
                int expectedScore2 = 110;
                int expectedScore3 = 50;
                int expectedScore4 = 150;
                int expectedScore5 = 70;
                
                REQUIRE(expectedConfiguration1 == Configuration1);
                REQUIRE(expectedConfiguration2 == Configuration2);
                REQUIRE(expectedConfiguration3 == Configuration3);
                REQUIRE(expectedConfiguration4 == Configuration4);
                REQUIRE(expectedConfiguration5 == Configuration5);
        


                REQUIRE(expectedScore1 == score1);
                REQUIRE(expectedScore2 == score2);
                REQUIRE(expectedScore3 == score3);
                REQUIRE(expectedScore4 == score4);
                REQUIRE(expectedScore5 == score5);
            }
        }
    }
}

SCENARIO("Testing complex configurations", "[int][string][complex]"){

    GIVEN("Complex configurations are present"){
        std::string Configuration1 = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
        std::string Configuration2 = "25|31|11|6/|51|1/|26|33|22|1-||";
        std::string Configuration3 = "5-|5/|22|3-|6-|8/|9/|15|51|52||";
        std::string Configuration4 = "X|X|32|22|5/|3-|3-|62|8/|5/||2";
        std::string Configuration5 = "71|72|7/|2/|71|54|42|5/|13|X||25";


        

        WHEN("Round is finished, scores are as follows:"){
            int score1 = 167;
            int score2 = 7+4+2+15+6+12+8+6+4+1;
            int score3 = 5+12+4+3+5+19+11+6+6+7;
            int score4 = 25+19+5+4+13+3+3+8+15+12+2;
            int score5 = 8+9+12+17+8+9+6+11+4+17+2+5;

            THEN("Result score for such configuration should be:"){
                std::string expectedConfiguration1 = "X|7/|9-|X|-8|8/|-6|X|X|X||81";
                std::string expectedConfiguration2 = "25|31|11|6/|51|1/|26|33|22|1-||";
                std::string expectedConfiguration3 = "5-|5/|22|3-|6-|8/|9/|15|51|52||";
                std::string expectedConfiguration4 = "X|X|32|22|5/|3-|3-|62|8/|5/||2";
                std::string expectedConfiguration5 = "71|72|7/|2/|71|54|42|5/|13|X||25";

                int expectedScore1 = 167;
                int expectedScore2 = 65;
                int expectedScore3 = 78;
                int expectedScore4 = 109;
                int expectedScore5 = 108;
                
                REQUIRE(expectedConfiguration1 == Configuration1);
                REQUIRE(expectedConfiguration2 == Configuration2);
                REQUIRE(expectedConfiguration3 == Configuration3);
                REQUIRE(expectedConfiguration4 == Configuration4);
                REQUIRE(expectedConfiguration5 == Configuration5);
        


                REQUIRE(expectedScore1 == score1);
                REQUIRE(expectedScore2 == score2);
                REQUIRE(expectedScore3 == score3);
                REQUIRE(expectedScore4 == score4);
                REQUIRE(expectedScore5 == score5);
            }
        }
    }
}

SCENARIO("Additional score testing", "[int][string][score]"){

    GIVEN("Scores at specific bowling lane are given"){
    auto score = {60,90,110,115,250,300,123,154};

            THEN("Expected read scores from whole bowling lane:"){

                REQUIRE_THAT(score, Catch::Matchers::Contains(60));
                REQUIRE_THAT(score, Catch::Matchers::Contains(90));
                REQUIRE_THAT(score, Catch::Matchers::Contains(110));
                REQUIRE_THAT(score, Catch::Matchers::Contains(115));
                REQUIRE_THAT(score, Catch::Matchers::Contains(250));
                REQUIRE_THAT(score, Catch::Matchers::Contains(300));
                REQUIRE_THAT(score, Catch::Matchers::Contains(123));
                REQUIRE_THAT(score, Catch::Matchers::Contains(154));
            }
        }
    }