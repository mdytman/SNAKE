#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeBoard.h"

class SnakeView
{
	SnakeBoard & board;
	sf::RectangleShape square;
	sf::RectangleShape background;
public:
	SnakeView(SnakeBoard & b);
	void draw(sf::RenderWindow & w);
};

