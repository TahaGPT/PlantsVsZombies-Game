#include "Level1.h"
#include"Level.h"
#include"SimpleZombie.h"
#include"SFML/Graphics.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace sf;
using namespace std;
void Level1::spawnZombies(Zombie* zombies[], int& numZombies, const int MAX_ZOMBIES, const int ROWS, const int COLS, const float gridWidth, const float gridHeight) {
    srand(time(0));
    int numToSpawn = (rand() % 5) + 1;
    for (int i = 0; i < numToSpawn; ++i) {
        if (numZombies >= MAX_ZOMBIES) {
            break;
        }
        int row = (rand() % ROWS);
        if (row == 0) {
            Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.5f));
            zombies[numZombies++] = new SimpleZombie(spawnPosition, Vector2f(gridWidth, gridHeight));
        }
        else if (row == 1) {
            Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.35f));
            zombies[numZombies++] = new SimpleZombie(spawnPosition, Vector2f(gridWidth, gridHeight));
        }
        else if (row == 2) {
            Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.25f));
            zombies[numZombies++] = new SimpleZombie(spawnPosition, Vector2f(gridWidth, gridHeight));
        }
        else if (row == 3) {
            Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.1f));
            zombies[numZombies++] = new SimpleZombie(spawnPosition, Vector2f(gridWidth, gridHeight));
        }
        else if (row == 4) {
            Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row - 0.2f));
            zombies[numZombies++] = new SimpleZombie(spawnPosition, Vector2f(gridWidth, gridHeight));
        }

        //Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.1f));

    }
}