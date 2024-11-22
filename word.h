#pragma once

#include <string>

class Word {
private:
    std::string word;
    std::string revealedWord;

public:
    Word(const std::string& word);

    bool checkLetter(char letter);
    bool isFullyRevealed() const;

    void updateRevealedWord(char letter);

    std::string getRevealedWord() const;
    std::string getOriginalWord() const;
};