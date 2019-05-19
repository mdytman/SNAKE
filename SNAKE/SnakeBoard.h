#pragma once
#include <iostream>
#include <vector>

enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum Direction {RIGHT, LEFT, UP, DOWN};

struct Field
{
	bool hasFeed;
	bool isWall;
	bool hasSnake; //?
	bool hasSnakeHead;
};

struct snakePosition
{
	int x;
	int y;
};

class SnakeBoard
{
	Field board[100][100];
	int winHeight;
	int winWidth;
	int height;
	int width;
	GameState state;
	Direction direction;
	std::vector <snakePosition> snakePos;

	void setFeed();
public:
	SnakeBoard(int windowHeight, int windowWidth);
	void debug_display() const;
	int getWindowHeight() const { return winHeight; }
	int getWindowWidth() const { return winWidth; }
	int getBoardHeight() const { return height; }
	int getBoardWidth() const { return width; }
	bool hasSnake(int x, int y) const;
	bool isWall(int x, int y) const;
	bool hasSnakeHead(int x, int y) const;
	bool hasFeed(int x, int y) const;
	GameState getGameState() const;
	int getSnakeLength() const;
	void move(Direction dir);
	bool isFeedEaten() const;
	void lengthenSnake();
	char getFieldInfo(int x, int y) const;
};

