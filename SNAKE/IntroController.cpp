//#include "pch.h"
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
			if ((event.mouseButton.x > board.getWindowWidth() / 3) && (event.mouseButton.x < board.getWindowWidth() / 3 + board.getWindowWidth() / 3) && (event.mouseButton.y > board.getWindowHeight() - board.getWindowHeight() / 4) && (event.mouseButton.y < board.getWindowHeight() - board.getWindowHeight() / 4 + board.getWindowHeight() / 12))
			{
				finished = true;
			}
		}
	}
}



