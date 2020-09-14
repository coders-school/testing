#pragma once

#include <filesystem>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
namespace fs = std::filesystem;

class DirectoryHandler {
public:
    DirectoryHandler(const std::string directoryName)
        : directoryName_{directoryName} {}

    void getDirectoryData() {
        //returning prepared data;
    }

    void processData() {
        //processing raw data :P
    }

private:
    std::string directoryName_;
    std::vector<std::pair<int, std::vector<std::string>>> rawLanesData_;
};

