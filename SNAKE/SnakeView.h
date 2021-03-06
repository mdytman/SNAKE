#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeBoard.h"

class SnakeView
{
	SnakeBoard & board;
	sf::RectangleShape wall;
	sf::RectangleShape background;
	sf::RectangleShape snake;
	sf::RectangleShape snakeHead;
	sf::RectangleShape feed; 
	sf::Texture feedTexture;
	sf::Text scoreText;
	sf::Font font;
	sf::Text spaceText;
public:
	SnakeView(SnakeBoard & b);
	void draw(sf::RenderWindow & w);
};

