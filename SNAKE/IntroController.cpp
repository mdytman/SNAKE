#include "pch.h"
#include "IntroController.h"


IntroController::IntroController(IntroView & v, SnakeBoard & b) : view(v), board(b)
{
}

void IntroController::handleEvent(sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			if ((event.mouseButton.x > board.getBoardWidth() / 3) && (event.mouseButton.x < board.getBoardWidth() / 3 + board.getBoardWidth() / 3) && (event.mouseButton.y > board.getBoardHeight() - board.getBoardHeight() / 4) && (event.mouseButton.y < board.getBoardHeight() - board.getBoardHeight() / 4 + board.getBoardHeight() / 12))
			{
				finished = true;
			}
		}
	}
}



