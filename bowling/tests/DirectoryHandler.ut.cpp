#include <algorithm>

#include <gtest/gtest.h>
#include "DirectoryHandler.hpp"

constexpr char inputManyFilesDirectoryPath[] = "../input/many-files";

TEST(DirectoryHandlerTest, CheckAllLanesBeingProcessed) {
    std::vector<int> lanes{1, 2, 3};
    DirectoryHandler handler{inputManyFilesDirectoryPath};
    auto handlerData = handler.getDirectoryData();

    auto isContainsAllLanes = std::all_of(handlerData.cbegin(), handlerData.cend(), [lanes](const auto& el) {
        return std::find(lanes.cbegin(), lanes.cend(), el.first) != lanes.cend();
    });

    ASSERT_TRUE(isContainsAllLanes);
}

TEST(DirectoryHandlerTest, CheckIfFirstLaneDataWasLoaded) {
    DirectoryHandler handler{inputManyFilesDirectoryPath};
    auto handlerDataFirstLane = handler.getDirectoryData()[1];

    std::vector<std::string> lane1{"Name1:X|4-|3",
                                   "Name2:34|X|0-",
                                   ":X|22|33"};

    auto isContainsLine1 = std::all_of(handlerDataFirstLane.cbegin(), handlerDataFirstLane.cend(), [lane1](const auto& el) {
        return std::find(lane1.cbegin(), lane1.cend(), el) != lane1.cend();
    });

    ASSERT_TRUE(isContainsLine1);
}
