#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeBoard.h"

class IntroView
{
	sf::Font font1;
	sf::Font font2;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::RectangleShape background;
	sf::RectangleShape playButton;
	SnakeBoard board;
public:
	IntroView(SnakeBoard & sb);
	void draw(sf::RenderWindow & win);
};

