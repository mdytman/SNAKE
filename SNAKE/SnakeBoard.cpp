#include "pch.h"
#include "SnakeBoard.h"


SnakeBoard::SnakeBoard(int h, int w)
{
	winHeight = h;
	winWidth = w;
	height = 100;
	width = 100;
	for (int i = 0; i < 100; ++i)
	{
		for (int k = 0; k < 100; ++k)
		{
			board[i][k].hasFeed = false;
			board[i][k].hasSnake = false;
			board[i][k].hasWall = false;
		}
	}
	for (int j = 0; j < 100; ++j)
	{
		board[j][0].hasWall = true;
		board[j][99].hasWall = true;
		board[0][j].hasWall = true;
		board[99][j].hasWall = true;
	}
	board[49][49].hasSnake = true;

}

void SnakeBoard::setFeed()
{
	int x = 0;
	int y = 0;
	do
	{
		x = rand() % height;
		y = rand() % width;
	} while (board[x][y].hasSnake == true || board[x][y].hasWall == true);
	board[x][y].hasFeed = true;
}


GameState SnakeBoard::getGameState() const
{
	return GameState();
}

int SnakeBoard::getSnakeLength() const
{
	return 0;
}

void SnakeBoard::move(direction dir)
{
}

bool SnakeBoard::isFeedEaten() const
{
	return false;
}

void SnakeBoard::lengthenSnake()
{
}

char SnakeBoard::getFieldInfo(int x, int y) const
{
	return 0;
}



