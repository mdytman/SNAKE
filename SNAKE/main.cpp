#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "SnakeBoard.h"





int main()
{
	SnakeBoard sb(900, 900);

	sf::RenderWindow w{ sf::VideoMode{sb.getBoardWidth(), sb.getBoardHeight()}, "SNAKE" };

	w.setFramerateLimit(60);
	sf::Event event;

	while (w.isOpen()) {

		sf::Event event;
		while (w.pollEvent(event)) {

			if (event.type == sf::Event::Closed)
				w.close();

		}

		w.clear();
		sb.draw(w);

		w.display();
	}

	return 0;
}