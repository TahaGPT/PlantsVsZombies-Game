#pragma once
#include"Level.h"
#include"Zombie.h"
class Level1 : public Level
{
public:
	void spawnZombies(Zombie* zombies[], int& numZombies, const int MAX_ZOMBIES, const int ROWS, const int COLS, const float gridWidth, const float gridHeight);
};

