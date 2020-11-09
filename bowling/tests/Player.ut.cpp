#include <gtest/gtest.h>
#include "../include/Player.hpp"

constexpr int scoreOfAllZeros = 0;
constexpr int scoreOfAllOnes = 20;
constexpr int scoreOfAllTens = 300;
constexpr int scoreWithoutSpareAndStrike = 74;
constexpr int scoreWithExtraThrows = 167;
constexpr int scoreWithExtraThrowsOther = 179;
constexpr int scoreWithOneStrike = 88;
constexpr int scoreWithOneSpare = 78;
constexpr int scoreWithAllSpare = 146;
constexpr int scoreWithSpareAfterStrike = 30;
constexpr int scoreWithStrikeAfterSpare = 30;
constexpr int scoreWithAllFives = 150;

using Pairs = std::pair<std::vector<int>, int>;
struct testingPlayer : public testing::TestWithParam<Pairs> {};

TEST_P(testingPlayer, ShouldCountOfScoreForGames) {
    // GIVEN
    auto [input, expected] = GetParam();
    // WHEN
    Player player{"name", input};

    // THEN
    EXPECT_EQ(player.getScore(), expected);
}

INSTANTIATE_TEST_CASE_P(
    CountOfScore,
    testingPlayer,
    ::testing::Values(
        Pairs{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, scoreOfAllZeros},
        Pairs{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, scoreOfAllOnes},
        Pairs{{10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0}, scoreOfAllTens},
        Pairs{{5, 3, 4, 3, 7, 2, 5, 1, 8, 0, 6, 2, 4, 4, 3, 3, 7, 1, 4, 2}, scoreWithoutSpareAndStrike},
        Pairs{{4, 5, 3, 4, 5, 5, 7, 2, 3, 7, 8, 2, 10, 0, 10, 0, 8, 2, 10, 0, 6, 3}, scoreWithExtraThrows},
        Pairs{{10, 0, 10, 0, 10, 0, 5, 3, 10, 0, 10, 0, 9, 0, 4, 4, 6, 3, 10, 0, 10, 0, 4, 0},
              scoreWithExtraThrowsOther},
        Pairs{{3, 6, 2, 2, 4, 5, 10, 0, 7, 2, 3, 5, 4, 2, 7, 1, 8, 1, 3, 4}, scoreWithOneStrike},
        Pairs{{3, 3, 7, 3, 2, 5, 8, 1, 4, 5, 4, 4, 3, 2, 1, 4, 6, 3, 5, 3}, scoreWithOneSpare},
        Pairs{{9, 1, 8, 2, 7, 3, 6, 4, 5, 5, 5, 5, 4, 6, 3, 7, 2, 8, 1, 9, 5, 0}, scoreWithAllSpare},
        Pairs{{0, 0, 0, 0, 10, 0, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, scoreWithSpareAfterStrike},
        Pairs{{0, 0, 0, 0, 5, 5, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, scoreWithStrikeAfterSpare},
        Pairs{{5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0}, scoreWithAllFives}));