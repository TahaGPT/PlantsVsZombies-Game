#pragma once
#include "screen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
class GameScreen : public screen
{
public:
	Texture gameTexture;
	Sprite gameSprite;

	GameScreen()
	{
		gameTexture.loadFromFile("Images\\Frontyardedit.png");
		gameSprite.setTexture(gameTexture);
	}

	void draw(RenderWindow& window)
	{
		window.draw(gameSprite);
	}

};

