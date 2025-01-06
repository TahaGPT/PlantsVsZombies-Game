#include "DancingZombie.h"
#include"Zombie.h"
#include"SimpleZombie.h"
#include<iostream>
using namespace std;
using namespace sf;
DancingZombie::DancingZombie(const sf::Vector2f& position, const sf::Vector2f& size)
    : Zombie(100, 3, "Images/dancing_zombie.png", position, size) {}



void DancingZombie::move() {
    if (position == Vector2f(133 * 8, 120 * 0.5)) {
        sprite.move(-speed, 1);
    } // Move diagonally
    else if (position == Vector2f(133 * 8, 120 * 3.8)) {
        sprite.move(-speed, -1);
    }
    else {
        sprite.move(-speed, 0);
    }
}

void DancingZombie::summonSimpleZombies(Zombie* zombies[], int& numZombies, const int MAX_ZOMBIES) {
    // Summon SimpleZombies around the DancingZombie
    for (int i = 0; i < 3; ++i) { // Summon 3 SimpleZombies

        // Calculate the position relative to the DancingZombie position
        Vector2f summonPosition = position + Vector2f(50 * i, 0);

        // Create and add a new SimpleZombie to the array
        zombies[numZombies++] = new SimpleZombie(summonPosition, Vector2f(133, 120));

        //print the position of the summoned zombie for debugging
        cout << "Summoned SimpleZombie at position: " << summonPosition.x << ", " << summonPosition.y << std::endl;
    }
}

void DancingZombie::attack() {
    // attack logic for dancing zombie
}