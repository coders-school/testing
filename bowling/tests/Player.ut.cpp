#include <gtest/gtest.h>
#include "../include/Player.hpp"

struct PlayerTest : public ::testing::Test {
    Player player;
    std::vector<int> score{};
};

TEST_F(PlayerTest, ShouldCountOfScoreForAllZeros) {
    score = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Player playerTest("name", score);
    constexpr int scoreOfAllZeros = 0;
    ASSERT_EQ(playerTest.getScore(), scoreOfAllZeros);
}

TEST_F(PlayerTest, ShouldCountOfScoreForAllOnes) {
    score = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Player playerTest("name", score);
    constexpr int scoreOfAllOnes = 20;
    ASSERT_EQ(playerTest.getScore(), scoreOfAllOnes);
}

TEST_F(PlayerTest, ShouldCountOfScoreForAllTens) {
    score = {10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0};
    Player playerTest("name", score);
    constexpr int scoreOfAllTens = 300;
    ASSERT_EQ(playerTest.getScore(), scoreOfAllTens);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithoutSpareAndStrike) {
    score = {5, 3, 4, 3, 7, 2, 5, 1, 8, 0, 6, 2, 4, 4, 3, 3, 7, 1, 4, 2};
    Player playerTest("name", score);
    constexpr int scoreWithoutSpareAndStrike = 74;
    ASSERT_EQ(playerTest.getScore(), scoreWithoutSpareAndStrike);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithExtraThrows) {
    score = {4, 5, 3, 4, 5, 5, 7, 2, 3, 7, 8, 2, 10, 0, 10, 0, 8, 2, 10, 0, 6, 3};
    std::vector<int> score_other = {10, 0, 10, 0, 10, 0, 5, 3, 10, 0, 10, 0, 9, 0, 4, 4, 6, 3, 10, 0, 10, 0, 4, 0};
    Player playerTest1("name", score);
    constexpr int scoreWithExtraThrows = 167;
    ASSERT_EQ(playerTest1.getScore(), scoreWithExtraThrows);

    Player playerTest2("name", score_other);
    constexpr int scoreWithExtraThrowsOther = 179;
    ASSERT_EQ(playerTest2.getScore(), scoreWithExtraThrowsOther);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithOneStrike) {
    score = {3, 6, 2, 2, 4, 5, 10, 0, 7, 2, 3, 5, 4, 2, 7, 1, 8, 1, 3, 4};
    Player playerTest("name", score);
    constexpr int scoreWithOneStrike = 88;
    ASSERT_EQ(playerTest.getScore(), scoreWithOneStrike);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithOneSpare) {
    score = {3, 3, 7, 3, 2, 5, 8, 1, 4, 5, 4, 4, 3, 2, 1, 4, 6, 3, 5, 3};
    Player playerTest("name", score);
    constexpr int scoreWithOneSpare = 78;
    ASSERT_EQ(playerTest.getScore(), scoreWithOneSpare);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithAllSpare) {
    score = {9, 1, 8, 2, 7, 3, 6, 4, 5, 5, 5, 5, 4, 6, 3, 7, 2, 8, 1, 9, 5, 0};
    Player playerTest("name", score);
    constexpr int scoreWithAllSpare = 146;
    ASSERT_EQ(playerTest.getScore(), scoreWithAllSpare);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithSpareAfterStrike) {
    score = {0, 0, 0, 0, 10, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Player playerTest("name", score);
    constexpr int scoreWithSpareAfterStrike = 30;
    ASSERT_EQ(playerTest.getScore(), scoreWithSpareAfterStrike);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithStrikeAfterSpare) {
    score = {0, 0, 0, 0, 5, 5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    Player playerTest("name", score);
    constexpr int scoreWithStrikeAfterSpare = 30;
    ASSERT_EQ(playerTest.getScore(), scoreWithStrikeAfterSpare);
}

TEST_F(PlayerTest, ShouldCountOfScoreForGameWithAllFives) {
    score = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0};
    Player playerTest("name", score);
    constexpr int scoreWithAllFives = 150;
    ASSERT_EQ(playerTest.getScore(), scoreWithAllFives);
}