#include <algorithm>

#include "player.h"

void Player::setName(const std::string& playerName) {
    name = playerName;
}

std::string Player::getName() const {
    return name;
}

void Player::addGuess(char letter) {
    if (!hasGuessed(letter)) {
        guessedLetters.push_back(letter);
    }
}

bool Player::hasGuessed(char letter) const {
    return std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end();
}

const std::vector<char>& Player::getGuessedLetters() const {
    return guessedLetters;
}