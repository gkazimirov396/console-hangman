#include <fstream>
#include <iostream>
#include <cstdlib>

#include "difficulty.h"

Difficulty::Difficulty() {
    loadWordsFromFile("words.txt");
}

void Difficulty::loadWordsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file " << filename << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        wordsByLength[word.size()].push_back(word);
    }

    file.close();
}

std::string Difficulty::chooseWord(int wordLength) {
    if (wordsByLength.find(wordLength) == wordsByLength.end()) {
        return "";
    }

    const auto& words = wordsByLength[wordLength];
    int randomIndex = rand() % words.size();

    return words[randomIndex];
}