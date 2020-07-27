#include "catch.hpp"

SCENARIO("frame tests", "[frames]") {
    GIVEN("throws: 10, 3, 4, 10, 5, 5, 1") {
        WHEN("actual frame is calculating") {
            THEN("return frame number == 5") {
            }
        }
    }
}

SCENARIO("throw tests", "[throws]") {
    GIVEN("player makes a move / frame started") {
        WHEN("player already made 2 throws") {
            THEN("point count for this frame is <= 20") {}
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
