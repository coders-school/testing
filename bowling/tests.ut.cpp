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

    GIVEN("Before player a first move") {
        WHEN("Pins count == 10 and has 2 ball") {
            THEN("Begin a frame") {
            }
        }
    }

    GIVEN("Before frame ended by spare nad Player make a new frame") {
        WHEN("Player got points") {
            THEN("plus points by spare to first ball") {
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
        WHEN("player knocks down 10 pins") {
            THEN("return spare") {
            }
        }
    }
}

SCENARIO("The frame end after spare", "[frames]") {
    GIVEN("player make second move") {
        WHEN("player knocks down all pins") {
            THEN("pins is 0") {
            }
        }
    }
}

SCENARIO("If knocking down 10 pins", "[frames]") {
    GIVEN("player make first move") {
        WHEN("player knocks down all pins") {
            THEN("all 10 pins down") {
            }
        }
    }
    GIVEN("player make first move") {
        WHEN("player koocks all pins in first move") {
            THEN("player got strike") {
            }
        }
    }
}
