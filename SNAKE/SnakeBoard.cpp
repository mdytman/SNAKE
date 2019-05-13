#include "pch.h"
#include "SnakeBoard.h"


SnakeBoard::SnakeBoard(int h, int w) : height(h), width(w)
{
	background.setSize(sf::Vector2f(height, width));
	background.setFillColor(sf::Color(253, 246, 111));

	square.setSize(sf::Vector2f(width/40, width/40)); //40 - amount of squares
	square.setFillColor(sf::Color(146, 69, 42));
	square.setOutlineThickness(3);
	square.setOutlineColor(sf::Color::White);
}

unsigned int SnakeBoard::getBoardHeight()
{
	return height;
}

unsigned int SnakeBoard::getBoardWidth()
{
	return width;
}

void SnakeBoard::draw(sf::RenderWindow & w)
{
	w.draw(background);
	for (int i = 0; i < 40; ++i)
	{
		if (i <= 1 || i >= 40 - 2)
		{
			for (int j = 0; j < 40; ++j)
			{
				square.setPosition(j*width / 40, i*width / 40);
				w.draw(square);
			}
		}
		else
		{
			for (int j = 0; j < 2; ++j)
			{
				square.setPosition(j*width / 40, i*width / 40);
				w.draw(square);
			}
			for (int k = 40 - 2; k < 40; ++k)
			{
				square.setPosition(k*width / 40, i*width / 40);
				w.draw(square);
			}
		}
		
	}
}

