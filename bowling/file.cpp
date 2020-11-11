#include "file.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <regex>
#include <sstream>

File::File(std::string fileName)
    : fileName_(fileName) {}

std::map<std::string, std::vector<std::pair<int, int>>> File::getPlayerResults() const {
    return playerResults_;
}

void File::splitString(const std::string& str, std::vector<std::string>& vec, char delimiter) {
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        vec.push_back(token);
    }
}

void File::divideResultsIntoPlayers(const std::vector<std::string>& line) {
    std::vector<std::string> temp{};
    std::vector<std::pair<int, int>> scoreVector;
    for (auto singlePlayerResults : line) {
        temp.clear();
        this->splitString(singlePlayerResults, temp, ':');
        scoreVector = this->translateResultsToScoreVector(temp[1]);
        playerResults_[temp[0]] = scoreVector;
    }
}

std::vector<std::pair<int, int>> File::translateResultsToScoreVector(const std::string& results) {
    std::vector<std::string> results_divided;
    std::vector<int> temp{};
    std::vector<std::pair<int, int>> score;

    this->splitString(results, results_divided, '|');

    for (auto elem : results_divided) {
        if (elem.empty()) {
            continue;
        } else if (elem == "X") {
            score.push_back(std::make_pair(10, 0));
        } else if (elem == "XX") {
            score.push_back(std::make_pair(10, 0));
            score.push_back(std::make_pair(10, 0));
        } else if (elem == "--") {
            score.push_back(std::make_pair(0, 0));
        } else {
            for (int i = 0; i < 2; i++) {
                if (elem[i] == '-') {
                    temp.push_back(0);
                } else if (std::isdigit(elem[i])) {
                    temp.push_back((int)elem[i] - '0');
                } else if (elem[i] == '/') {
                    temp.push_back(10 - temp[0]);
                } else {
                    temp.push_back(0);
                }
            }
            score.push_back(std::make_pair(temp[0], temp[1]));
            temp.clear();
        }
    }
    return score;
}

void File::readFile() {
    std::string line;
    std::ifstream lane(this->fileName_);
    std::vector<std::string> fileContents;
    if (lane.is_open()) {
        while (getline(lane, line)) {
            fileContents.push_back(line);
        }
    } else {
        std::cerr << "Could not open file ...";
    }
    if (!fileContents.empty()) {
        this->divideResultsIntoPlayers(fileContents);
    }
}

void File::saveFile() {
    namespace fs = std::filesystem;
    fs::path path = fs::current_path();
    fs::create_directories(path.parent_path());
    std::ofstream ofs(path);
    if (!ofs) {
        std::cerr << "Could not open " << fileName_ << " for writing!\n";
    } else {
        ofs << "score";
        ofs.close();
    }
}
