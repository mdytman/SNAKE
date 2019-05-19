#include "pch.h"
#include "SnakeView.h"


SnakeView::SnakeView(SnakeBoard & b) : board(b)
{
	background.setSize(sf::Vector2f(board.getWindowWidth(), board.getWindowWidth()));
	background.setFillColor(sf::Color(253, 246, 111));

	wall.setSize(sf::Vector2f(board.getWindowWidth() / board.getBoardWidth(), board.getWindowHeight() / board.getBoardHeight())); 
	wall.setFillColor(sf::Color(146, 69, 42));
	wall.setOutlineThickness(3);
	wall.setOutlineColor(sf::Color::White);

	snake.setSize(sf::Vector2f(board.getWindowWidth() / board.getBoardWidth(), board.getWindowHeight() / board.getBoardHeight())); 
	snake.setFillColor(sf::Color(48, 86, 48));

	feed.setSize(sf::Vector2f(board.getWindowWidth() / board.getBoardWidth(), board.getWindowHeight() / board.getBoardHeight()));
	feed.setFillColor(sf::Color::Red);	

	if (!font.loadFromFile("silkscreen.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	scoreText.setFont(font);
	scoreText.setCharacterSize(board.getWindowHeight() / 50);
	scoreText.setString("Score:" + std::to_string(board.getSnakeLength()));
	scoreText.setFillColor(sf::Color::Black);
	scoreText.setPosition(board.getWindowWidth() / 2.3, 0);

	spaceText.setFont(font);
	spaceText.setCharacterSize(board.getWindowHeight() / 50);
	spaceText.setString("press space to see results");
	spaceText.setFillColor(sf::Color::Black);
	spaceText.setPosition(board.getWindowWidth() / 4, board.getWindowHeight()/2);
}



void SnakeView::draw(sf::RenderWindow & w)
{
	w.draw(background);
	for (int i = 0; i < board.getBoardHeight(); ++i)
	{
		for (int j = 0; j < board.getBoardWidth(); ++j)
		{
			if (board.getFieldInfo(i, j) == 'S')
			{
				snake.setPosition(sf::Vector2f(j*(board.getWindowWidth() / board.getBoardWidth()), i*(board.getWindowHeight() / board.getBoardHeight())));
				w.draw(snake);
			}
			if (board.getFieldInfo(i, j) == 'F')
			{
				feed.setPosition(sf::Vector2f(j*(board.getWindowWidth() / board.getBoardWidth()), i*(board.getWindowHeight() / board.getBoardHeight())));
				w.draw(feed);
			}
			if (board.getFieldInfo(i, j) == 'W')
			{
				wall.setPosition(sf::Vector2f(j*(board.getWindowWidth() / board.getBoardWidth()), i*(board.getWindowHeight() / board.getBoardHeight())));
				w.draw(wall);
			}
		}
	}
	w.draw(scoreText);

	if (board.getGameState() != RUNNING)
	{
		w.draw(spaceText);
	}
}

