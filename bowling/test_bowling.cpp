#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>


SCENARIO ("Check if each frame works with miss state") { // 1
    GIVEN ("Score board frame state") {
        auto state = GENERATE ( "-|1-|1-|1-|1-|1-|1-|1-|1-|1-|",
                                "1-|-|1-|1-|1-|1-|1-|1-|1-|1-|"
                                "1-|1-|-|1-|1-|1-|1-|1-|1-|1-|"
                                "1-|1-|1-|-|1-|1-|1-|1-|1-|1-|"
                                "1-|1-|1-|1-|-|1-|1-|1-|1-|1-|"
                                "1-|1-|1-|1-|1-|-|1-|1-|1-|1-|"
                                "1-|1-|1-|1-|1-|1-|-|1-|1-|1-|"
                                "1-|1-|1-|1-|1-|1-|1-|-|1-|1-|"
                                "1-|1-|1-|1-|1-|1-|1-|1-|-|1-|"
                                "1-|1-|1-|1-|1-|1-|1-|1-|1-|-|"
        );
        WHEN ("Frame state check is called") {
            THEN ("state == false") {
            }
        }
    }
}

SCENARIO ("Check if each frame works with spare state / frame 10 with additional ball MISS") { // 2
    GIVEN ("Score board frame state") {
        auto state = GENERATE ( "1/|-|-|-|-|-|-|-|-|-|",
                                "-|1/|-|-|-|-|-|-|-|-|"
                                "-|-|1/|-|-|-|-|-|-|-|"
                                "-|-|-|1/|-|-|-|-|-|-|"
                                "-|-|-|-|1/|-|-|-|-|-|"
                                "-|-|-|-|-|1/|-|-|-|-|"
                                "-|-|-|-|-|-|1/|-|-|-|"
                                "-|-|-|-|-|-|-|1/|-|-|"
                                "-|-|-|-|-|-|-|-|1/|-|"
                                "-|-|-|-|-|-|-|-|-|1/|-"
        );
        WHEN ("Frame state check is called") {
            THEN ("state == true") {
            }
        }
    }
}

SCENARIO ("Check if each frame works with strike state / frame 10 with additional 2 balls MISS") { // 3
    GIVEN ("Score board state") {
        auto state = GENERATE ( "X|-|-|-|-|-|-|-|-|-|",
                                "-|X|-|-|-|-|-|-|-|-|"
                                "-|-|X|-|-|-|-|-|-|-|"
                                "-|-|-|X|-|-|-|-|-|-|"
                                "-|-|-|-|X|-|-|-|-|-|"
                                "-|-|-|-|-|X|-|-|-|-|"
                                "-|-|-|-|-|-|X|-|-|-|"
                                "-|-|-|-|-|-|-|X|-|-|"
                                "-|-|-|-|-|-|-|-|X|-|"
                                "-|-|-|-|-|-|-|-|-|X|--"
        );
        WHEN ("Frame state check is called") {
            THEN ("state == true") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads score from each frame - 1 point and MISS ") { // 4
        GIVEN ("Score") {
        auto score = GENERATE ( "1-|-|-|-|-|-|-|-|-|-|",
                                "-|1-|-|-|-|-|-|-|-|-|"
                                "-|-|1-|-|-|-|-|-|-|-|"
                                "-|-|-|1-|-|-|-|-|-|-|"
                                "-|-|-|-|1-|-|-|-|-|-|"
                                "-|-|-|-|-|1-|-|-|-|-|"
                                "-|-|-|-|-|-|1-|-|-|-|"
                                "-|-|-|-|-|-|-|1-|-|-|"
                                "-|-|-|-|-|-|-|-|1-|-|"
                                "-|-|-|-|-|-|-|-|-|1-|"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 1") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads score from each frame -  MISS and 1 point ") { // 5
    GIVEN ("Score") {
        auto score = GENERATE ( "-1|-|-|-|-|-|-|-|-|-|",
                                "-|-1|-|-|-|-|-|-|-|-|"
                                "-|-|-1|-|-|-|-|-|-|-|"
                                "-|-|-|-1|-|-|-|-|-|-|"
                                "-|-|-|-|-1|-|-|-|-|-|"
                                "-|-|-|-|-|-1|-|-|-|-|"
                                "-|-|-|-|-|-|-1|-|-|-|"
                                "-|-|-|-|-|-|-|-1|-|-|"
                                "-|-|-|-|-|-|-|-|-1|-|"
                                "-|-|-|-|-|-|-|-|-|-1|"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 1") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads score from each frame - 1 point and MISS") { //6
    GIVEN ("Score") {
        auto score = GENERATE ( "X|1-|-|-|-|-|-|-|-|-|",
                                "-|X|1-|-|-|-|-|-|-|-|"
                                "-|-|X|1-|-|-|-|-|-|-|"
                                "-|-|-|X|1-|-|-|-|-|-|"
                                "-|-|-|-|X|1-|-|-|-|-|"
                                "-|-|-|-|-|X|1-|-|-|-|"
                                "-|-|-|-|-|-|X|1-|-|-|"
                                "-|-|-|-|-|-|-|X|1-|-|"
                                "-|-|-|-|-|-|-|-|X|1-|"
                                "-|-|-|-|-|-|-|-|-|X|1-"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 11") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads score from each frame - 1 point and MISS") { //6
    GIVEN ("Score") {
        auto score = GENERATE ( "X|1-|-|-|-|-|-|-|-|-|",
                                "-|X|1-|-|-|-|-|-|-|-|"
                                "-|-|X|1-|-|-|-|-|-|-|"
                                "-|-|-|X|1-|-|-|-|-|-|"
                                "-|-|-|-|X|1-|-|-|-|-|"
                                "-|-|-|-|-|X|1-|-|-|-|"
                                "-|-|-|-|-|-|X|1-|-|-|"
                                "-|-|-|-|-|-|-|X|1-|-|"
                                "-|-|-|-|-|-|-|-|X|1-|"
                                "-|-|-|-|-|-|-|-|-|X|1-"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 11") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads SPARE state from frame and add score from next ball(1 point and MISS)") { // 7
    GIVEN ("Score") {
        auto score = GENERATE ( "1/|1-|-|-|-|-|-|-|-|-|",
                                "-|1/|1-|-|-|-|-|-|-|-|"
                                "-|-|1/|1-|-|-|-|-|-|-|"
                                "-|-|-|1/|1-|-|-|-|-|-|"
                                "-|-|-|-|1/|1-|-|-|-|-|"
                                "-|-|-|-|-|1/|1-|-|-|-|"
                                "-|-|-|-|-|-|1/|1-|-|-|"
                                "-|-|-|-|-|-|-|1/|1-|-|"
                                "-|-|-|-|-|-|-|-|1/|1-|"
                                "-|-|-|-|-|-|-|-|-|1/|1"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 11") {
            }
        }
    }
}


SCENARIO ("Check if points calculation function reads SPARE state from frame and add score from next ball(miss and 1 point - except frame 10") { // 8
    GIVEN ("Score") {
        auto score = GENERATE ( "1/|-1|-|-|-|-|-|-|-|-|",
                                "-|1/|-1|-|-|-|-|-|-|-|"
                                "-|-|1/|-1|-|-|-|-|-|-|"
                                "-|-|-|1/|-1|-|-|-|-|-|"
                                "-|-|-|-|1/|-1|-|-|-|-|"
                                "-|-|-|-|-|1/|-1|-|-|-|"
                                "-|-|-|-|-|-|1/|-1|-|-|"
                                "-|-|-|-|-|-|-|1/|-1|-|"
                                "-|-|-|-|-|-|-|-|1/|-1|"
                                "-|-|-|-|-|-|-|-|-|1/|1"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 11") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads SPARE state from 10 frame - additional ball miss") { // 9
    GIVEN ("-|-|-|-|-|-|-|-|-|1/|-") {
        WHEN ("Score calculation function is called") {
            THEN ("Points = 10") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads STRIKE state from frame and add score from next 2 balls(1 point and 1 point") { // 10
    GIVEN ("Score") {
        auto score = GENERATE ( "X|11|-|-|-|-|-|-|-|-|",
                                "-|X|11|-|-|-|-|-|-|-|"
                                "-|-|X|11|-|-|-|-|-|-|"
                                "-|-|-|X|11|-|-|-|-|-|"
                                "-|-|-|-|X|11|-|-|-|-|"
                                "-|-|-|-|-|X|11|-|-|-|"
                                "-|-|-|-|-|-|X|11|-|-|"
                                "-|-|-|-|-|-|-|X|11|-|"
                                "-|-|-|-|-|-|-|-|X|11|"
                                "-|-|-|-|-|-|-|-|-|X|11"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 12") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads STRIKE state from frame and add score from next 2 balls( MISS and 1 point") { // 11
    GIVEN ("Score") {
        auto score = GENERATE ( "X|-1|-|-|-|-|-|-|-|-|",
                                "-|X|-1|-|-|-|-|-|-|-|"
                                "-|-|X|-1|-|-|-|-|-|-|"
                                "-|-|-|X|-1|-|-|-|-|-|"
                                "-|-|-|-|X|-1|-|-|-|-|"
                                "-|-|-|-|-|X|-1|-|-|-|"
                                "-|-|-|-|-|-|X|-1|-|-|"
                                "-|-|-|-|-|-|-|X|-1|-|"
                                "-|-|-|-|-|-|-|-|X|-1|"
                                "-|-|-|-|-|-|-|-|-|X|-1"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 11") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads STRIKE state from frame and add score from next 2 balls( 1 point and MISS") { // 12
    GIVEN ("Score") {
        auto score = GENERATE ( "X|1-|-|-|-|-|-|-|-|-|",
                                "-|X|1-|-|-|-|-|-|-|-|"
                                "-|-|X|1-|-|-|-|-|-|-|"
                                "-|-|-|X|1-|-|-|-|-|-|"
                                "-|-|-|-|X|1-|-|-|-|-|"
                                "-|-|-|-|-|X|1-|-|-|-|"
                                "-|-|-|-|-|-|X|1-|-|-|"
                                "-|-|-|-|-|-|-|X|1-|-|"
                                "-|-|-|-|-|-|-|-|X|1-|"
                                "-|-|-|-|-|-|-|-|-|X|1-"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 11") {
            }
        }
    }
}

SCENARIO ("Check if points calculation function reads STRIKE state from frame and add score from next 2 balls( MISS and MISS") { // 13
    GIVEN ("Score") {
        auto score = GENERATE ( "X|-|-|-|-|-|-|-|-|-|",
                                "-|X|-|-|-|-|-|-|-|-|"
                                "-|-|X|-|-|-|-|-|-|-|"
                                "-|-|-|X|-|-|-|-|-|-|"
                                "-|-|-|-|X|-|-|-|-|-|"
                                "-|-|-|-|-|X|-|-|-|-|"
                                "-|-|-|-|-|-|X|-|-|-|"
                                "-|-|-|-|-|-|-|X|-|-|"
                                "-|-|-|-|-|-|-|-|X|-|"
                                "-|-|-|-|-|-|-|-|-|X|--"
        );
        WHEN ("Score calculation function is called") {
            THEN ("score == 10") {
            }
        }
    }
}

SCENARIO ("Check calculation function - every frame is miss / point ") { // 14
    GIVEN ("-2|-2|-2|-2|-2|-2|-2|-2|-2|-2|") {
        WHEN ("Points calculation is called") {
            THEN ("score = 20") {
            }
        }
    }
}

SCENARIO ("Check calculation function - every frame is miss / point ") { // 15
    GIVEN ("3-|3-|3-|3-|3-|3-|3-|3-|3-|3-|") {
        WHEN ("Points calculation is called") {
            THEN ("score = 30") {
            }
        }
    }
}

SCENARIO ("Check calculation function - every frame is strike ") { // 16
    GIVEN ("X|X|X|X|X|X|X|X|X|X|XX") {
        WHEN ("Points calculation is called") {
            THEN ("score = 300") {
            }
        }
    }
}

SCENARIO ("Check calculation function - every frame have spare state - frame 10 addtional ball - 1 point") { // 17
    GIVEN ("1/|1/|1/|1/|1/|1/|1/|1/|1/|1/|1") {
        WHEN ("Points calculation is called") {
            THEN ("Points = 111") {
            }
        }
    }
}

SCENARIO ("Check calculation function - every frame is miss ") { // 18
    GIVEN ("-|-|-|-|-|-|-|-|-|-|") {
        WHEN ("Points calculation is called") {
            THEN ("score = 0") {
            }
        }
    }
}

SCENARIO ("Check calculation function - all states ") { // 19
    GIVEN ("X|7/|9-|X|-8|8/|-6|X|X|X||81") {
        WHEN ("Points calculation is called") {
            THEN ("score = 167") {
            }
        }
    }
}

SCENARIO ("Rounds less than 10") { // 20
    GIVEN ("round_num = 1"){
        WHEN("Calculatio function is called") {
            THEN ("ErrorCode::NotEnoughRounds"){

            }
        }
    }
}

SCENARIO ("Rounds over 10") { // 21
    GIVEN ("round_num = 11"){
        WHEN("Calculatio function is called") {
            THEN ("ErrorCode::ToManyRounds"){

            }
        }
    }
}

SCENARIO ("Additional balls amount - 10 frame - strike") { // 22
    GIVEN ("additional_balls_num = 3"){
        WHEN("Calculatio function is called") {
            THEN ("ErrorCode::ToManyBalls"){
            }
        }
    }
}

SCENARIO ("Additional balls amount - 10 frame - strike") { // 23
    GIVEN ("additional_balls_num = 1"){
        WHEN("Calculatio function is called") {
            THEN ("ErrorCode::NotEnoughBalls"){
            }
        }
    }
}

SCENARIO ("Additional balls amount - 10 frame - spare") { // 24
    GIVEN ("additional_balls_num = 2"){
        WHEN("Calculatio function is called") {
            THEN ("ErrorCode::ToManyBalls"){
            }
        }
    }
}
