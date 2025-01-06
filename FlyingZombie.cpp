#include "FlyingZombie.h"

FlyingZombie::FlyingZombie(const sf::Vector2f& position, const sf::Vector2f& size)
    : Zombie(100, 2, "Images/flying_zombie.png", position, size) {}


void FlyingZombie::move() {
    sprite.move(-speed, 0);
}

void FlyingZombie::attack() {
    // Implement attack logic for flying zombie
}