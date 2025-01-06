#pragma once

#include "Zombie.h"

class DancingZombie : public Zombie {
public:
    DancingZombie(const sf::Vector2f& position, const sf::Vector2f& size);
    void move();
    void summonSimpleZombies(Zombie* zombies[], int& numZombies, const int MAX_ZOMBIES);
    void attack();
};

