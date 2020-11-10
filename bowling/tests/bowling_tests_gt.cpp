#include "gtest/gtest.h"

#include "Game.hpp"

#include <filesystem>
#include <fstream>

class GameTests : public ::testing::Test {
   protected:
    Game game;
    std::ofstream file;
    std::string filePath;
    std::string tenStrikes{"X|X|X|X|X|X|X|X|X|X|"};

    void SetUp() override {
        std::string fileName = "/test_file.txt";
        filePath = std::filesystem::current_path().string() + fileName;
        file.open(filePath, std::ios_base::out);
    }

    void TearDown() override {
        file.close();
        std::filesystem::remove(filePath);
    }
};

using GameDeathTests = GameTests;

TEST_F(GameDeathTests, GameCrashesWhenLoadedFromNonExistingFile) {
    std::string DfileName{"hiashdksjd.txt"};
    std::string DfilePath = std::filesystem::current_path().string() + DfileName;
    std::string expectedMessage = "file " + DfilePath + " could not be opened!";
    EXPECT_DEATH(game.loadFromFile(DfilePath), expectedMessage);
}

TEST_F(GameTests, loadFromFileShouldLoadPlayerName) {
    std::string expectedPlayerName{"Franek"};
    file << "Franek:\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].name, expectedPlayerName);
}

TEST_F(GameTests, loadFromFileShouldLoadEmptyPlayerName) {
    std::string expectedPlayerName{};
    file << ":\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].name, expectedPlayerName);
}

TEST_F(GameTests, loadFromFileShouldLoadAllPlayersNames) {
    std::vector<std::string> expectedPlayerNames{"Wojtek", "Jadwiga", "Robert"};
    file << "Wojtek:27|12\n";
    file << "Jadwiga:33|18\n";
    file << "Robert:X\n";
    file.flush();
    game.loadFromFile(filePath);
    ASSERT_EQ(game.getPlayers().size(), 3);
    EXPECT_EQ(game.getPlayers()[0].name, expectedPlayerNames[0]);
    EXPECT_EQ(game.getPlayers()[1].name, expectedPlayerNames[1]);
    EXPECT_EQ(game.getPlayers()[2].name, expectedPlayerNames[2]);
}

TEST_F(GameTests, loadFromFileShouldNotLoadAnyPlayerFromEmptyFile) {
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers().size(), 0);
}

TEST_F(GameTests, loadFromFileShouldLoadPlayerRolls) {
    std::vector<Frame> expectedPlayerRolls{{'6', '3'}, {'1', '8'}, {'X', ' '}, {'4', '/'}};
    file << "Name:63|18|X|4/\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].rolls, expectedPlayerRolls);
}

TEST_F(GameTests, loadFromFileShouldLoadAllPlayersRolls) {
    std::vector<std::vector<Frame>> expectedAllPlayersRolls{{{'1', '2'}, {'X', ' '}, {'5', '/'}},
                                                            {{'3', '/'}, {'5', '4'}, {'X', ' '}},
                                                            {{'2', '2'}, {'8', '-'}, {'0', '-'}}};
    file << "Player1:12|X|5/\n";
    file << "Player2:3/|54|X\n";
    file << "Player3:22|8-|0-\n";
    file.flush();
    game.loadFromFile(filePath);
    ASSERT_EQ(game.getPlayers().size(), 3);
    EXPECT_EQ(game.getPlayers()[0].rolls, expectedAllPlayersRolls[0]);
    EXPECT_EQ(game.getPlayers()[1].rolls, expectedAllPlayersRolls[1]);
    EXPECT_EQ(game.getPlayers()[2].rolls, expectedAllPlayersRolls[2]);
}

TEST_F(GameTests, loadFromFileShouldLoadExtraRolls) {
    std::vector<Frame> expectedPlayerRolls{{'1', '2'},
                                           {'3', '4'},
                                           {'5', '6'},
                                           {'7', '8'},
                                           {'9', '9'},
                                           {'X', ' '},
                                           {'0', '-'},
                                           {'5', '/'},
                                           {'5', '4'},
                                           {'X', ' '},
                                           {'4', '4'}};
    file << "Name:12|34|56|78|99|X|0-|5/|54|X||44\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].rolls, expectedPlayerRolls);
}

TEST_F(GameTests, loadFromFileShouldNotAddEmptyFrameWhenThereAreNoExtraRolls) {
    std::vector<Frame> expectedPlayerRolls{{'1', '2'},
                                           {'3', '4'},
                                           {'5', '6'},
                                           {'7', '8'},
                                           {'9', '9'},
                                           {'X', ' '},
                                           {'0', '-'},
                                           {'5', '/'},
                                           {'5', '4'},
                                           {'X', ' '}};
    file << "Name:12|34|56|78|99|X|0-|5/|54|X||\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getPlayers()[0].rolls, expectedPlayerRolls);
}

std::ostream& operator<<(std::ostream& os, Game::Status status) {
    os << static_cast<int>(status);
    return os;
}

TEST_F(GameTests, getGameStatusShouldReturnNoGameWhenFileIsEmpty) {
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getGameStatus(), Game::Status::NO_GAME);
}

TEST_F(GameTests, getGameStatusShouldReturnInProgressWhenFramesAreNotFull) {
    file << "Robcio:12|27|X\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getGameStatus(), Game::Status::IN_PROGRESS);
}

TEST_F(GameTests, getGameStatusShouldReturnFinishedWhenFramesAreFull) {
    file << "Robcio:12|27|X|1/|22|11|0-|0-|12|0-||\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getGameStatus(), Game::Status::FINISHED);
}

TEST_F(GameTests, getGameStatusShouldReturnFinishedWhenExtraFrames) {
    file << "Robcio:12|27|X|1/|22|11|0-|0-|12|X||17\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getGameStatus(), Game::Status::FINISHED);
}

TEST_F(GameTests, getGameStatusShouldReturnInProgressWhenAtLeastOnePlayerHasLessThan10Frames) {
    file << "Robcio:" << tenStrikes << "|35\n";
    file << "Grzegorz:" << tenStrikes << "\n";
    file << "Eryk:12|27|X|0-|12|X|\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getGameStatus(), Game::Status::IN_PROGRESS);
}

TEST_F(GameTests, getGameStatusShouldReturnFinishedWhenOnePlayerHas10FramesAndSecondHasExtraBalls) {
    file << "Robcio:" << tenStrikes << "|35\n";
    file << "Grzegorz:" << tenStrikes << "\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getGameStatus(), Game::Status::FINISHED);
}

TEST_F(GameTests, getGameStatusShouldReturnInProgressWhenOnePlayerHasLessThan10FramesAndSecondHasExtraBalls) {
    file << "Robcio:" << tenStrikes << "|35\n";
    file << "Grzegorz:51|21|X\n";
    file.flush();
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getGameStatus(), Game::Status::IN_PROGRESS);
}

TEST_F(GameTests, countPointsFromVectorOfFramesWithoutStrikeNorSpareIncompleteGame) {
    std::vector<Frame> playerRolls{{'1', '2'}, {'4', '5'}, {'2', '2'}, {'7', '0'}};
    EXPECT_EQ(game.countPoints(playerRolls), 23);
}

TEST_F(GameTests, countPointsFromVectorOfFramesWithStrikeWithoutSpareIncompleteGame) {
    std::vector<Frame> playerRolls{{'X', ' '}, {'4', '5'}, {'X', ' '}, {'X', ' '}, {'1', '1'}, {'X', ' '}};
    EXPECT_EQ(game.countPoints(playerRolls), 72);
}

TEST_F(GameTests, countPointsFromVectorOfFramesWithSpareWithoutStrikeIncompleteGame) {
    std::vector<Frame> playerRolls{{'2', '/'}, {'4', '5'}, {'3', '/'}, {'2', '/'}, {'0', '/'}};
    EXPECT_EQ(game.countPoints(playerRolls), 55);
}

TEST_F(GameTests, countPointsFromVectorOfFramesCompleteGameWithStrikeSpareAndExtraFrame) {
    std::vector<Frame> playerRolls{{'X', ' '},
                                   {'4', '5'},
                                   {'X', ' '},
                                   {'X', ' '},
                                   {'1', '1'},
                                   {'X', ' '},
                                   {'5', '/'},
                                   {'X', ' '},
                                   {'1', '8'},
                                   {'X', ' '},
                                   {'5', '1'}};
    EXPECT_EQ(game.countPoints(playerRolls), 152);
}

TEST_F(GameTests, gameReturnsOutputStringWithManyPlayers) {
    file << "Name1:X|41|3\n";
    file << "Name2:\n";
    file << ":13|1/|1-\n";
    file.flush();
    auto laneNumber{1};
    auto expectedOutput{
        "### Lane 1: game in progress ###\n"
        "Name1 23\n"
        "Name2 0\n"
        "16\n"};
    game.loadFromFile(filePath);
    EXPECT_EQ(game.getOutputString(laneNumber), expectedOutput);
}

TEST_F(GameTests, loadFromFileShouldAddEmptyRollWhenFrameIsNotFinished) {
    file << "Name1:X|4-|3\n";
    file.flush();
    game.loadFromFile(filePath);
    auto players = game.getPlayers();
    std::vector<Frame> expectedRolls{{'X', ' '}, {'4', '-'}, {'3', ' '}};
    EXPECT_EQ(players[0].rolls, expectedRolls);
}

TEST_F(GameTests, calculateScoreShouldReturnCalculatedScoreForPlayer) {
    file << "Name1:X|4-|3\n";
    file.flush();
    game.loadFromFile(filePath);
    auto players = game.getPlayers();
    auto score = game.countPoints(players[0].rolls);
    auto expectedScore{21};
    EXPECT_EQ(score, expectedScore);
}
