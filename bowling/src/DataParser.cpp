#include "DataParser.hpp"

#include <algorithm>

std::string DataParser::stringPreparing(std::string& playerResults) {
    const char addToEndOfString = '|';
    playerResults.push_back(addToEndOfString);

    return playerResults;
}

std::vector<std::string> DataParser::stringSplitting(std::string& preparedStringWithPlayerResults) {
    const std::string delimiter = "|";
    size_t position = 0;
    std::string token;
    std::vector<std::string> vectorWithResultsForEachLine{};
    while ((position = preparedStringWithPlayerResults.find(delimiter)) != std::string::npos) {
        token = preparedStringWithPlayerResults.substr(0, position);
        vectorWithResultsForEachLine.emplace_back(token);
        preparedStringWithPlayerResults.erase(0, position + delimiter.length());
    }

    return vectorWithResultsForEachLine;
}

std::vector<int> DataParser::stringProcessing(std::vector<std::string>& vectorWithResultsForEachLine) {
    std::vector<int> vectorWithResults{};

    std::find_if(vectorWithResultsForEachLine.cbegin(), vectorWithResultsForEachLine.cend(),
                 [&vectorWithResults](std::string bowlingLineString) {
                     std::find_if(bowlingLineString.cbegin(), bowlingLineString.cend(),
                                  [&vectorWithResults, &bowlingLineString](const char charackter) {
                                      if (charackter == isStrike) {
                                          vectorWithResults.emplace_back(strike);
                                          vectorWithResults.emplace_back(zeroPoints);
                                      }

                                      if (charackter == isMiss) {
                                          vectorWithResults.emplace_back(zeroPoints);
                                      }

                                      if (isdigit(charackter)) {
                                          if (bowlingLineString[1] == isSpare) {
                                              uint8_t firstThrow = *bowlingLineString.begin() - convertCharToInt;
                                              uint8_t secondThrow = strike - firstThrow;
                                              vectorWithResults.emplace_back(firstThrow);
                                              vectorWithResults.emplace_back(secondThrow);
                                              return true;
                                          }
                                          uint8_t charackterToInteger = charackter - convertCharToInt;
                                          vectorWithResults.emplace_back(charackterToInteger);
                                      }

                                      return false;
                                  });

                     return false;
                 });

    if (vectorWithResults.size() == addZeroPointsToVectorEndForThisSize) {
        vectorWithResults.emplace_back(zeroPoints);
    }

    return vectorWithResults;
}

std::pair<std::string, std::vector<int>> DataParser::dataParsing(std::string& processingString) {
    auto delimiterPosition = processingString.find_first_of(':');
    std::string playerName = processingString.substr(0, delimiterPosition);

    std::string playerResults = processingString.substr(++delimiterPosition);
    std::string preparedStringWithPlayerResults = stringPreparing(playerResults);
    std::vector<std::string> vectorWithResultsForEachLine = stringSplitting(preparedStringWithPlayerResults);
    std::vector<int> playerResult = stringProcessing(vectorWithResultsForEachLine);

    return std::make_pair(playerName, playerResult);
}