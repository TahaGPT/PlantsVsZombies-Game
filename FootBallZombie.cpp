#include "FootballZombie.h"
#include"SFML/Graphics.hpp"
using namespace sf;

FootballZombie::FootballZombie(const sf::Vector2f& position, const sf::Vector2f& size)
    : Zombie(150, 2, "Images/football_zombie.png", position, size) {}


void FootballZombie::move() {
    sprite.move(-speed, 0);
}

void FootballZombie::attack() {
    // Implement attack logic for football zombie
}