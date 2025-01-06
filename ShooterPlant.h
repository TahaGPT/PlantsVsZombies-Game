#pragma once
#include "Plant.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
class ShooterPlant : public Plant
{
public :
	Texture bulletTexture;
	Sprite bulletSprite;

	/*virtual void drawBullet(RenderWindow& window);*/
};

