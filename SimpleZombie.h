#pragma once
#include "Zombie.h"
#include"SFML/Graphics.hpp"

class SimpleZombie : public Zombie {
public:
    SimpleZombie(const sf::Vector2f& position, const sf::Vector2f& size);
    void move();
    void attack();
};


