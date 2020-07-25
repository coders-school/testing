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
