#include "game_of_life.h"



bool game_of_life::slucajna_vrijednost()
{
	int n = rand() % (4 - 1 + 1) + 1;
	if (n == 1)
		return true;
	else
		return false;
}

game_of_life::game_of_life(sf::RenderWindow *window)
{
	this->window = window;

	sf::RectangleShape organism(sf::Vector2f(1.f, 1.f));
	organism.setFillColor(sf::Color::Blue);

	srand(time(nullptr));

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
			if(_generacija[i][j])
				organisms->push_back(organism);
		}
	}
}

void game_of_life::sljedeca_generacija()
{
	sf::RectangleShape organism(sf::Vector2f(1.f, 1.f));
	organism.setFillColor(sf::Color::Blue);
	organisms->clear();

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			int neighbours = 0;
			
			//gornji lijevi kut
			if (i == 0 && j == 0)
			{
				if (_generacija[i][j + 1])
					neighbours++;
				if (_generacija[i + 1][j + 1])
					neighbours++;
				if (_generacija[i + 1][j])
					neighbours++;
				if (_generacija[REDAKA][j + 1])
					neighbours++;
				if (_generacija[REDAKA][j])
					neighbours++;
				if (_generacija[REDAKA][STUPACA])
					neighbours++;
				if (_generacija[i][STUPACA])
					neighbours++;
				if (_generacija[i+1][STUPACA])
					neighbours++;
			}
			//gornji desni kut
			else if (i==0 && j == STUPACA)
			{
				if (_generacija[i][j - 1])
					neighbours++;
				if (_generacija[i + 1][j - 1])
					neighbours++;
				if (_generacija[i + 1][j])
					neighbours++;
				if (_generacija[REDAKA][0])
					neighbours++;
				if (_generacija[REDAKA][j])
					neighbours++;
				if (_generacija[REDAKA][j - 1])
					neighbours++;
				if (_generacija[i][0])
					neighbours++;
				if (_generacija[i + 1][0])
					neighbours++;
			}
			//donji lijevi kut
			else if (i == REDAKA && j == 0)
			{
				if (_generacija[i - 1][j])
					neighbours++;
				if (_generacija[i - 1][j + 1])
					neighbours++;
				if (_generacija[i + 1][j + 1])
					neighbours++;
				if (_generacija[i+1][STUPACA])
					neighbours++;
				if (_generacija[i][STUPACA])
					neighbours++;
				if (_generacija[0][STUPACA])
					neighbours++;
				if (_generacija[0][j])
					neighbours++;
				if (_generacija[0][j+1])
					neighbours++;
			}
			//donji desni kut
			else if (i == REDAKA && j == STUPACA)
			{
				if (_generacija[i - 1][j])
					neighbours++;
				if (_generacija[i - 1][j - 1])
					neighbours++;
				if (_generacija[i][j - 1])
					neighbours++;
				if (_generacija[0][0])
					neighbours++;
				if (_generacija[i+1][0])
					neighbours++;
				if (_generacija[i][0])
					neighbours++;
				if (_generacija[0][j])
					neighbours++;
				if (_generacija[0][j - 1])
					neighbours++;
			}
			//gornji rub
			if (i == 0)
			{
				if (_generacija[i][j - 1])
					neighbours++;
				if (_generacija[i][j + 1])
					neighbours++;
				if (_generacija[i + 1][j - 1])
					neighbours++;
				if (_generacija[i + 1][j])
					neighbours++;
				if (_generacija[i + 1][j + 1])
					neighbours++;
				if (_generacija[REDAKA][j - 1])
					neighbours++;
				if (_generacija[REDAKA][j])
					neighbours++;
				if (_generacija[REDAKA][j + 1])
					neighbours++;
			}

			//donji rub
			else if (i == REDAKA)
			{
				if (_generacija[i - 1][j - 1])
					neighbours++;
				if (_generacija[i - 1][j])
					neighbours++;
				if (_generacija[i - 1][j + 1])
					neighbours++;
				if (_generacija[i][j - 1])
					neighbours++;
				if (_generacija[i][j + 1])
					neighbours++;
				if (_generacija[0][j - 1])
					neighbours++;
				if (_generacija[0][j])
					neighbours++;
				if (_generacija[0][j + 1])
					neighbours++;
			}

			//lijevi rub
			else if (j == 0)
			{
				if (_generacija[i - 1][j])
					neighbours++;
				if (_generacija[i - 1][j + 1])
					neighbours++;
				if (_generacija[i][j + 1])
					neighbours++;
				if (_generacija[i + 1][j + 1])
					neighbours++;
				if (_generacija[i + 1][j])
					neighbours++;
				if (_generacija[i + 1][STUPACA])
					neighbours++;
				if (_generacija[i][STUPACA])
					neighbours++;
				if (_generacija[i - 1][STUPACA])
					neighbours++;
			}

			//desni rub
			else if (j == STUPACA)
			{
				if (_generacija[i - 1][j])
					neighbours++;
				if (_generacija[i + 1][j])
					neighbours++;
				if (_generacija[i - 1][j - 1])
					neighbours++;
				if (_generacija[i][j - 1])
					neighbours++;
				if (_generacija[i + 1][j - 1])
					neighbours++;
				if (_generacija[i + 1][0])
					neighbours++;
				if (_generacija[i][0])
					neighbours++;
				if (_generacija[i - 1][0])
					neighbours++;
			}
			
			//svi ostali organizmi
			else
			{
				if (_generacija[i - 1][j - 1])
					neighbours++;
				if (_generacija[i - 1][j])
					neighbours++;
				if (_generacija[i - 1][j + 1])
					neighbours++;
				if (_generacija[i][j - 1])
					neighbours++;
				if (_generacija[i - 1][j + 1])
					neighbours++;
				if (_generacija[i + 1][j - 1])
					neighbours++;
				if (_generacija[i + 1][j])
					neighbours++;
				if (_generacija[i + 1][j + 1])
					neighbours++;
			}

			//izracunavanje zivota ili smrti sljedece generacije
			if (_generacija[i][j] && neighbours < 2)
				_sljedeca_generacija[i][j] = false;

			else if (_generacija[i][j] && neighbours > 3)
				_sljedeca_generacija[i][j] = false;

			else if (!_generacija[i][j] && neighbours == 3)
			{
				_sljedeca_generacija[i][j] = true;
				organisms->push_back(organism);
			}
			else if (_generacija[i][j])
			{
				_sljedeca_generacija[i][j] = true;
				organisms->push_back(organism);
			}
			else if (!_generacija[i][j])
				_sljedeca_generacija[i][j] = false;

		}
	}
	//kopiranje sljedece u trenutnu generaciju
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}

}

void game_of_life::iscrtaj()
{
	int counter = 0;
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_generacija[i][j])
			{
				(*organisms)[counter].setPosition(i, j);
				window->draw((*organisms)[counter]);
				counter++;
			}
		}
	}

}
