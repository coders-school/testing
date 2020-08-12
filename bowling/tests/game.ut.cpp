#include <gtest/gtest.h>
#include "Game.hpp"

TEST(GameScoreTest, GivenAll0ShouldGiveGameScore0){
    Game g;

    for(int i = 0 ; i < 21 ; ++i){
        g.roll(0);
    }

    ASSERT_EQ(0, g.getScore());
}

TEST(GameScoreTest, GivenAll1ShouldGiveGameScore20){
    Game g;

    for(int i = 0 ; i < 20 ; ++i){
        g.roll(1);
    }

    ASSERT_EQ(20, g.getScore());
}

TEST(GameScoreTest, GivenAll2ShouldGiveGameScore40){
    Game g;

    for(int i = 0 ; i < 20 ; ++i){
        g.roll(2);
    }

    ASSERT_EQ(40, g.getScore());
}


TEST(GameScoreTest, GivenFirst10AndRest0ShouldGiveGameScore10){
    Game g;

    g.roll(10);
    for(int i = 1 ; i < 20 ; ++i){
        g.roll(0);
    }

    ASSERT_EQ(10, g.getScore());
}
