#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "SnakeBoard.h"

class Snake : public sf::Drawable
{
	int length;
	int width;
	std::vector <sf::RectangleShape> rect;
	SnakeBoard board;
public:
	Snake(SnakeBoard & sb);

};

