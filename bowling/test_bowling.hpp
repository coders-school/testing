#define CATCH_CONFIG_MAIN
#include "catch.hpp"
// sunny day scenarios
//
GIVEN("No ball played in first frame") {
  WHEN("first ball in a frame knocks down 5 pins") {
    THEN("The frame is not over. Another ball can be played ") {}
  }
}

GIVEN("First ball played and knocks down 0 pins") {
  WHEN("Second ball played and knocks down 10 pins") {
    THEN("The frame is over. First frame includes spare") {}
  }
}

GIVEN("First ball played and knocks down 1 pins") {
  WHEN("Second ball played and knocks down 1 pins") {
    THEN("The frame is over. ") { CHECK("Score for frame is 2") }
  }
}

GIVEN("First ball played and knocks down 0 pins") {
  WHEN("Second ball played and knocks down 0 pins") {
    THEN("The frame is over. ") { CHECK("Score for frame is 0") }
  }
}

GIVEN("First ball knocks down 0, second ball knocks down 10 pins, first frame "
      "is over") {
  WHEN("Second frame played with 9 score") {
    THEN("First frame is a 'spare'.") { CHECK("score for first frame is 19") }
  }
}

GIVEN("First ball in first frame knocks down 10 pins, first fame is over.") {
  WHEN("Second frame played with 9, third frame played with 9") {
    THEN("First frame is over with 'strike'") {
      CHECK("score for first frame is 28")
    }
  }
}

// endigs
GIVEN("9 frames are played. First ball in last frame is not played.") {
  WHEN("First ball in 10th frame knocks down 10 pins") {
    THEN(
        "Last frame is over. Two bonus balls are added, game is not finished") {

    }
  }
}

GIVEN("All 10 frames are played, First ball in 10th frame knocks down 10 pins, "
      "Last frame is over. Two bonus balls are added, game is not finished") {
  WHEN(
      "New pins are setup, first extra ball is played and knock down 10 pins") {
    THEN("Game is over. Second bonus ball is not played. No additional bonus "
         "balls") {}
  }
}
}

GIVEN("All 10 frames are played, First ball in 10th frame knocks down 10 pins, "
      "Last frame is over. Two bonus balls are added, game is not finished") {
  WHEN("First extra ball is played and knock down 3 pins") {
    THEN("Game is not over. Second bonus ball can be played. No additional "
         "bonus balls") {}
  }
}

GIVEN("First extra ball is played and knock down 3 pins") {
  WHEN("Second extra ball is played and knock down 1 pin") {
    THEN("Game is over. No extra balls added")
  }
}

GIVEN("First extra ball is played and knock down 3 pins") {
  WHEN("Second extra ball is played and knock down 7 pins") {
    THEN("Game is over. No extra balls added")
  }
}

// interruption scenarios
SCENARIO("Playing against the rules") {
  GIVEN("Player with 2 balls played in 10-th frame and hits 3 points in last "
        "frame") {
    WHEN("Player tries play ball and hits all points (strike)") {
      THEN("Last frame counts for 3 points") {}
    }
  }

  GIVEN("Player1 played two balls in first frame and now Player2 should play") {
    WHEN("Player1 tries to play ball") {
      THEN("Not possible to play ball in this frame for Player1 ") {}
    }
  }
}
