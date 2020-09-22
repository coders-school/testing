#include <gtest/gtest.h>
#include "DataParser.hpp"

using dataParsingTuple = std::tuple<std::string, std::pair<std::string, std::vector<int>>>;
struct dataParsing : public testing::TestWithParam<dataParsingTuple> {};

TEST_P(dataParsing, ShouldParsingStringToPairOfStringAndVectorOfInts) {
    //GIVEN
    auto [inputString, expectedParsedData] = GetParam();
    //WHEN
    DataParser parser;
    std::pair<std::string, std::vector<int>> parsedData = parser.dataParsing(inputString);
    //THEN
    EXPECT_EQ(parsedData, expectedParsedData);
}

INSTANTIATE_TEST_CASE_P(
    dataParsingTest,
    dataParsing,
    ::testing::Values(
        dataParsingTuple{{"Michael:X|7/|9-|X|-8|8/|-6|X|X|X||81"},
                         {{"Michael"}, {10, 0, 7, 3, 9, 0, 10, 0, 0, 8, 8, 2, 0, 6, 10, 0, 10, 0, 10, 0, 8, 1}}},
        dataParsingTuple{{"Radek:9-|9-|9-|9-|9-|9-|9-|9-|9-|9-||"},
                         {{"Radek"}, {9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0, 9, 0}}},
        dataParsingTuple{{"Waleczny_Ziobro_69_PL:X|X|X|X|X|X|X|X|X|X||XX"},
                         {{"Waleczny_Ziobro_69_PL"}, {10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0, 10, 0}}},
        dataParsingTuple{{"|----------4 cm-----------|:5/|5/|5/|5/|5/|5/|5/|5/|5/|5/||5"},
                         {{"|----------4 cm-----------|"}, {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5}}},
        dataParsingTuple{{"Name2:34|X|0-"},
                         {{"Name2"}, {3, 4, 10, 0, 0, 0}}},
        dataParsingTuple{{":X|22|33"},
                         {{""}, {10, 0, 2, 2, 3, 3}}},
        dataParsingTuple{{"Name1:X|4-|3"},
                         {{"Name1"}, {10, 0, 4, 0, 3}}}));
