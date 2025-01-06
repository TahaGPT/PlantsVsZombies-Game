#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <iostream>
#include <cstdlib>

#include "MenuScreen.h"
#include "GameScreen.h"
#include "PauseScreen.h"
#include "InstructionsScreen.h"
#include "LeaderBoardScreen.h"
#include "EndScreen.h"

#include "SunFlower.h"
#include "CherryBomb.h"
#include "PeaShooter.h"
#include "ShooterPlant.h"
#include "Repeater.h"
#include "SnowPea.h"
#include "WallNut.h"
#include "FumeShroom.h"

#include "DancingZombie.h"
#include "FootBallZombie.h"
#include "FlyingZombie.h"
#include "SimpleZombie.h"

#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

#include "Sun.h"

using namespace sf;
using namespace std;
enum class Screen { Menu, Game, Pause, Instructions, Leaderboard };
enum class PlantType { SunFlower, PeaShooter, CherryBomb, SnowPea, WallNut, Repeater, FumeShroom };
enum class LevelNo { Level1, Level2, Level3 };

const int maxPlant = 10;
PeaShooter peashooter[maxPlant];
SunFlower sunflower[maxPlant];
CherryBomb cherrybomb[maxPlant];
Repeater repeater[maxPlant];
WallNut wallnut[maxPlant];
SnowPea snowpea[maxPlant];
FumeShroom fumeshroom[maxPlant];



Level1 level1;
Level2 level2;
Level3 level3;
int numPeaShooters = 0, numSunFlowers = 0, numCherryBombs = 0, numRepeaters = 0, numWallNuts = 0, numSnowPeas = 0, numFumeShrooms = 0;
float x = 0, y = 0;
bool click = 0;
int xID = 360;
int yID = 126;
int xFD = 1515;
int yFD = 841;

Clock spawnClock;
Time spawnInterval = seconds(5); // Set spawn interval to 5 seconds

//const int MAX_ZOMBIES = 10; // Maximum number of zombies allowed
//Zombie* zombies[MAX_ZOMBIES];
//int numZombies = 0;




class Game {


public:
    Game() : window( VideoMode(1650, 932), "SFML Game") {
        // Load textures

        //Vector2f gridSize(window.getSize().x / 9.0f, window.getSize().y / 5.0f);
        //gridWidth = window.getSize().x / COLS;
        //gridHeight = window.getSize().y / ROWS;
        srand(time(NULL));
        if (!menuBackgroundTexture.loadFromFile("Images/Starting_Screene.png")) {
            cout  << "Failed to load menu background texture!" << endl;
        }
        if (!gameBackgroundTexture.loadFromFile("Images/Frontyarde.png")) {
            cout  << "Failed to load game background texture!" <<  endl;
        }
        if (!pauseBackgroundTexture.loadFromFile("Images/Removal-644.png")) {
            cout  << "Failed to load pause background texture!" <<  endl;
        }
        if (!instructionsBackgroundTexture.loadFromFile("Images/Instructions.png")) {
            cout  << "Failed to load instructions background texture!" <<  endl;
        }
        if (!leaderboardBackgroundTexture.loadFromFile("Images/Losing_Message.png")) {
            cout  << "Failed to load leaderboard background texture!" <<  endl;
        }
        if (!font.loadFromFile("Fonts/FFF_Tusj")) {
            cout  << "Failed to load font!" <<  endl;
        }
        

        

        // Set textures to sprites
        menuBackgroundSprite.setTexture(menuBackgroundTexture);
        gameBackgroundSprite.setTexture(gameBackgroundTexture);
        pauseBackgroundSprite.setTexture(pauseBackgroundTexture);
        instructionsBackgroundSprite.setTexture(instructionsBackgroundTexture);
        leaderboardBackgroundSprite.setTexture(leaderboardBackgroundTexture);

        // Initialize screen to menu
        currentScreen = Screen::Menu;
        selectedPlant = PlantType::PeaShooter;
        currentLevel = LevelNo::Level1;
    }

    void run() {


        //Game icon
        Image icon;
        if (!icon.loadFromFile("Images/icon.png"))
        {
            cout  << "Failed to load Icon!" <<  endl;
        }
        window.setIcon(32, 32, icon.getPixelsPtr());
        while (window.isOpen()) {
           

           // cout << Mouse::getPosition().x << " " << Mouse::getPosition().y << endl;
            handleEvents();
            update();
            render();
        }
    }

private:
    void handleEvents() {
         Event event;
        while (window.pollEvent(event)) {
            if ((event.type ==  Event::Closed) || (event.type ==  Event::KeyPressed && event.key.code ==  Keyboard::Escape)) {
                window.close();
            }

            if (event.type ==  Event::KeyPressed) {
                if (event.key.code ==  Keyboard::Space) {
                    if (currentScreen == Screen::Menu) {
                        currentScreen = Screen::Game;
                    }
                    else if (currentScreen == Screen::Pause) {
                        currentScreen = Screen::Game;
                        
                    }
                    else if (currentScreen == Screen::Game)
                    {
                        currentScreen = Screen::Pause;
                    }
                    else if (currentScreen == Screen::Instructions)
                    {
                        currentScreen = Screen::Menu;
                    }
                }
                if (event.key.code == Keyboard::I)
                {
                    if (currentScreen == Screen::Menu) {
                        currentScreen = Screen::Instructions;
                    }

                }
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && !click)
            {

                Vector2i mousePos = Mouse::getPosition(window);
                if(peashooter[0].inventSprite.getGlobalBounds().contains((Vector2f)mousePos))
                {
                    selectedPlant = PlantType::PeaShooter;
                    click = true;
                }                
                if(sunflower[0].inventSprite.getGlobalBounds().contains((Vector2f)mousePos))
                {
                    selectedPlant = PlantType::SunFlower;
                    click = true;
                }
                if(cherrybomb[0].inventSprite.getGlobalBounds().contains((Vector2f)mousePos))
                {
                    selectedPlant = PlantType::CherryBomb;
                    click = true;
                }
                if(repeater[0].inventSprite.getGlobalBounds().contains((Vector2f)mousePos))
                {
                    selectedPlant = PlantType::Repeater;
                    click = true;
                }                
                if(wallnut[0].inventSprite.getGlobalBounds().contains((Vector2f)mousePos))
                {
                    selectedPlant = PlantType::WallNut;
                    click = true;
                }                
                if(snowpea[0].inventSprite.getGlobalBounds().contains((Vector2f)mousePos))
                {
                    selectedPlant = PlantType::SnowPea;
                    click = true;
                }             
                if(fumeshroom[0].inventSprite.getGlobalBounds().contains((Vector2f)mousePos))
                {
                    selectedPlant = PlantType::FumeShroom;
                    click = true;
                }
                

                x = Mouse::getPosition().x;
                y = Mouse::getPosition().y;
            }

            else if (event.type ==  Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && click)
            {
               Vector2i mousePos =  Mouse::getPosition(window);
               switch(selectedPlant) 
               {
               case PlantType::PeaShooter:
               {
                   if (numPeaShooters < maxPlant && Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD) {
                       Vector2i mousePos = Mouse::getPosition(window);
                       x = Mouse::getPosition().x;
                       y = Mouse::getPosition().y;
                       peashooter[numPeaShooters].setP(mousePos.x, mousePos.y);
                       peashooter[numPeaShooters].setBP(mousePos.x + 50, mousePos.y + 5);
                       peashooter[numPeaShooters].clicked = true;
                       numPeaShooters++; // Increase the count of active PeaShooter
                       click = false;
                   }
                   break;
               }

               case PlantType::SunFlower:
               {
                   if (numSunFlowers < maxPlant && Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD) {
                       Vector2i mousePos = Mouse::getPosition(window);
                       x = Mouse::getPosition().x;
                       y = Mouse::getPosition().y;
                       sunflower[numSunFlowers].setP(mousePos.x, mousePos.y);
                       sunflower[numSunFlowers].clicked = true;
                       numSunFlowers++; // Increase the count of active PeaShooter
                       click = false;
                   }
                   break;
               }
               
               case PlantType::CherryBomb:
               {
                   if (numCherryBombs < maxPlant && Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD) {
                       Vector2i mousePos = Mouse::getPosition(window);
                       x = Mouse::getPosition().x;
                       y = Mouse::getPosition().y;
                       cherrybomb[numCherryBombs].setP(mousePos.x, mousePos.y);
                       cherrybomb[numCherryBombs].clicked = true;
                       numCherryBombs++; // Increase the count of active PeaShooter
                       click = false;
                   }
                   break;
               }

               case PlantType::Repeater:
               {
                   if (numRepeaters < maxPlant && Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD) {
                       Vector2i mousePos = Mouse::getPosition(window);
                       x = Mouse::getPosition().x;
                       y = Mouse::getPosition().y;
                       repeater[numRepeaters].setP(mousePos.x, mousePos.y);
                       repeater[numRepeaters].setBP(mousePos.x + 50, mousePos.y + 5);
                       repeater[numRepeaters].clicked = true;
                       numRepeaters++; // Increase the count of active PeaShooter
                       click = false;
                   }
                   break;
               }

               case PlantType::WallNut:
               {
                   if (numWallNuts < maxPlant && Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD) {
                       Vector2i mousePos = Mouse::getPosition(window);
                       x = Mouse::getPosition().x;
                       y = Mouse::getPosition().y;
                       wallnut[numWallNuts].setP(mousePos.x, mousePos.y);
                       wallnut[numWallNuts].clicked = true;
                       numWallNuts++; // Increase the count of active PeaShooter
                       click = false;
                   }
                   break;
               }

               case PlantType::SnowPea:
               {
                   if (numSnowPeas < maxPlant && Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD) {
                       Vector2i mousePos = Mouse::getPosition(window);
                       x = Mouse::getPosition().x;
                       y = Mouse::getPosition().y;
                       snowpea[numSnowPeas].setP(mousePos.x, mousePos.y);
                       snowpea[numSnowPeas].setBP(mousePos.x + 50, mousePos.y + 5);
                       snowpea[numSnowPeas].clicked = true;
                       numSnowPeas++; // Increase the count of active PeaShooter
                       click = false;
                   }
                   break;
               }
               case PlantType::FumeShroom:
               {
                   if (numFumeShrooms < maxPlant && Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD) {
                       Vector2i mousePos = Mouse::getPosition(window);
                       x = Mouse::getPosition().x;
                       y = Mouse::getPosition().y;
                       fumeshroom[numFumeShrooms].setP(mousePos.x, mousePos.y);
                       fumeshroom[numFumeShrooms].setBP(mousePos.x + 50, mousePos.y + 5);
                       fumeshroom[numFumeShrooms].clicked = true;
                       numFumeShrooms++; // Increase the count of active PeaShooter
                       click = false;
                   }
                   break;
               }
               }
            }






        }
    }

    void update() {

        //if (numZombies == 0)
        //{
        //    currentLevel = LevelNo::Level2;
        //}
    }

    void render() {
        window.clear();

        // Draw background
        if (currentScreen == Screen::Menu) {
            window.draw(menuBackgroundSprite);
        }
        else if (currentScreen == Screen::Game) 
        {
            
            window.draw(gameBackgroundSprite);
            for (int i = 0; i < maxPlant; i++)
            {
                sunflower[i].drawInitial(window);
            }            
            for (int i = 0; i < maxPlant; i++)
            {
                cherrybomb[i].drawInitial(window);
            }

            for (int i = 0; i < maxPlant; i++)
            {
                
                peashooter[i].drawInitial(window);
            }            
            for (int i = 0; i < maxPlant; i++)
            {
                
                repeater[i].drawInitial(window);
            }            
            for (int i = 0; i < maxPlant; i++)
            {
                
                wallnut[i].drawInitial(window);
            }
            for (int i = 0; i < maxPlant; i++)
            {
                
                snowpea[i].drawInitial(window);
            }
            for (int i = 0; i < maxPlant; i++)
            {
                
                fumeshroom[i].drawInitial(window);
            }


            for (int i = 0; i < numPeaShooters; i++) {
                if (peashooter[i].clicked == true)
                {
                    peashooter[i].draw(window);
                    peashooter[i].drawBullet(window);
                    peashooter[i].updateBullet();



               
                }
            }            
            for (int i = 0; i < numSnowPeas; i++) {
                if (peashooter[i].clicked == true)
                {
                    peashooter[i].draw(window);
                    peashooter[i].drawBullet(window);
                    peashooter[i].updateBullet();



               
                }
            }
            for (int i = 0; i < numRepeaters; i++) {
                if (repeater[i].clicked == true)
                {
                    repeater[i].draw(window);
                    repeater[i].drawBullet(window);
                    repeater[i].updateBullet();



                }
            }            
            for (int i = 0; i < numSnowPeas; i++) {
                if (snowpea[i].clicked == true)
                {
                    snowpea[i].draw(window);
                    snowpea[i].drawBullet(window);
                    snowpea[i].updateBullet();



                }
            }
            for (int i = 0; i < numFumeShrooms; i++) {
                if (fumeshroom[i].clicked == true)
                {
                    fumeshroom[i].draw(window);
                    fumeshroom[i].drawBullet(window);
                    fumeshroom[i].updateBullet();



                }
            }
            for (int i = 0; i < numSunFlowers; i++) {
                if (sunflower[i].clicked == true)
                {
                    sunflower[i].draw(window);
                }
            }
            for (int i = 0; i < numCherryBombs; i++) {
                if (cherrybomb[i].clicked == true)
                {
                    cherrybomb[i].draw(window);
                }
            }            
            for (int i = 0; i < numWallNuts; i++) {
                if (wallnut[i].clicked == true)
                {
                    wallnut[i].draw(window);
                }
            }

            //if (spawnClock.getElapsedTime() >= spawnInterval) {
            //    level1.spawnZombies(zombies, numZombies, MAX_ZOMBIES, ROWS, COLS, gridWidth, gridHeight);
            //    //level2.spawnZombies(zombies, numZombies, MAX_ZOMBIES, ROWS, COLS, gridWidth, gridHeight);
            //   /* level3.spawnZombies(zombies, numZombies, MAX_ZOMBIES, ROWS, COLS, gridWidth, gridHeight);*/
            //    // Reset the spawn clock
            //    spawnClock.restart();
            //}

            //for (int i = 0; i < numZombies; ++i) {
            //    zombies[i]->move();
            //    zombies[i]->draw(window);
            //}




            //switch (selectedPlant)
            //{
            //case PlantType::PeaShooter :
            //{
            //    for (int i = 0; i < numPeaShooters; i++) {
            //        if (peashooter[i].clicked == true)
            //        {
            //            peashooter[i].draw(window);
            //            peashooter[i].drawBullet(window);
            //            peashooter[i].updateBullet();



            //        }
            //    }
            //    break;
            //}

            //case PlantType::SunFlower:
            //{
            //    for (int i = 0; i < numSunFlowers; i++) {
            //        if (sunflower[i].clicked == true)
            //        {
            //            sunflower[i].draw(window);
            //        }
            //    }
            //    break;
            //}
            //}
            
            //for (int i = 0; i < numZombies; ++i) {
            //    delete zombies[i];
            //}
        }
        else if (currentScreen == Screen::Pause) {
            window.draw(pauseBackgroundSprite);
        }
        else if (currentScreen == Screen::Instructions) {
            window.draw(instructionsBackgroundSprite);
        }
        else if (currentScreen == Screen::Leaderboard) {
            window.draw(leaderboardBackgroundSprite);
        }

        // Draw screens
        // Draw screens in reverse order to ensure they're drawn last
        if (currentScreen == Screen::Menu) {
            // Draw MenuScreen text
            drawText("Menu Screen", 300.f, 100.f);
        }
        else if (currentScreen == Screen::Game) {
            // Draw GameScreen text
            drawText("Game Screen", 300.f, 100.f);
        }
        else if (currentScreen == Screen::Pause) {
            // Draw PauseScreen text
            drawText("Pause Screen", 300.f, 100.f);
        }
        else if (currentScreen == Screen::Instructions) {
            // Draw InstructionsScreen text
            drawText("Instructions Screen", 300.f, 100.f);
        }
        else if (currentScreen == Screen::Leaderboard) {
            // Draw LeaderboardScreen text
            drawText("Leaderboard Screen", 300.f, 100.f);
        }

        window.display();
    }

    void drawText(const  string& text, float x, float y) {
         Text screenText(text, font);
        screenText.setPosition(x, y);
        window.draw(screenText);
    }

private:

    //const int ROWS = 5;
    //const int COLS = 9;
    //float gridWidth;
    //float gridHeight;
    PlantType selectedPlant;
    Screen currentScreen;
    LevelNo currentLevel;
    RenderWindow window;

    //cout << gridWidth << "\t" << gridHeight << endl;

     Texture menuBackgroundTexture;
     Sprite menuBackgroundSprite;

     Texture gameBackgroundTexture;
     Sprite gameBackgroundSprite;

     Texture pauseBackgroundTexture;
     Sprite pauseBackgroundSprite;

     Texture instructionsBackgroundTexture;
     Sprite instructionsBackgroundSprite;

     Texture leaderboardBackgroundTexture;
     Sprite leaderboardBackgroundSprite;

     Texture playerTexture;
     Sprite playerSprite;

     Font font;
};