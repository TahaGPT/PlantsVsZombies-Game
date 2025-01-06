#include "SimpleZombie.h"
#include"SFML/Graphics.hpp"


SimpleZombie::SimpleZombie(const sf::Vector2f& position, const sf::Vector2f& size)
    : Zombie(100, 1, "Images/Zombie_healthy.png", position, size) {}

void SimpleZombie::move() {
    sprite.move(-speed, 0); // Move forward
}


void SimpleZombie::attack() {
    // Implement attack logic for simple zombie
}
