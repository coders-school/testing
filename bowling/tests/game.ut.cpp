#include <gtest/gtest.h>
#include "Game.hpp"


TEST(GameScoreTest, GameScoreShouldBe0){
    Game g;
    ASSERT_EQ(0, g.getScore());
}
