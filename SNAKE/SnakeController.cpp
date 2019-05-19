#include "pch.h"
#include "SnakeController.h"


SnakeController::SnakeController(SnakeView & v, SnakeBoard & b) : view(v), board(b)
{
}

void SnakeController::handleEvent(sf::Event & event)
{
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
