#include "pch.h"
#include "ScoreView.h"

ScoreView::ScoreView(SnakeBoard & b) : board(b)
{
	background.setSize(sf::Vector2f(board.getWindowHeight(), board.getWindowWidth()));
	background.setFillColor(sf::Color(78, 56, 56));

	if (!font1.loadFromFile("snake.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}
	gameOver.setFont(font1);
	gameOver.setFillColor(sf::Color(48, 86, 48));

	if (!font2.loadFromFile("silkscreen.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	scoreText.setFont(font2);
	scoreText.setCharacterSize(board.getWindowHeight() / 50);
	scoreText.setFillColor(sf::Color::Black);	
}

void ScoreView::draw(sf::RenderWindow & win)
{
	win.draw(background);

	gameOver.setPosition(board.getWindowWidth() / 6, board.getWindowHeight() / 9);
	gameOver.setString("Game");
	gameOver.setCharacterSize(board.getWindowHeight() / 4);
	win.draw(gameOver);

	gameOver.setPosition(board.getWindowWidth() / 4, board.getWindowHeight() / 3);
	gameOver.setString("over");
	gameOver.setCharacterSize(board.getWindowHeight() / 5);
	win.draw(gameOver);

	scoreText.setString("Your score: " + std::to_string(board.getSnakeLength()));
	scoreText.setPosition(board.getWindowWidth() / 2.5, board.getWindowHeight() / 1.5);
	win.draw(scoreText);

	scoreText.setString("press space to close the window");
	scoreText.setPosition(board.getWindowWidth() / 4, board.getWindowHeight() / 1.3);
	win.draw(scoreText);
}
