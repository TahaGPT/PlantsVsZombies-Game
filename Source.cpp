#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>


#include "Game.h"
using namespace sf;
using namespace std;

//Taha Ahmed 23i-0532
//Abdullah Bin Nasir 23i=0803
//CS - A

int main() {
	Game game;
	game.run();
	cout << "HEllo";

	return 0;
}

//
//
//struct coordinats 
//{
//	int x;
//	int y;
//};
//
//const int boxPixelsX = 74;
//const int boxPixelsY = 100;
//int leftDist = 250;
//int upDist = 75;
//
//int xID = 360;
//int yID = 126;
//int xFD = 1515;
//int yFD = 841;
//
//
//
//
//
//
//
//
//
//
//int main()
//{
//
//	
//	RenderWindow window(VideoMode(1986,900), "Main Menu", Style::Fullscreen);
//
//	////Game icon
//	Image icon;
//	if (!icon.loadFromFile("Images/icon.png"))
//	{
//		return 1;
//	}
//	window.setIcon(32, 32, icon.getPixelsPtr());
//	MenuScreen Main;
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				window.close();
//			}
//
//			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return)
//			{
//				RenderWindow Play(VideoMode(1986, 900), "Plants Vs Zombies", Style::Fullscreen);
//				RenderWindow Instructions(VideoMode(1986, 900), "Instructions", Style::Fullscreen);
//
//				int x = Main.MenuScreenPressed();
//				if (x == 0)
//				{
//
//				}
//			}
//
//		}
//	}
//	
//	return 0;
//}

//#include <SFML/Graphics.hpp>





//Drawing the background
//void createBack(RenderWindow& window) {
//	//Drawing the background
//	Image map_image;
//	map_image.loadFromFile("Images/Starting_Screene.png");
//	Texture map;
//	map.loadFromImage(map_image);
//	Sprite s_map;
//	s_map.setTexture(map);
//	s_map.setPosition(0, 0);
//	window.draw(s_map);
//}

//Drawing the map
//void createMap(RenderWindow& window) {
//	//Drawing a map
//	Image map_image;//объект изображения для карты
//	map_image.loadFromFile("Images/Frontyardedit.png");//load the file for the map
//	Texture map;
//	map.loadFromImage(map_image);
//	Sprite s_map;
//	s_map.setTexture(map);
//	s_map.setPosition(0, 0);
//
//	window.draw(s_map);
//}


//MenuScreen menu;
	//menu.active = true;
	//GameScreen game;
	//PauseScreen pause;
	//InstructionsScreen instructions;
	//LeaderBoardScreen leader;
	//EndScreen end;


	//SunFlower* Sf = new SunFlower[45];
	//int cSf = 0;


	////Create a window, n*n
	//RenderWindow window(VideoMode(1060, 600), "Plants Vs Zombies");
	//window.setPosition(Vector2i(0, 0)); // Set window position

	//
	////Game icon
	//Image icon;
	//if (!icon.loadFromFile("Images/icon.png"))
	//{
	//	return 1;
	//}
	//window.setIcon(32, 32, icon.getPixelsPtr());

	/////////////////////////////////////////

	////Game field (5*9)
	////Point 137*79 - leftmost point
	////length 41; width 53
	//const int ROWS = 5;
	//const int COLS = 9;

	//bool FIELD_GAME_STATUS[ROWS][COLS];

	//for (int i = 0; i < ROWS; i++) {
	//	for (int j = 0; j < COLS; j++) {
	//		FIELD_GAME_STATUS[i][j] = true;
	//	}
	//}

	//Clock timeMoney;


	//bool drawSunflower = false, clicked = false;
	//Clock clock;

	//int mouseCatchX = 0, mouseCatchY = 0;


	//while (window.isOpen())
	//{
	//	float time = clock.getElapsedTime().asMicroseconds();
	//	float moneyTime = timeMoney.getElapsedTime().asSeconds();

	//	clock.restart();
	//	time = time / 800;
	//
	//	//cout <<  Mouse::getPosition(window).x << " " <<  Mouse::getPosition(window).y << endl;
	//	Event event;
	//	while (window.pollEvent(event))
	//	{


	//		if (event.type == Event::Closed)
	//			window.close();

	//		if (event.type ==  Event::KeyPressed && event.key.code ==  Keyboard::Space) // Change screen on space key press
 //  		    {
	//			cout << "opening second screen" << endl;
	//			menu.active = false;
	//			
	//            game.active = true;
	//        }

	//		if (event.type ==  Event::KeyPressed && event.key.code ==  Keyboard::Escape) // Change screen on space key press
	//		{
	//			window.close();
	//		}

	//		//if (drawSunflower)
	//		//{
	//		//	if (event.type ==  Event::MouseButtonPressed && event.key.code == Mouse::Left && game.active && drawSunflower)
	//		//	{
	//		//		cout << "SecondCLick\n";
	//		//		auto mouse_pos =  Mouse::getPosition(window);
	//		//		auto translated_pos = window.mapPixelToCoords(mouse_pos);
	//		//		Sf.draw(window, translated_pos);
	//		//	}
	//		//}
	//		if (event.type ==  Event::MouseButtonPressed && event.key.code == Mouse::Left && game.active && drawSunflower == false)
	//		{
	//			auto mouse_pos =  Mouse::getPosition(window);
	//			auto translated_pos = window.mapPixelToCoords(mouse_pos);
	//			if (Sf[cSf].inventSprite.getGlobalBounds().contains(translated_pos))
	//			{
	//				drawSunflower = true;
	//				cout << "1st Click\n";
	//			}
	//		}
	//		else if (event.type ==  Event::MouseButtonPressed && event.key.code == Mouse::Left && game.active && drawSunflower == true)
	//		{
	//			auto mouse_pos =  Mouse::getPosition(window);
	//			auto translated_pos = window.mapPixelToCoords(mouse_pos);
	//			if (Mouse::getPosition(window).x >= xID && Mouse::getPosition(window).y >= yID && Mouse::getPosition(window).x <= xFD && Mouse::getPosition(window).y <= yFD)
	//			{
	//				if (drawSunflower == true) {
	//					cout << "2nd Click" << endl;
	//					clicked = true;
	//					mouseCatchX = Mouse::getPosition(window).x;
	//					mouseCatchY = Mouse::getPosition(window).y;
	//					drawSunflower = false;
	//				}

	//			}
	//		}


	//	}




	//	


	//	//Create a background
	///*	createBack(window);*/
	//	//createMap(window);



	//	window.clear();
	//	if (menu.active) menu.draw(window); //the cool thing about the objects is you can just use the draw function you made inside them and dont even care about adding or changing anything else here
	//	else if (game.active) game.draw(window);
	//	if (game.active)
	//	{
	//		Sf[cSf].drawInitial(window);


	//	}
	//	if (game.active && clicked)
	//	{
	//		Sf[2].draw(window, mouseCatchX, mouseCatchY);
	//		clicked = false;

	//	}
	//	window.setSize( Vector2u(1650, 900));

	//	window.display();
	//}