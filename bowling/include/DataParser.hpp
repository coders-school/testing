#pragma once

#include <string>
#include <vector>

namespace {
constexpr uint8_t strike = 10;
constexpr uint8_t zeroPoints = 0;
constexpr uint8_t addZeroPointsToVectorEndForThisSize = 25;
constexpr char strikeMarker = 'X';
constexpr char missMarker = '-';
constexpr char spareMarker = '/';
constexpr char charToIntConverter = '0';
}  // namespace

class DataParser {
public:
    DataParser() = default;
    std::pair<std::string, std::vector<int>> parseData(std::string& processingString);

private:
    std::string prepareString(std::string& playerResults);
    std::vector<std::string> splitString(std::string& preparedStringWithPlayerResults);
    std::vector<int> processString(std::vector<std::string>& vectorWithResultsForEachLine);
};