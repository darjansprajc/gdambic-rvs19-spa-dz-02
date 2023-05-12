#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace std;

class game_of_life {
private:

	static const unsigned int STUPACA = 600;
	static const unsigned int REDAKA = 800;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();


	sf::RenderWindow* window;
	sf::RectangleShape organism;
	vector<sf::RectangleShape >* organisms = new vector<sf::RectangleShape>;

public:
	game_of_life(sf::RenderWindow* window);
	void sljedeca_generacija();
	void iscrtaj();
};

#endif
