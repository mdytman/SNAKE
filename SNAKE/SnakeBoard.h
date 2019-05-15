#pragma once
#include <SFML/Graphics.hpp>
class SnakeBoard
{
	int height;
	int width;
	sf::RectangleShape square;
	sf::RectangleShape background;
public:
	SnakeBoard(int h, int w);
	int getBoardHeight();
	int getBoardWidth();
	void draw(sf::RenderWindow &w);
};

