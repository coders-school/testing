#include "catch.hpp"

SCENARIO("frame tests", "[frames]") {
    GIVEN("start a frame") {
        WHEN("player is before first throw in a frame") {
            THEN("points and throws in this frame == 0") {
            }
        }
    }
    GIVEN("throws: 10, 3, 4, 10, 5, 5, 1") {
        WHEN("actual frame is calculating") {
            THEN("return frame number == 5") {
            }
        }
    }
    GIVEN("player make a first move") {
        WHEN("player knocks down all pins, strike") {
            THEN("end frame") {
            }
        }
    }
    GIVEN("before player a first move") {
        WHEN("pins count == 10 and has 2 ball") {
            THEN("begin a frame") {
            }
        }
    }
    GIVEN("before frame ended by spare and player make a new frame") {
        WHEN("player got points") {
            THEN("plus points by spare to first ball") {
            }
        }
    }
    GIVEN("an completed game") {
        WHEN("frames are calculating") {
            THEN("number of frames == 10") {
            }
        }
    }
     GIVEN("last 10th frame") {
        WHEN("player throw a spare") {
            THEN("player has one more bonus ball") {
            }
        }
    }
     GIVEN("last 10th frame") {
        WHEN("player throw a strike") {
            THEN("player has two more bonus balls") {
            }
        }
    }
}

SCENARIO("throw tests", "[throws]") {
    GIVEN("player makes a move / frame started") {
        WHEN("player already made 2 throws") {
            THEN("point count for this frame is <= 20") {
            }
        }
    }
    GIVEN("10 points in first throw") {
        WHEN("player already made one throw") {
            THEN("end frame with only one throw") {
            }
        }
    }
    GIVEN("player makes second move") {
        WHEN("player knocks down 10 pins in total") {
            THEN("return spare") {
            }
        }
    }
    GIVEN("start frame") {
        WHEN("player start new frame") {
            THEN("player has 2 throw") {
            }
        }
    }
    GIVEN("player makes a one throw") {
        WHEN("player throw first ball") {
            THEN("player has 1 throw") {
            }
        }
    }
    GIVEN("player makes a second throw") {
        WHEN("player throw second ball") {
            THEN("player has 0 throw") {
            }
        }
    }
}

SCENARIO("the frame end after spare", "[frames]") {
    GIVEN("player make second move") {
        WHEN("player knocks down all pins") {
            THEN("pins is 0") {
            }
        }
    }   
}

SCENARIO("if knocking down 10 pins", "[frames]") {
    GIVEN("player make first move") {
        WHEN("player knocks down all pins") {
            THEN("all 10 pins down") {
            }
        }
    }
    GIVEN("player make first move") {
        WHEN("player knocks all pins in first move") {
            THEN("player has a strike") {
            }
        }
    }
}

SCENARIO("points test", "[points]") {
    GIVEN("2 throws: 2, 5 (not a strike nor a spare)") {
        WHEN("points are calculating") {
            THEN("points in frame == 7") {
            }
        }
    }
    GIVEN("3 throws: first strike, and then: 2, 3") {
        WHEN("points are calculating") {
            THEN("points after two frames should be 20") {
            }
        }
    }
    GIVEN("an ended (completed) game") {
        WHEN("points are calculating") {
            THEN("overall score should be a total of all frame scores") {
            }
        }
    }
    GIVEN("spare in a bonus ball") {
        WHEN("last frame is adding to overall score") {
            THEN("overall score shouldn't be increase by extra points for spare") {
            }
        }
    }
    GIVEN("strike in a bonus ball") {
        WHEN("last frame is adding to overall score") {
            THEN("overall score shouldn't be increase by extra points for strike") {
            }
        }
    }
}
