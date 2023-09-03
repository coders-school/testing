#include <catch2/catch_all.hpp>
#include "bowling_game.hpp" 

SCENARIO("Testing all possible bowling game scenarios") {
    GIVEN( "The game has started" ) {
        BowlingGame game;
        game.start();

        WHEN("All frames are strikes") {
            for (int i = 0; i < 12; i++) {
                game.roll(10);
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|X|X|X|X|X|X|X|X|X||XX'") {
                REQUIRE(gameString == "X|X|X|X|X|X|X|X|X|X||XX");
            }
            AND_THEN("The calculated score should be 300") {
                REQUIRE(game.calculateScore() == 300);
            }
        }

        WHEN("All frames are spares") {
            for (int i = 0; i < 21; i++) {
                game.roll(5);
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5'") {
                REQUIRE(gameString == "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5");
            }
            AND_THEN("The calculated score should be 150") {
                REQUIRE(game.calculateScore() == 150);
            }
        }

        WHEN("All rolls miss all pins") {
            for (int i = 0; i < 20; i++) {
                game.roll(0);
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '--|--|--|--|--|--|--|--|--|--||'") {
                REQUIRE(gameString == "--|--|--|--|--|--|--|--|--|--||");
            }
            AND_THEN("The calculated score should be 0") {
                REQUIRE(game.calculateScore() == 0);
            }
        }

        WHEN("Mixed strikes, spares, and misses") {
            game.roll(10);
            game.roll(7);
            game.roll(3);
            game.roll(9);
            game.roll(0);
            game.roll(10);
            game.roll(0);
            game.roll(8);
            game.roll(8);
            game.roll(2);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(10);
            game.roll(10);
            game.roll(9);
            game.roll(1);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|7/|9-|X|-8|8/|5/|X|X|X||91'") {
                REQUIRE(gameString == "X|7/|9-|X|-8|8/|5/|X|X|X||91");
            }
            AND_THEN("The calculated score should be 188") {
                REQUIRE(game.calculateScore() == 188);
            }
        }

        WHEN("All frames are gutter balls") {
            for (int i = 0; i < 20; i++) {
                game.roll(0);
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||'") {
                REQUIRE(gameString == "9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||");
            }
            AND_THEN("The calculated score should be 90") {
                REQUIRE(game.calculateScore() == 90);
            }
        }

        WHEN("All frames are strikes except the last frame is a spare") {
            for (int i = 0; i < 9; i++) {
                game.roll(10);
            }
            game.roll(9);
            game.roll(1);
            game.roll(1);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|X|X|X|X|X|X|X|X|9/||1'") {
                REQUIRE(gameString == "X|X|X|X|X|X|X|X|X|9/||1");
            }
            AND_THEN("The calculated score should be 270") {
                REQUIRE(game.calculateScore() == 270);
            }
        }

        WHEN("All frames are spares except the last frame is a strike") {
            for (int i = 0; i < 9; i++) {
                game.roll(5);
                game.roll(5);
            }
            game.roll(10);
            game.roll(1);
            game.roll(1);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|5/|5/|5/|5/|5/|5/|5/|5/|X||11'") {
                REQUIRE(gameString == "5/|5/|5/|5/|5/|5/|5/|5/|5/|X||11");
            }
            AND_THEN("The calculated score should be 152") {
                REQUIRE(game.calculateScore() == 152);
            }
        }

        WHEN("All frames are misses except the last frame is a strike") {
            for (int i = 0; i < 9; i++) {
                game.roll(0);
                game.roll(0);
            }
            game.roll(10);
            game.roll(5);
            game.roll(4);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '--|--|--|--|--|--|--|--|--|X||54'") {
                REQUIRE(gameString == "--|--|--|--|--|--|--|--|--|X||54");
            }
            AND_THEN("The calculated score should be 19") {
                REQUIRE(game.calculateScore() == 19);
            }
        }

        WHEN("Frames alternate between strikes and misses") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(10);
                } else {
                    game.roll(0);
                    game.roll(0);
                }
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|--|X|--|X|--|X|--|X|--||'") {
                REQUIRE(gameString == "X|--|X|--|X|--|X|--|X|--||");
            }
            AND_THEN("The calculated score should be 50") {
                REQUIRE(game.calculateScore() == 50);
            }
        }

        WHEN("Frames alternate between spares and misses") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(5);
                    game.roll(5);
                } else {
                    game.roll(0);
                    game.roll(0);
                }
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|--|5/|--|5/|--|5/|--|5/|--||'") {
                REQUIRE(gameString == "5/|--|5/|--|5/|--|5/|--|5/|--||");
            }
            AND_THEN("The calculated score should be 50") {
                REQUIRE(game.calculateScore() == 50);
            }
        }

        WHEN("Frames have random scores") {
            game.roll(3);
            game.roll(6);
            game.roll(8);
            game.roll(1);
            game.roll(10);
            game.roll(2);
            game.roll(4);
            game.roll(9);
            game.roll(0);
            game.roll(6);
            game.roll(3);
            game.roll(7);
            game.roll(1);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(8);
            game.roll(2);
            game.roll(10);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '36|81|X|24|9-|63|71|5/|X|82||X'") {
                REQUIRE(gameString == "36|81|X|24|9-|63|71|5/|X|82||X");
            }
            AND_THEN("The calculated score should be 106") {
                REQUIRE(game.calculateScore() == 106);
            }
        }

        WHEN("Mixed strikes, spares, and misses with bonus strikes") {
            game.roll(10);
            game.roll(7);
            game.roll(3);
            game.roll(9);
            game.roll(0);
            game.roll(10);
            game.roll(0);
            game.roll(8);
            game.roll(8);
            game.roll(2);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(10);
            game.roll(10);
            game.roll(10); 
            game.roll(10);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|7/|9-|X|-8|8/|5/|X|X|X||XX'") {
                REQUIRE(gameString == "X|7/|9-|X|-8|8/|-6|X|X|X||XX");
            }
            AND_THEN("The calculated score should be 180") {
                REQUIRE(game.calculateScore() == 180);
            }
        }

        WHEN("Random frames scores with a bonus spare in the last frame") {
            game.roll(3);
            game.roll(6);
            game.roll(8);
            game.roll(1);
            game.roll(10);
            game.roll(2);
            game.roll(4);
            game.roll(9);
            game.roll(0);
            game.roll(6);
            game.roll(3);
            game.roll(7);
            game.roll(1);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(5);
            game.roll(5);
            game.roll(5);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '36|81|X|24|9-|63|71|5/|X|5/||5'") {
                REQUIRE(gameString == "36|81|X|24|9-|63|71|5/|X|5/||5");
            }
            AND_THEN("The calculated score should be 121") {
                REQUIRE(game.calculateScore() == 121);
            }
        }

        WHEN("Random frames scores with a bonus strike in the last frame") {
            game.roll(3);
            game.roll(6);
            game.roll(8);
            game.roll(1);
            game.roll(10);
            game.roll(2);
            game.roll(4);
            game.roll(9);
            game.roll(0);
            game.roll(6);
            game.roll(3);
            game.roll(7);
            game.roll(1);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(10); 
            game.roll(10);
            game.roll(10); 
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '36|81|X|24|9-|63|71|5/|X|X||XX'") {
                REQUIRE(gameString == "36|81|X|24|9-|63|71|5/|X|X||XX");
            }
            AND_THEN("The calculated score should be 146") {
                REQUIRE(game.calculateScore() == 146);
            }
        }

        WHEN("All frames are strikes with a bonus spare in the last frame") {
            for (int i = 0; i < 11; i++) {
                game.roll(10);
            }
            game.roll(5);
            game.roll(5);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|X|X|X|X|X|X|X|X|X||5/'") {
                REQUIRE(gameString == "X|X|X|X|X|X|X|X|X|X||5/");
            }
            AND_THEN("The calculated score should be 285") {
                REQUIRE(game.calculateScore() == 285);
            }
        }

        WHEN("All frames are spares with a bonus strike in the last frame") {
            for (int i = 0; i < 10; i++) {
                game.roll(5);
                game.roll(5);
            }
            game.roll(10);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||X'") {
                REQUIRE(gameString == "5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||X");
            }
            AND_THEN("The calculated score should be 155") {
                REQUIRE(game.calculateScore() == 155);
            }
        }

        WHEN("All frames are misses with a bonus spare in the last frame") {
            for (int i = 0; i < 9; i++) {
                game.roll(0);
                game.roll(0);
            }
            game.roll(0);
            game.roll(10);
            game.roll(5);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '--|--|--|--|--|--|--|--|--|-/||5'") {
                REQUIRE(gameString == "--|--|--|--|--|--|--|--|--|-/||5");
            }
            AND_THEN("The calculated score should be 15") {
                REQUIRE(game.calculateScore() == 15);
            }
        }

        WHEN("Random frames scores with a bonus strike in the last frame") {
            game.roll(3);
            game.roll(6);
            game.roll(8);
            game.roll(1);
            game.roll(10);
            game.roll(2);
            game.roll(4);
            game.roll(9);
            game.roll(0);
            game.roll(6);
            game.roll(3);
            game.roll(7);
            game.roll(1);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(10);
            game.roll(10);
            game.roll(10);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '36|81|X|24|9-|63|71|5/|X|X||XX'") {
                REQUIRE(gameString == "36|81|X|24|9-|63|71|5/|X|X||XX");
            }
            AND_THEN("The calculated score should be 146") {
                REQUIRE(game.calculateScore() == 146);
            }
        }

        WHEN("Frames alternate between strikes and spares") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(10);
                } else {
                    game.roll(5);
                    game.roll(5);
                }
            }
            game.roll(10);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|5/|X|5/|X|5/|X|5/|X|5/||X'") {
                REQUIRE(gameString == "X|5/|X|5/|X|5/|X|5/|X|5/||X");
            }
            AND_THEN("The calculated score should be 200") {
                REQUIRE(game.calculateScore() == 200);
            }
        }

        WHEN("Frames alternate between strikes and misses") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(10);
                } else {
                    game.roll(0);
                    game.roll(0);
                }
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|--|X|--|X|--|X|--|X|--||'") {
                REQUIRE(gameString == "X|--|X|--|X|--|X|--|X|--||");
            }
            AND_THEN("The calculated score should be 50") {
                REQUIRE(game.calculateScore() == 50);
            }
        }

        WHEN("Frames alternate between spares and strikes") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(5);
                    game.roll(5);
                } else {
                    game.roll(10);
                }
            }
            game.roll(5);
            game.roll(5);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|X|5/|X|5/|X|5/|X|5/|X||5/'") {
                REQUIRE(gameString == "5/|X|5/|X|5/|X|5/|X|5/|X||5/");
            }
            AND_THEN("The calculated score should be 200") {
                REQUIRE(game.calculateScore() == 200);
            }
        }

        WHEN("Frames alternate between spares and misses") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(5);
                    game.roll(5);
                } else {
                    game.roll(0);
                    game.roll(0);
                }
            }
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|--|5/|--|5/|--|5/|--|5/|--||'") {
                REQUIRE(gameString == "5/|--|5/|--|5/|--|5/|--|5/|--||");
            }
            AND_THEN("The calculated score should be 50") {
                REQUIRE(game.calculateScore() == 50);
            }
        }

        WHEN("Frames alternate between misses and strikes") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(0);
                    game.roll(0);
                } else {
                    game.roll(10);
                }
            }
            game.roll(0);
            game.roll(0);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '--|X|--|X|--|X|--|X|--|X||--'") {
                REQUIRE(gameString == "--|X|--|X|--|X|--|X|--|X||--");
            }
            AND_THEN("The calculated score should be 50") {
                REQUIRE(game.calculateScore() == 50);
            }
        }

        WHEN("Frames alternate between misses and spares") {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    game.roll(0);
                    game.roll(0);
                } else {
                    game.roll(5);
                    game.roll(5);
                }
            }
            game.roll(0);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '--|5/|--|5/|--|5/|--|5/|--|5/||-'") {
                REQUIRE(gameString == "--|5/|--|5/|--|5/|--|5/|--|5/||-");
            }
            AND_THEN("The calculated score should be 50") {
                REQUIRE(game.calculateScore() == 50);
            }
        }

        WHEN("Random frames scores with all strikes in the last frame") {
            for (int i = 0; i < 9; i++) {
                game.roll(3);
                game.roll(6);
            }
            game.roll(10);
            game.roll(10);
            game.roll(10);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '36|36|36|36|36|36|36|36|36|X||XX'") {
                REQUIRE(gameString == "36|36|36|36|36|36|36|36|36|X||XX");
            }
            AND_THEN("The calculated score should be 111") {
                REQUIRE(game.calculateScore() == 111);
            }
        }

        WHEN("Random frames scores with all spares in the last frame") {
            for (int i = 0; i < 9; i++) {
                game.roll(3);
                game.roll(6);
            }
            game.roll(5);
            game.roll(5);
            game.roll(5);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '36|36|36|36|36|36|36|36|36|5/||5'") {
                REQUIRE(gameString == "36|36|36|36|36|36|36|36|36|5/||5");
            }
            AND_THEN("The calculated score should be 96") {
                REQUIRE(game.calculateScore() == 96);
            }
        }

        WHEN("Random frames scores with all misses in the last frame") {
            for (int i = 0; i < 9; i++) {
                game.roll(3);
                game.roll(6);
            }
            game.roll(0);
            game.roll(0); 
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '36|36|36|36|36|36|36|36|36|--||'") {
                REQUIRE(gameString == "36|36|36|36|36|36|36|36|36|--||");
            }
            AND_THEN("The calculated score should be 81") {
                REQUIRE(game.calculateScore() == 81);
            }
        }

        WHEN("Random frames scores with all strikes except the last frame is a spare") {
            for (int i = 0; i < 9; i++) {
                game.roll(10);
            }
            game.roll(9);
            game.roll(1);
            game.roll(5); 
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be 'X|X|X|X|X|X|X|X|X|9/||5'") {
                REQUIRE(gameString == "X|X|X|X|X|X|X|X|X|9/||5");
            }
            AND_THEN("The calculated score should be 274") {
                REQUIRE(game.calculateScore() == 274);
            }
        }

        WHEN("Random frames scores with all spares except the last frame is a strike") {
            for (int i = 0; i < 9; i++) {
                game.roll(5);
                game.roll(5);
            }
            game.roll(10);
            game.roll(5); 
            game.roll(5);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|5/|5/|5/|5/|5/|5/|5/|5/|X||55'") {
                REQUIRE(gameString == "5/|5/|5/|5/|5/|5/|5/|5/|5/|X||55");
            }
            AND_THEN("The calculated score should be 160") {
                REQUIRE(game.calculateScore() == 160);
            }
        }

        WHEN("Random frames scores with spares and strikes with bonus strikes") {
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(7);
            game.roll(3);
            game.roll(9);
            game.roll(0);
            game.roll(10);
            game.roll(0);
            game.roll(8);
            game.roll(8);
            game.roll(2);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(10);
            game.roll(10);
            game.roll(10);
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            std::string gameString = game.generateGameString();
            AND_THEN("The generated string should be '5/|X|7/|9-|X|-8|8/|-6|X|X||XX'") {
                REQUIRE(gameString == "5/|X|7/|9-|X|-8|8/|-6|X|X||XX");
            }
            AND_THEN("The calculated score should be 170") {
                REQUIRE(game.calculateScore() == 170);
            }
        }

        WHEN("Random frames scores with strikes and spares with bonus spares") {
            game.roll(10);
            game.roll(7);
            game.roll(3);
            game.roll(9);
            game.roll(0);
            game.roll(10);
            game.roll(0);
            game.roll(8);
            game.roll(8);
            game.roll(2);
            game.roll(5);
            game.roll(5);
            game.roll(10);
            game.roll(5);
            game.roll(5);
            std::string gameString = game.generateGameString();
            THEN("The game must be over") {
                REQUIRE(game.isOver() == true);
            }
            AND_THEN("The generated string should be 'X|7/|9-|X|-8|8/|-6|X|X|X||5/'") {
                REQUIRE(gameString == "X|7/|9-|X|-8|8/|-6|X|X|X||5/");
            }
            AND_THEN("The calculated score should be 165") {
                REQUIRE(game.calculateScore() == 165);
            }
        }
}

SCENARIO("Negative Test Cases") {
    GIVEN( "The game has started" ) {
        BowlingGame game;
        game.start();

        WHEN("Random frames scores") {
            game.roll(10);
            game.roll(7);

            std::string gameString = game.generateGameString();
            THEN("The game must not be over") {
                REQUIRE(game.isOver() == false);
            }
        }

        WHEN("Random frames scores") {
            game.roll(10);
            game.roll(7);

            std::string gameString = game.generateGameString();
            THEN("The game must not be over") {
                REQUIRE_THROWS(calculateScore());
            }
        }
    }
}
