#pragma once
#include "Plant.h"
#include "ShooterPlant.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
class PeaShooter : public ShooterPlant
{
private:
	int unlockLevel = 1;
	float bulletX;
	float bulletY;
	int b = 10;
	Clock clock;

public:
	PeaShooter()
	{
		flowerTexture.loadFromFile("Images/Peashootere.png");
		flowerSprite.setTexture(flowerTexture);
		bulletTexture.loadFromFile("Images/pea.png");
		bulletSprite.setTexture(bulletTexture);
		inventTexture.loadFromFile("Images/icon_peashooter.png");
		inventSprite.setTexture(inventTexture);


	}

	void draw(RenderWindow& window)
	{


		flowerSprite.setScale(0.05f, 0.05f);
		//flowerSprite.setPosition(260, 80);
	
		window.draw(flowerSprite);
		
		clock.restart();
	}

	void checkUnlock(int lev)
	{
		if (lev >= unlockLevel)
		{
			unlocked = true;
		}
	}

	void drawInitial(RenderWindow& window)
	{
		

		int lev = 1;
		checkUnlock(lev);
		if (unlocked)
		{
			inventSprite.setScale(0.5f, 0.5f); // Set scale
			inventSprite.setPosition(0, 0);
			window.draw(inventSprite);
		}


	}

	//void updateBullet() {
	//	/*float elapsedTime = clock.getElapsedTime().asSeconds()*/;
	//	/*float moveDistance = bulletX * elapsedTime;*/
	//	float moveDistance = bulletX + b++;
	//	bulletSprite.setPosition(moveDistance, bulletY);
	//
	//}

	void updateBullet() {
		// Calculate the movement distance based on elapsed time and a constant speed
		float elapsedTime = clock.restart().asSeconds(); // Restart the clock and get the elapsed time
		float moveDistance = bulletX * elapsedTime * 100; // Multiply the speed by a factor (e.g., 2.0) to increase the speed
		if (bulletSprite.getPosition().x >= 1650) {
			bulletSprite.setPosition(bulletX, bulletY); // Reset the bullet's position to its initial position
		}
		else {
			bulletSprite.move(moveDistance, 0); // Move the bullet horizontally
		}
	}

	

	void setP(float x, float y)
	{
		flowerSprite.setPosition(x, y);

	}

	void setBP(float x, float y)
	{
		bulletX = x;
		bulletY = y;
		bulletSprite.setPosition(bulletX, bulletY);
		
	}

	void drawBullet(RenderWindow& window)
	{
		
		
		bulletSprite.setScale(0.15f, 0.15f);
	

		window.draw(bulletSprite);
	}

};

