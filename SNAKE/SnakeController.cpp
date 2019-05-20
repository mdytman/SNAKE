#include "pch.h"
#include "SnakeController.h"


SnakeController::SnakeController(SnakeView & v, SnakeBoard & b) : view(v), board(b)
{
}

void SnakeController::handleEvent(sf::Event & event)
{

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Right)
		{
			board.changeDirection(RIGHT);
		}
		if (event.key.code == sf::Keyboard::Left)
		{
			board.changeDirection(LEFT);
		}
		if (event.key.code == sf::Keyboard::Up)
		{
			board.changeDirection(UP);
		}
		if (event.key.code == sf::Keyboard::Down)
		{
			board.changeDirection(DOWN);
		}
	}
	board.move();
	board.lengthenSnake();

	if (board.getGameState() != RUNNING)
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				finished = true;
			}
		}
	}
}
