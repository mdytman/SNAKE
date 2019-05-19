#pragma once
#include <SFML/Graphics.hpp>
#include "SnakeView.h"
#include "SnakeBoard.h"

class SnakeController {

	bool finished = false;
	SnakeView & view;
	SnakeBoard & board;

public:
	explicit SnakeController(SnakeView & v, SnakeBoard & b);
public:
	void handleEvent(sf::Event &event);
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};
