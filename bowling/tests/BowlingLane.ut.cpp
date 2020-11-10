#include <gtest/gtest.h>
#include <string_view>
#include "../include/BowlingLane.hpp"

constexpr char playerName[] = "test";
constexpr char noGameString[] = "no game";
constexpr char gameInProgressMessage[] = "### Lane 1: game in progress ###\ntest 3\n";
constexpr char gameFinishedMessage[] = "### Lane 1: game finished ###\ntest 20\n";

struct BowlingLaneTest : public ::testing::Test {
    std::vector<std::shared_ptr<Player>> players;
    BowlingLane bowlingLane_{1, players};
};

TEST_F(BowlingLaneTest, ShouldConvertGameStateNoGameoString) {
    auto gameState = bowlingLane_.convertGameState(BowlingLane::GameState::NO_GAME);
    ASSERT_EQ(gameState, noGameString);
}

TEST(BowlingLane, BowlingLaneStateShouldReturnNoGame) {
    std::vector<std::shared_ptr<Player>> players;
    BowlingLane bowlingLane{1, players};
    ASSERT_EQ(bowlingLane.checkGameState(), BowlingLane::GameState::NO_GAME);
}

TEST(BowlingLane, BowlingLaneStateShouldReturnGameInProgress) {
    std::vector<std::shared_ptr<Player>> players;
    std::vector<int> gameInProgress = {1, 2, 3};
    players.emplace_back(std::make_shared<Player>(playerName, gameInProgress));
    BowlingLane bowlingLane{1, players};
    ASSERT_EQ(bowlingLane.checkGameState(), BowlingLane::GameState::IN_PROGRESS);
}

TEST(BowlingLane, BowlingLaneStateShouldReturnFinished) {
    std::vector<std::shared_ptr<Player>> players;
    std::vector<int> gameFinished(20, 1);
    players.emplace_back(std::make_shared<Player>(playerName, gameFinished));
    BowlingLane bowlingLane{1, players};
    ASSERT_EQ(bowlingLane.checkGameState(), BowlingLane::GameState::FINISHED);
}

TEST_F(BowlingLaneTest, ShouldWriteOutDataUsingOstreamOperatorWithEmptyLaneNoGame) {
    std::stringstream os;
    os << bowlingLane_;
    int laneNumber = bowlingLane_.getLaneNumber();
    auto gameState = bowlingLane_.convertGameState(bowlingLane_.checkGameState());

    std::string expected("### Lane " + std::to_string(laneNumber) + ": " + gameState + " ###\n");
    ASSERT_EQ(os.str(), expected);
}

TEST_F(BowlingLaneTest, ShouldWriteOutDataUsingOstreamOperatorWithGameInProgress) {
    std::vector<std::shared_ptr<Player>> players;
    std::vector<int> gameInProgress = {1, 2, 3};
    players.emplace_back(std::make_shared<Player>(playerName, gameInProgress));
    BowlingLane bowlingLane_{1, players};

    std::stringstream os;
    os << bowlingLane_;

    ASSERT_EQ(os.str(), gameInProgressMessage);
}

TEST_F(BowlingLaneTest, ShouldWriteOutDataUsingOstreamOperatorWithGameFinished) {
    std::vector<std::shared_ptr<Player>> players;
    std::vector<int> gameFinished(20, 1);
    players.emplace_back(std::make_shared<Player>(playerName, gameFinished));
    BowlingLane bowlingLane_{1, players};

    std::stringstream os;
    os << bowlingLane_;

    ASSERT_EQ(os.str(), gameFinishedMessage);
}