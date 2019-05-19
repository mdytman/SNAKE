#pragma once
#include "IntroController.h"
#include "SnakeController.h"
#include "ScoreController.h"
#include "SnakeBoard.h"

class GameManager {
	IntroController &introController;
	SnakeController &snakeController;
	ScoreController &scoreController;

	enum GameState {
		INTRO, GAME, SCORE
	} state;

	void updateState();
public:
	GameManager(IntroController &ic, SnakeController &snc, ScoreController &sc);

	void draw(sf::RenderWindow &win);

	void handleEvent(sf::Event &event);
};
