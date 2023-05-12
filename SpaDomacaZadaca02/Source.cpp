#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include "game_of_life.h"
using namespace std;
using namespace std::this_thread;
using namespace std::chrono; 

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(60);

	//pocetna generacija
	game_of_life the_game(&window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
		}

		window.clear();

		//iscrtavanje
		the_game.iscrtaj();
		
		window.display();

		the_game.sljedeca_generacija();
		
		//pricekaj 2 sekunde
		//sleep_for(seconds(2));
	}

	return 0;
}