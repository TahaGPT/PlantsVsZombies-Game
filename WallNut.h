#pragma once
#include "Plant.h"

class WallNut : public Plant
{
private:
	int unlockLevel = 1;

public:
	WallNut()
	{
		flowerTexture.loadFromFile("Images/Wallnut_body.png");
		flowerSprite.setTexture(flowerTexture);
		inventTexture.loadFromFile("Images/wall.png");
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
			inventSprite.setPosition(0, 400);
			window.draw(inventSprite);
		}


	}


	void setP(float x, float y)
	{
		flowerSprite.setPosition(x, y);

	}
};

