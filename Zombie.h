#pragma once
#include <SFML/Graphics.hpp>

class Zombie {
protected:
    int health;
    int speed;
    int level;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Clock clock; // Add a clock for movement timing
    sf::Vector2f size;

public:
    Zombie(int health, int speed, const std::string& texturePath, const sf::Vector2f& position, const sf::Vector2f& size);
    virtual ~Zombie() = default;
    virtual void move() = 0;
    virtual void attack() = 0;
    void draw(sf::RenderWindow& window);
};
