#pragma once

#include <string>
#include <vector>

namespace {
constexpr uint8_t strike = 10;
constexpr uint8_t zeroPoints = 0;
constexpr uint8_t addZeroPointsToVectorEndForThisSize = 25;
constexpr char isStrike = 'X';
constexpr char isMiss = '-';
constexpr char isSpare = '/';
constexpr char convertCharToInt = '0';
}  // namespace

class DataParser {
public:
    DataParser() = default;
    std::pair<std::string, std::vector<int>> dataParsing(std::string& processingString);

private:
    std::string stringPreparing(std::string& playerResults);
    std::vector<std::string> stringSplitting(std::string& preparedStringWithPlayerResults);
    std::vector<int> stringProcessing(std::vector<std::string>& vectorWithResultsForEachLine);
};