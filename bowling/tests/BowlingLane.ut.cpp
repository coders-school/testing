#include <gtest/gtest.h>
#include "../include/BowlingLane.hpp"

struct BowlingLaneTest : public ::testing::Test {
    std::vector<std::shared_ptr<Player>> players;
    BowlingLane bowlingLane_{1, players};
};

TEST_F(BowlingLaneTest, ShouldConvertGameStateNO_GAMEToString){
    auto gameState = bowlingLane_.convertGameState(BowlingLane::GameState::NO_GAME);
    ASSERT_EQ(gameState, "no game");
}

TEST_F(BowlingLaneTest, ShouldWriteOutDataUsingOstreamOperator){
    std::stringstream os;
    os << bowlingLane_;
    int laneNumber = bowlingLane_.getLaneNumber();
    auto gameState = bowlingLane_.convertGameState(bowlingLane_.checkGameState());

    std::string expected("### Lane " + std::to_string(laneNumber) + ": " + gameState + " ###\n");
    ASSERT_EQ(os.str(), expected);
}

