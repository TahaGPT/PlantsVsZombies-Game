#pragma once
#include "PlantFactory.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
class Plant : public PlantFactory
{
protected:
	int life;
	int cost;


public:
	Texture inventTexture;
	Sprite inventSprite;
	Texture flowerTexture;
	Sprite flowerSprite;
	int itemNo = 0;
	bool clicked = false;
	//virtual void draw(RenderWindow& window);// = 0;
	//virtual void drawInitial(RenderWindow& window);// = 0;


};


