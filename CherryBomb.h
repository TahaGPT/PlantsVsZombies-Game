#pragma once
#include "Plant.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
class CherryBomb :
    public Plant
{
private:
	int unlockLevel = 1;

public:
	CherryBomb()
	{
		flowerTexture.loadFromFile("Images/cherry.png");
		flowerSprite.setTexture(flowerTexture);
		inventTexture.loadFromFile("Images/Removal-22.png");
		inventSprite.setTexture(inventTexture);


	}

	void draw(RenderWindow& window)
	{


		flowerSprite.setScale(0.05f, 0.05f);
		//flowerSprite.setPosition(260, 80);

		window.draw(flowerSprite);

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
			inventSprite.setPosition(0, 200);
			window.draw(inventSprite);
		}


	}


	void setP(float x, float y)
	{
		flowerSprite.setPosition(x, y);

	}
};

