#pragma once

#include <string>
#include <vector>
#include <map>

class DirectoryHandler {
public:
    DirectoryHandler(const std::string directoryName)
        : directoryName_{directoryName} {
        processData();
    }

    std::map<int, std::vector<std::string>> getDirectoryData() {
        return rawLanesData_;
    }

    void printData();

private:
    std::string directoryName_;
    //std::vector<std::pair<int, std::vector<std::string>>> rawLanesData_;
    std::map<int, std::vector<std::string>> rawLanesData_;


    void processData();
};
