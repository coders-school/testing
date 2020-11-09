#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class DirectoryHandler {
public:
    DirectoryHandler(const std::string directoryName);

    std::map<int, std::vector<std::string>> getDirectoryData() {
        return rawLanesData_;
    }

private:
    std::string directoryName_;
    std::map<int, std::vector<std::string>> rawLanesData_;
    void processData();
};
