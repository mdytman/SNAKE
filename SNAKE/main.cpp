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




int main()
{
	srand(time(NULL));
	SnakeBoard sb(920, 920);
	IntroView iv(sb);
	sb.debug_display();

	SnakeView sv(sb);
	ScoreView scv(sb);

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

		w.clear();
		//sv.draw(w);
		//iv.draw(w);
		scv.draw(w);

		w.display();
	}

	return 0;
}