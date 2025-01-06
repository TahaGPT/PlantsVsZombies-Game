#pragma once
#include "Plant.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
class SunFlower : public Plant
{
private:
	int unlockLevel = 1;
	int sun = 10;

public:
	Texture sunTexture;
	Sprite sunSprite;


	SunFlower()
	{
		flowerTexture.loadFromFile("Images/Sunflower.png");
		flowerSprite.setTexture(flowerTexture);
		inventTexture.loadFromFile("Images/icon_sunflower.png");
		inventSprite.setTexture(inventTexture);
		sunTexture.loadFromFile("Images/sun.png");
		sunSprite.setTexture(sunTexture);


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
			inventSprite.setPosition(0, 100);
			window.draw(inventSprite);
		}


	}


	void setP(float x, float y)
	{
		flowerSprite.setPosition(x, y);

	}
};

