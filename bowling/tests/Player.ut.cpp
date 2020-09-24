#include <gtest/gtest.h>
#include "../include/Player.hpp"

struct PlayerTest : public ::testing::Test {
    Player player;
    std::vector<int> score{};
};

TEST_F(PlayerTest, ShouldCountOfScoreForAllZeros) {
    score = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    constexpr int scoreOfAllZeros = 0;
    ASSERT_EQ(player.countScore(score), scoreOfAllZeros);
}

TEST_F(PlayerTest, ShouldCountOfScoreForAllOnes) {
    score = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    constexpr int scoreOfAllOnes = 20;
    ASSERT_EQ(player.countScore(score), scoreOfAllOnes);
}

TEST_F(PlayerTest, ShouldCountOfScoreForAllTens) {
    score = {10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0};
    constexpr int scoreOfAllTens = 300;
    ASSERT_EQ(player.countScore(score), scoreOfAllTens);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithoutSpareAndStrike) {
    score = {5, 3, 4, 3, 7, 2, 5, 1, 8, 0, 6, 2, 4, 4, 3, 3, 7, 1, 4, 2};
    constexpr int scoreWithoutSpareAndStrike = 74;
    ASSERT_EQ(player.countScore(score), scoreWithoutSpareAndStrike);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithExtraThrows) {
    score = {4, 5, 3, 4, 5, 5, 7, 2, 3, 7, 8, 2, 10, 0, 10, 0, 8, 2, 10, 0, 6, 3};
    std::vector<int> score_other = {10, 0, 10, 0, 10, 0, 5, 3, 10, 0, 10, 0, 9, 0, 4, 4, 6, 3, 10, 0, 10, 0, 4, 0};
    constexpr int scoreWithExtraThrows = 167;
    ASSERT_EQ(player.countScore(score), scoreWithExtraThrows);

    constexpr int scoreWithExtraThrowsOther = 179;
    ASSERT_EQ(player.countScore(score_other), scoreWithExtraThrowsOther);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithOneStrike) {
    score = {3, 6, 2, 2, 4, 5, 10, 0, 7, 2, 3, 5, 4, 2, 7, 1, 8, 1, 3, 4};
    constexpr int scoreWithOneStrike = 88;
    ASSERT_EQ(player.countScore(score), scoreWithOneStrike);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithOneSpare) {
    score = {3, 3, 7, 3, 2, 5, 8, 1, 4, 5, 4, 4, 3, 2, 1, 4, 6, 3, 5, 3};
    constexpr int scoreWithOneSpare = 78;
    ASSERT_EQ(player.countScore(score), scoreWithOneSpare);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithAllSpare) {
    score = {9, 1, 8, 2, 7, 3, 6, 4, 5, 5, 5, 5, 4, 6, 3, 7, 2, 8, 1, 9, 5, 0};
    constexpr int scoreWithAllSpare = 146;
    ASSERT_EQ(player.countScore(score), scoreWithAllSpare);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithSpareAfterStrike) {
    score = {0, 0, 0, 0, 10, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    constexpr int scoreWithSpareAfterStrike = 30;
    ASSERT_EQ(player.countScore(score), scoreWithSpareAfterStrike);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithStrikeAfterSpare) {
    score = {0, 0, 0, 0, 5, 5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    constexpr int scoreWithStrikeAfterSpare = 30;
    ASSERT_EQ(player.countScore(score), scoreWithStrikeAfterSpare);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithAllFives) {
    score = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0};
    constexpr int scoreWithAllFives = 150;
    ASSERT_EQ(player.countScore(score), scoreWithAllFives);
}