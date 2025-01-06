#pragma once
#include "screen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
using namespace sf;
using namespace std;
class MenuScreen : public screen
{
private:
    int MainMenuSelected;
public:
    Texture menuTexture;
    Sprite menuSprite;


    MenuScreen()
    {
        menuTexture.loadFromFile("Images/Starting_Screene.png");
        menuSprite.setTexture(menuTexture);
        MainMenuSelected = -1;

    }

    void draw(RenderWindow& window)
    {
        window.draw(menuSprite);
    }

    int MainMenuPressed()
    {
        return MainMenuSelected;
    }
};

