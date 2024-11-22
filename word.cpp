#include "word.h"

Word::Word(const std::string& word) : word(word), revealedWord(word.size(), '_') {}

bool Word::checkLetter(char letter) {
    bool found = false;

    for (size_t i = 0; i < word.size(); ++i) {
        if (word[i] == letter) {
            revealedWord[i] = letter;
            found = true;
        }
    }

    return found;
}

void Word::updateRevealedWord(char letter) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (word[i] == letter) {
            revealedWord[i] = letter;
        }
    }
}

bool Word::isFullyRevealed() const {
    return word == revealedWord;
}

std::string Word::getRevealedWord() const {
    return revealedWord;
}

std::string Word::getOriginalWord() const {
    return word;
}