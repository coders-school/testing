#include "gtest/gtest.h"

#include "BowlingAlley.hpp"

#include <filesystem>

class BowlingAlleyTests : public ::testing::Test {
protected:
    std::filesystem::path path = "../games";
    BowlingAlley bowlingAlley{path};

};

TEST_F(BowlingAlleyTests, bowlingAlleyCanBeLoadedFromFolder) {
    BowlingAlley alley;
    alley.loadFromFolder(path);
}
