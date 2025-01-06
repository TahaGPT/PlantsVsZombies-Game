#pragma once

#include "Zombie.h"

class FlyingZombie : public Zombie {
public:
    FlyingZombie(const sf::Vector2f& position, const sf::Vector2f& size);
    void move();
    void attack();
};
