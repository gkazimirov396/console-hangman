#include <iostream>

#include "display.h"

void Display::showWord(const std::string& word) const {
    std::cout << "\nCurrent word: " << word << "\n";
}

void Display::showHangman(int attemptsLeft) {
    if (attemptsLeft == 6) {
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
    }
    else if (attemptsLeft == 5) {
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
    }
    else if (attemptsLeft == 4) {
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << "  |   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
    }
    else if (attemptsLeft == 3) {
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|   | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
    }
    else if (attemptsLeft == 2) {
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|\\  | \n";
        std::cout << "      | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
    }
    else if (attemptsLeft == 1) {
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|\\  | \n";
        std::cout << " /    | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
    }
    else if (attemptsLeft == 0) {
        std::cout << "  +---+ \n";
        std::cout << "  |   | \n";
        std::cout << "  O   | \n";
        std::cout << " /|\\  | \n";
        std::cout << " / \\  | \n";
        std::cout << "      | \n";
        std::cout << " ========= \n";
    }

    std::cout << "\nAttempts left: " << attemptsLeft << std::endl;
}

void Display::showGuessedLetters(const std::vector<char>& guessedLetters) const {
    std::cout << "Guessed letters: ";

    for (char letter : guessedLetters) {
        std::cout << letter << ' ';
    }

    std::cout << std::endl;
}

void Display::showWinMessage(const std::string& name) {
    std::cout << "Congratulations, " << name << "! You've guessed the word!" << std::endl;
}

void Display::showLoseMessage(const std::string& fullWord) {
    std::cout << "Game Over! The word was: " << fullWord << std::endl;
}