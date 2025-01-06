#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
class Sun
{
private:
	Texture sunTexture;
	Sprite sunSprite;
	float sunX;
	float sunY;
	Clock clock;



public:
	bool click = false;
	Sun()
	{
		sunTexture.loadFromFile("Images/sun.png");
		sunSprite.setTexture(sunTexture);

	}

	void draw(float x, float y, RenderWindow& window)
	{
		if(!click)
		{
			sunX = x;
			sunSprite.setPosition(x, y);
			window.draw(sunSprite);
			clock.restart();
		}
	}

	void update()
	{
		// Calculate the movement distance based on elapsed time and a constant speed
		float elapsedTime = clock.restart().asSeconds(); // Restart the clock and get the elapsed time
		float moveDistance = sunY * elapsedTime * 10;
		if (sunSprite.getPosition().y >= 1650) {
			sunSprite.setPosition(sunX, moveDistance); // Reset the bullet's position to its initial position
		}
		else {
			sunSprite.move(moveDistance, 0);
		}
	}

};

