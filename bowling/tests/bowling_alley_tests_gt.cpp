#include "gtest/gtest.h"

#include "BowlingAlley.hpp"

#include <filesystem>

class BowlingAlleyTests : public ::testing::Test {
protected:
    std::filesystem::path path = "/tests";
    BowlingAlley bowlingAlley{path};

};
