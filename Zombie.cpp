#include "Zombie.h"
#include<iostream>
using namespace std;

Zombie::Zombie(int health, int speed, const string& texturePath, const sf::Vector2f& position, const sf::Vector2f& gridSize)
    : health(health), speed(speed), position(position) {
    if (!texture.loadFromFile(texturePath)) {
        // Handle error when loading texture
        cout << "Error loading texture: " << texturePath << endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
    float zombieSize = std::min(gridSize.x / sprite.getTexture()->getSize().x, gridSize.y / sprite.getTexture()->getSize().y);
    sprite.setScale(zombieSize, zombieSize);
}
void Zombie::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

