#include <iostream>

#include "game-manager.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager(const std::string& secretWord, int maxAttempts)
    : maxAttempts(maxAttempts), currentAttempts(maxAttempts), isGameOver(false), word(secretWord) {}


GameManager* GameManager::getInstance(const std::string& secretWord, int maxAttempts) {
    if (instance == nullptr) {
        instance = new GameManager(secretWord, maxAttempts);
    }

    return instance;
}

void GameManager::startGame() {
    std::string playerName;

    std::cout << "Enter your name: ";
    std::cin >> playerName;

    player.setName(playerName);

    while (currentAttempts > 0 && !isGameOver) {
        displayState();

        char guess;
        std::string playerInput;

        std::cout << "Enter a letter: ";
        std::cin >> playerInput;

        if (playerInput.size() != 1) {
            std::cout << "Please enter only one letter.\n";
            continue;
        }

        guess = std::tolower(playerInput[0]);

        if (!std::isalpha(guess)) {
            std::cout << "Please enter an alphabetical character.\n";
            continue;
        }

        if (player.hasGuessed(guess)) {
            std::cout << "You've already guessed that letter.\n";
            continue;
        }

        player.addGuess(guess);

        if (word.checkLetter(guess)) {
            std::cout << "Correct!\n";

            if (word.isFullyRevealed()) {
                display.showWinMessage(playerName);
                isGameOver = true;
            }
        }
        else {
            currentAttempts--;
            display.showHangman(currentAttempts);

            if (currentAttempts == 0) {
                display.showLoseMessage(word.getOriginalWord());
                isGameOver = true;
            }
        }
    }
}

void GameManager::displayState() const {
    display.showWord(word.getRevealedWord());
    display.showGuessedLetters(player.getGuessedLetters());
}