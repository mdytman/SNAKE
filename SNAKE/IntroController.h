#pragma once
#include "IntroView.h"
#include "SnakeBoard.h"

class IntroController
{
	bool finished = false;
	IntroView & view;
	SnakeBoard & board;
public:
	IntroController(IntroView & v, SnakeBoard & b);
	void handleEvent(sf::Event &event);
	void draw(sf::RenderWindow & win) { view.draw(win); }
};

