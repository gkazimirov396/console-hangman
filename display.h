#pragma once

#include <string>
#include <vector>

class Display {
public:
    void showWord(const std::string& word) const;
    void showHangman(int attemptsLeft);
    void showGuessedLetters(const std::vector<char>& guessedLetters) const;
    void showWinMessage(const std::string& name);
    void showLoseMessage(const std::string& fullWord);
};