#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SnakeBoard.h"
#include "IntroView.h"
#include "SnakeView.h"
#include "ScoreView.h"
#include "IntroController.h"
#include "SnakeController.h"
#include "ScoreController.h"
#include "GameManager.h"


int main()
{
	srand(time(NULL));
	SnakeBoard sb(920, 920);

	IntroView iv(sb);
	IntroController ic(iv, sb);

	SnakeView snv(sb);
	SnakeController snc(snv, sb);

	ScoreView sv(sb);
	ScoreController sc(sv);

	GameManager gm(ic, snc, sc);

	unsigned int width;
	unsigned int height;

	width = (unsigned)sb.getWindowWidth();
	height = (unsigned)sb.getWindowHeight();

	sf::RenderWindow w{ sf::VideoMode{width, height}, "SNAKE" };

	w.setFramerateLimit(60);
	sf::Event event;

	while (w.isOpen()) {

		sf::Event event;
		while (w.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				w.close();			

		}
		gm.handleEvent(event);

		w.clear();

		gm.draw(w);

		w.display();
	}

	return 0;
}