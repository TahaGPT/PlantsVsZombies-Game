#pragma once
#include"Zombie.h"

class FootballZombie : public Zombie {
private:
    sf::Clock clock;
public:
    FootballZombie(const sf::Vector2f& position, const sf::Vector2f& size);
    void move();
    void attack();
};

