#include "pch.h"
#include "SnakeView.h"


SnakeView::SnakeView(SnakeBoard & b) : board(b)
{
	background.setSize(sf::Vector2f(board.getBoardWidth(), board.getBoardWidth()));
	background.setFillColor(sf::Color(253, 246, 111));

	square.setSize(sf::Vector2f(board.getBoardWidth() / 40, board.getBoardHeight() / 40)); //40 - amount of squares
	square.setFillColor(sf::Color(146, 69, 42));
	square.setOutlineThickness(3);
	square.setOutlineColor(sf::Color::White);
}

//wall - edit

void SnakeView::draw(sf::RenderWindow & w)
{
	w.draw(background);
	for (int i = 0; i < 40; ++i)
	{
		if (i <= 1 || i >= 40 - 2)
		{
			for (int j = 0; j < 40; ++j)
			{
				square.setPosition(j*board.getBoardWidth() / 40, i*board.getBoardWidth() / 40);
				w.draw(square);
			}
		}
		else
		{
			for (int j = 0; j < 2; ++j)
			{
				square.setPosition(j*board.getBoardWidth() / 40, i*board.getBoardWidth() / 40);
				w.draw(square);
			}
			for (int k = 40 - 2; k < 40; ++k)
			{
				square.setPosition(k*board.getBoardWidth() / 40, i*board.getBoardWidth() / 40);
				w.draw(square);
			}
		}

	}
}

