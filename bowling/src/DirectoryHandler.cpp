#include "DirectoryHandler.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
namespace fs = std::filesystem;

DirectoryHandler::DirectoryHandler(const std::string directoryName)
    : directoryName_{directoryName} {
    try {
        processData();
    } catch (std::exception& e) {
        std::cerr << "Cannot process directory data!\n";
        throw;
    }
}

void DirectoryHandler::processData() {
    std::regex pattern(R"((\w+)/([a-zA-Z]+)(\d+).?(\w+)?)");

    for (auto& p : fs::directory_iterator(directoryName_)) {
        std::string recentFile = p.path().string();

        int lineNumber;
        std::vector<std::string> temporaryLanesData;
        if (p.is_regular_file()) {
            std::smatch matches;

            if (std::regex_search(recentFile, matches, pattern)) {
                lineNumber = std::stoi(matches[3]);
            }

            std::ifstream ifs{recentFile};
            for (std::string line; std::getline(ifs, line);) {
                if (!line.empty()) {
                    temporaryLanesData.push_back(line);
                }
            }
        }

        rawLanesData_.insert({lineNumber, temporaryLanesData});
    }
}
