#pragma once
#include"Zombie.h"
class Level {
public:
    virtual void spawnZombies(Zombie* zombies[], int& numZombies, const int MAX_ZOMBIES, const int ROWS, const int COLS, const float gridWidth, const float gridHeight) = 0;
};