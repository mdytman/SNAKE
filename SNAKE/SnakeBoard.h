#pragma once
#include <iostream>
#include <vector>

enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum direction {RIGHT, LEFT, UP, DOWN};

struct Field
{
	bool hasFeed;
	bool hasWall;
	bool hasSnake; //?
};

class SnakeBoard
{
	Field board[100][100];
	int winHeight;
	int winWidth;
	int height;
	int width;
	GameState state;
	std::vector <int> snakeLength;
public:
	SnakeBoard(int h, int w);
	void setFeed();
	int getBoardHeight() const { return winHeight; }
	int getBoardWidth() const { return winWidth; }
	int getHeight() const { return height; }
	int getWidth() const { return width; }
	GameState getGameState() const;
	int getSnakeLength() const;
	void move(direction dir);
	bool isFeedEaten() const;
	void lengthenSnake();
	char getFieldInfo(int x, int y) const;
};

