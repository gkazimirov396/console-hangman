#pragma once

#include <vector>
#include <string>

class Player {
private:
    std::string name;
    std::vector<char> guessedLetters;

public:
    void addGuess(char letter);
    bool hasGuessed(char letter) const;

    const std::vector<char>& getGuessedLetters() const;

    void setName(const std::string& playerName);
    std::string getName() const;
};