#include "Level2.h"
#include"SimpleZombie.h"
#include"DancingZombie.h"
#include"FootballZombie.h"
#include"FlyingZombie.h"
#include"Zombie.h"
#include<cstdlib>
#include<ctime>
using namespace sf;

void Level2::spawnZombies(Zombie* zombies[], int& numZombies, const int MAX_ZOMBIES, const int ROWS, const int COLS, const float gridWidth, const float gridHeight) {
    // Calculate the number of zombies to spawn without exceeding the maximum allowed
    srand(time(0));
    int numToSpawn = (rand() % 5) + 1;

    // Spawn zombies randomly in random rows
    for (int i = 0; i < numToSpawn; ++i) {

        int row = rand() % ROWS; // Randomly select a row
        if (numZombies == MAX_ZOMBIES) {
            break;
        }
        // Randomly select a type of zombie to spawn
        switch (rand() % 4) { // Assuming there are 4 types of zombies
        case 0:
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
            break;
        case 1:
            if (row == 0) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.5f));
                zombies[numZombies++] = new FootballZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 1) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.35f));
                zombies[numZombies++] = new FootballZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 2) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.25f));
                zombies[numZombies++] = new FootballZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 3) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.1f));
                zombies[numZombies++] = new FootballZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 4) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row - 0.2f));
                zombies[numZombies++] = new FootballZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            break;
        case 2:
            if (row == 0) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.5f));
                zombies[numZombies++] = new FlyingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 1) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.35f));
                zombies[numZombies++] = new FlyingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 2) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.25f));
                zombies[numZombies++] = new FlyingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 3) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.1f));
                zombies[numZombies++] = new FlyingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 4) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row - 0.2f));
                zombies[numZombies++] = new FlyingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            break;
        case 3:
            if (row == 0) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.5f));
                zombies[numZombies++] = new DancingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 1) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row - 0.5f));
                zombies[numZombies++] = new DancingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 2) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row - 1.5f));
                zombies[numZombies++] = new DancingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 3) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row + 0.8f));
                zombies[numZombies++] = new DancingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            else if (row == 4) {
                Vector2f spawnPosition = Vector2f(gridWidth * (COLS - 1), gridHeight * (row - 0.2f));
                zombies[numZombies++] = new DancingZombie(spawnPosition, Vector2f(gridWidth, gridHeight));

            }
            break;
        }
    }
}