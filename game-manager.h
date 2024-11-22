#pragma once

#include "word.h"
#include "player.h"
#include "display.h"

class GameManager {
private:
    int maxAttempts;
    int currentAttempts;
    bool isGameOver;

    Word word;
    Player player;
    Display display;

    static GameManager* instance;

    GameManager(const std::string& secretWord, int maxAttempts = 6);

    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
public:
    static GameManager* getInstance(const std::string& secretWord, int maxAttempts = 6);

    void startGame();
    void displayState() const;
};