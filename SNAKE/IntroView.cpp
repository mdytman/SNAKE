#include "pch.h"
#include "IntroView.h" 
#include <iostream>

IntroView::IntroView(SnakeBoard & sb) : board(sb)
{
	background.setSize(sf::Vector2f(board.getWindowHeight(), board.getWindowWidth()));
	background.setFillColor(sf::Color(78, 56, 56));
	
	
	if (!font1.loadFromFile("snake.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	text1.setFont(font1);
	text1.setCharacterSize(board.getWindowHeight() / 4);
	int posW = board.getWindowWidth() / 8;
	int posH = board.getWindowHeight() / 5;
	text1.setPosition(posW, posH);
	text1.setString("Snake");
	text1.setFillColor(sf::Color(48, 86, 48));

	playButton.setSize(sf::Vector2f(board.getWindowWidth() / 3, board.getWindowHeight() / 12));
	int PosW = board.getWindowWidth() / 3;
	int PosH = board.getWindowHeight() - board.getWindowHeight() / 4;
	playButton.setPosition(PosW, PosH);
	playButton.setFillColor(sf::Color(48, 86, 48));

	if (!font2.loadFromFile("silkscreen.ttf"))
	{
		std::cout << "error " << std::endl;
		system("pause");
	}

	text2.setFont(font2);
	text2.setCharacterSize(board.getWindowHeight()/50);
	text2.setString("Dytman Marta, 249046");
	text2.setFillColor(sf::Color::White);
	text2.setPosition(board.getWindowWidth()/2, board.getWindowHeight()/2);

	text3.setFont(font2);
	text3.setCharacterSize(board.getWindowHeight()/30);
	text3.setString("PLAY");
	text3.setFillColor(sf::Color::White);
	text3.setPosition(board.getWindowWidth()/2.3, board.getWindowHeight() - board.getWindowHeight()/4.3);

}

void IntroView::draw(sf::RenderWindow & win)
{
	win.draw(background);
	win.draw(text1);
	win.draw(playButton);
	win.draw(text2);
	win.draw(text3);
}

