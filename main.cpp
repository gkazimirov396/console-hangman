#include <iostream>
#include <ctime>

#include "difficulty.h"
#include "game-manager.h"

int main() {
    srand(time(0));
    Difficulty difficulty;

    int level;
    std::cout << "Choose difficulty (1 - Easy, 2 - Medium, 3 - Hard): ";
    std::cin >> level;

    int wordLength = (level == 1) ? 4 : (level == 2) ? 6 : 8;

    std::string secretWord = difficulty.chooseWord(wordLength);
    if (secretWord.empty()) {
        std::cerr << "No words available for the selected difficulty." << std::endl;
        return 1;
    }

    GameManager* gameManager = GameManager::getInstance(secretWord);
    gameManager->startGame();

    return 0;
}