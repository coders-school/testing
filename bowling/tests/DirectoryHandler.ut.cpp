#include <algorithm>

#include <gtest/gtest.h>
#include "DirectoryHandler.hpp"

constexpr char inputDirectoryPath[] = "../input";

TEST(DirectoryHandlerTest, CheckAllLanesBeingProcessed) {
    std::vector<int> lanes{1, 2, 3};
    DirectoryHandler handler{inputDirectoryPath};
    auto handlerData = handler.getDirectoryData();

    auto isContainsAllLines = std::all_of(handlerData.begin(), handlerData.end(), [lanes](const auto& el) {
        return std::find(lanes.begin(), lanes.end(), el.first) != lanes.end();
    });

    ASSERT_TRUE(isContainsAllLines);
}

TEST(DirectoryHandlerTest, CheckIfFirstLaneDataWasLoaded) {
    DirectoryHandler handler{inputDirectoryPath};
    auto handlerDataFirstLane = handler.getDirectoryData()[0].second;

    std::vector<std::string> lane1{"Name1:X|4-|3",
                                   "Name2:34|X|0-",
                                   ":X|22|33"};

    auto isContainsLine1 = std::all_of(handlerDataFirstLane.begin(), handlerDataFirstLane.end(), [lane1](const auto& el) {
        return std::find(lane1.begin(), lane1.end(), el) != lane1.end();
    });

    ASSERT_TRUE(isContainsLine1);
}
