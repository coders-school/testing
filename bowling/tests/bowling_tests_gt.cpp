#include "gtest/gtest.h"

#include "Game.hpp"

#include <filesystem>
#include <fstream>

class GameTests : public ::testing::Test {
    protected:
    Game game;
};

using GameDeathTests = GameTests;

TEST_F(GameDeathTests, GameIsLoadedFromNonExistingFile) {
    std::string fileName{"hiashdksjd.txt"};
    std::string filePath = std::filesystem::current_path().string() + fileName;
    std::string expectedMessage = "file " + filePath + " could not be opened!";
    ASSERT_DEATH(game.loadFromFile(filePath), expectedMessage);
}

TEST_F(GameTests, loadFromFileShouldLoadPlayerName) {
    std::string expectedPlayerName{"Franek"};
    std::string fileName = "/franek.txt";
    std::string filePath = std::filesystem::current_path().string() + fileName;
    std::ofstream file(filePath, std::ios_base::out);
    file << "Franek:\n";
    file.flush();
    game.loadFromFile(filePath);
    ASSERT_EQ(game.getPlayers()[0].name, expectedPlayerName);
    file.close();
    std::filesystem::remove(filePath);
}


