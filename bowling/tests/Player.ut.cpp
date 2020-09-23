#include <gtest/gtest.h>
#include "../include/Player.hpp"

struct PlayerTest : public ::testing::Test {
    Player player;
    std::vector<int> score{};
};

TEST_F(PlayerTest, ShouldCountOfScoreForAllZeros) {
    score = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    constexpr int scoreOfAllZeros = 0;
    player.countScore(score);
    ASSERT_EQ(player.getScore(), scoreOfAllZeros);
}

TEST_F(PlayerTest, ShouldCountOfScoreForAllOnes) {
    score = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    constexpr int scoreOfAllOnes = 20;
    player.countScore(score);
    ASSERT_EQ(player.getScore(), scoreOfAllOnes);
}

TEST_F(PlayerTest, ShouldCountOfScoreForAllTens) {
    score = {10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0};
    constexpr int scoreOfAllTens = 300;
    player.countScore(score);
    ASSERT_EQ(player.getScore(), scoreOfAllTens);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithoutSpareAndStrike) {
    score = {5, 3, 4, 3, 7, 2, 5, 1, 8, 0, 6, 2, 4, 4, 3, 3, 7, 1, 4, 2};
    constexpr int scoreWithoutSpareAndStrike = 74;
    player.countScore(score);
    ASSERT_EQ(player.getScore(), scoreWithoutSpareAndStrike);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithExtraThrows) {
    score = {4, 5, 3, 4, 5, 5, 7, 2, 3, 7, 8, 2, 10, 0, 10, 0, 8, 2, 10, 0, 6, 3};
    constexpr int scoreWithExtraThrows = 167;
    player.countScore(score);
    ASSERT_EQ(player.getScore(), scoreWithExtraThrows);
}
