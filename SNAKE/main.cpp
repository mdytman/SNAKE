#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SnakeBoard.h"
#include "IntroView.h"





int main()
{
	srand(time(NULL));
	SnakeBoard sb(900, 900);
	IntroView iv(sb);
	sb.debug_display();

	unsigned int width;
	unsigned int height;

	width = (unsigned)sb.getBoardWidth();
	height = (unsigned)sb.getBoardHeight();

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
		//sb.draw(w);
		iv.draw(w);

		w.display();
	}

	return 0;
}