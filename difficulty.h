#pragma once

#include <string>
#include <vector>
#include <map>

class Difficulty {
public:
    Difficulty();
    std::string chooseWord(int wordLength);

private:
    std::map<int, std::vector<std::string>> wordsByLength;
    void loadWordsFromFile(const std::string& filename);
};