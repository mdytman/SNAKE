#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeBoard.h"

class ScoreView
{
	SnakeBoard & board;
	sf::Text gameOver;
	sf::Font font1;
	sf::Text scoreText;
	sf::Font font2;
	sf::RectangleShape background;
public:
	ScoreView(SnakeBoard & b);
	void draw(sf::RenderWindow &win);
	
};

