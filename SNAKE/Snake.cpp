#include "pch.h"
#include "Snake.h"


Snake::Snake(SnakeBoard & sb) : board(sb)
{
	length = 25;
	width = 25;
	for (int i = 0; i < rect.size(); ++i)
	{
		rect[i].setSize(sf::Vector2f(width, length));
		rect[i].setFillColor(sf::Color::Green);
		rect[i].setPosition(sf::Vector2f(board.getBoardHeight()/2, board.getBoardWidth()/2));
	}
}

