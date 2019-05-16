#include "pch.h"
#include "SnakeBoard.h"


SnakeBoard::SnakeBoard(int h, int w)
{
	winHeight = h;
	winWidth = w;
	height = 10;
	width = 10;
	state = RUNNING;
	for (int i = 0; i < height; ++i)
	{
		for (int k = 0; k < width; ++k)
		{
			board[i][k].hasFeed = false;
			board[i][k].hasSnake = false;
			board[i][k].isWall = false;
		}
	}
	for (int j = 0; j < 100; ++j)
	{
		board[j][0].isWall = true;
		board[j][width - 1].isWall = true;
		board[0][j].isWall = true;
		board[height - 1][j].isWall = true;
	}
	board[height/2][width/2].hasSnakeHead = true;
}

void SnakeBoard::debug_display() const
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			std::cout << getFieldInfo(i, j);
		}
		std::cout << std::endl;
	}
}

void SnakeBoard::setFeed()
{
	int x = 0;
	int y = 0;
	do
	{
		x = rand() % height;
		y = rand() % width;
	} while (board[x][y].hasSnake == true || board[x][y].isWall == true);
	board[x][y].hasFeed = true;
}


bool SnakeBoard::hasSnake(int x, int y) const
{
	if (board[y][x].hasSnake == true)
		return true;
	else
		return false;
}

bool SnakeBoard::isWall(int x, int y) const
{
	if (board[y][x].isWall == true)
		return true;
	else
		return false;
}

bool SnakeBoard::hasSnakeHead(int x, int y) const
{
	if (board[y][x].hasSnakeHead == true)
		return true;
	else
		return false;
}

bool SnakeBoard::hasFeed(int x, int y) const
{
	if (board[y][x].hasFeed == true)
		return true;
	else
		return false;
}

GameState SnakeBoard::getGameState() const
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if ((board[i][j].hasSnakeHead == true && board[i][j].isWall == true) || (board[i][j].hasSnakeHead == true && board[i][j].hasSnake == true))
			{
				return FINISHED_LOSS;
			}

		}
	}
	return state;
}

int SnakeBoard::getSnakeLength() const
{
	return snakeLength.size();
}

void SnakeBoard::move(direction dir) //
{
	if (dir == RIGHT)
	{

	}
}

bool SnakeBoard::isFeedEaten() const
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (board[i][j].hasSnakeHead == true && board[i][j].hasFeed == true)
			{
				return true;
			}
		}
	}
	return false;
}

void SnakeBoard::lengthenSnake()
{
	if (isFeedEaten() == true)
	{
		snakeLength.push_back(1);
	}
}

char SnakeBoard::getFieldInfo(int x, int y) const
{
	if (board[y][x].hasFeed == true)
		return 'F';
	if (board[y][x].hasSnake == true)
		return 'S';
	if (board[y][x].hasSnakeHead == true)
		return 'H';
	if (board[y][x].isWall == true)
		return 'W';
	else return '_';
}



