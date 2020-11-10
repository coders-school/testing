#include "DataParser.hpp"

#include <algorithm>

std::string DataParser::prepareString(std::string& playerResults) {
    const char addToEndOfString = '|';
    playerResults.push_back(addToEndOfString);

    return playerResults;
}

std::vector<std::string> DataParser::splitString(std::string& preparedStringWithPlayerResults) {
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

std::vector<int> DataParser::processString(std::vector<std::string>& vectorWithResultsForEachLine) {
    std::vector<int> vectorWithResults{};

    std::find_if(vectorWithResultsForEachLine.cbegin(), vectorWithResultsForEachLine.cend(),
                 [&vectorWithResults](std::string bowlingLineString) {
                     std::find_if(bowlingLineString.cbegin(), bowlingLineString.cend(),
                                  [&vectorWithResults, &bowlingLineString](const char charackter) {
                                      if (charackter == strikeMarker) {
                                          vectorWithResults.emplace_back(strike);
                                          vectorWithResults.emplace_back(zeroPoints);
                                      }

                                      if (charackter == missMarker) {
                                          vectorWithResults.emplace_back(zeroPoints);
                                      }

                                      if (isdigit(charackter)) {
                                          if (bowlingLineString[1] == spareMarker) {
                                              uint8_t firstThrow = *bowlingLineString.begin() - charToIntConverter;
                                              uint8_t secondThrow = strike - firstThrow;
                                              vectorWithResults.emplace_back(firstThrow);
                                              vectorWithResults.emplace_back(secondThrow);
                                              return true;
                                          }
                                          uint8_t charackterToInteger = charackter - charToIntConverter;
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

std::pair<std::string, std::vector<int>> DataParser::parseData(std::string& processingString) {
    auto delimiterPosition = processingString.find_first_of(':');
    std::string playerName = processingString.substr(0, delimiterPosition);

    std::string playerResults = processingString.substr(++delimiterPosition);
    std::string preparedStringWithPlayerResults = prepareString(playerResults);
    std::vector<std::string> vectorWithResultsForEachLine = splitString(preparedStringWithPlayerResults);
    std::vector<int> playerResult = processString(vectorWithResultsForEachLine);

    return std::make_pair(playerName, playerResult);
}