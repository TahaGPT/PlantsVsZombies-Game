#pragma once
#include "Level.h"

class Level2 : public Level {
public:
    void spawnZombies(Zombie* zombies[], int& numZombies, const int MAX_ZOMBIES, const int ROWS, const int COLS, const float gridWidth, const float gridHeight);
};

