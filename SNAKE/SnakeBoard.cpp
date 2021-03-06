//#include "pch.h"
#include "SnakeBoard.h"


SnakeBoard::SnakeBoard(int windowHeight, int windowWidth)
{
	winHeight = windowHeight; 
	winWidth = windowWidth;
	height = winHeight / 40;
	width = winWidth / 40;
	state = RUNNING;
	direction = RIGHT;
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
	snakePosition hP = { width / 2, height / 2 }; //head position
	snakePos.push_back(hP); 

	snakePosition sP = { width / 2, height / 2 - 1 };
	snakePos.push_back(sP);
	

	for (int i3 = 0; i3 < snakePos.size(); ++i3)
	{
		board[snakePos[i3].y][snakePos[i3].x].hasSnake = true;
	}
	setFeed();
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
	if (board[y][x].hasSnake == true && board[y][x].isWall == false)
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


bool SnakeBoard::hasFeed(int x, int y) const
{
	if (board[y][x].hasFeed == true)
		return true;
	else
		return false;
}

bool SnakeBoard::isCollision(int x, int y) const
{
	if (board[y][x].isWall) return true;
	for (int i = 0; i < snakePos.size(); ++i)
	{
		if (snakePos[i].x == x && snakePos[i].y == y)
		{
			return true;
		}
	}
	return false;
}

GameState SnakeBoard::getGameState() const
{
	return state;
}

int SnakeBoard::getSnakeLength() const
{
	return snakePos.size() - 2;
}

void SnakeBoard::changeDirection(Direction dir) 
{
	if (dir == RIGHT && direction != LEFT)
	{
		direction = RIGHT;
	}
	if (dir == LEFT && direction != RIGHT)
	{
		direction = LEFT;
	}
	if (dir == UP && direction != DOWN)
	{
		direction = UP;
	}
	if (dir == DOWN && direction != UP)
	{
		direction = DOWN;
	}
}

void SnakeBoard::move()
{
	snakePosition newPos;
	if (direction == RIGHT)
	{
		newPos.x = snakePos[0].x + 1;
		newPos.y = snakePos[0].y;
	}
	if (direction == LEFT)
	{
		newPos.x = snakePos[0].x - 1;
		newPos.y = snakePos[0].y;
	}
	if (direction == UP)
	{
		newPos.x = snakePos[0].x;
		newPos.y = snakePos[0].y - 1;
	}
	if (direction == DOWN)
	{
		newPos.x = snakePos[0].x;
		newPos.y = snakePos[0].y + 1;
	}
	
	if (isCollision(newPos.x, newPos.y) == false)
	{
		if (isFeedEaten())
		{
			board[newPos.y][newPos.x].hasSnake = true; //snake lengthen
			snakePos.insert(snakePos.begin(), newPos);

			setFeed();
		}
		else
		{
			board[newPos.y][newPos.x].hasSnake = true;
			snakePos.insert(snakePos.begin(), newPos);
			board[snakePos[snakePos.size() - 1].y][snakePos[snakePos.size() - 1].x].hasSnake = false;
			snakePos.pop_back();
		}
	}
	else state = FINISHED_LOSS;
}

bool SnakeBoard::isFeedEaten()
{
	for (int i = 0; i < snakePos.size(); ++i)
	{
		if (board[snakePos[0].y][snakePos[0].x].hasFeed == true)
		{
			board[snakePos[0].y][snakePos[0].x].hasFeed = false;
			return true;
		}
	}
	return false;
}


char SnakeBoard::getFieldInfo(int x, int y) const
{
	if (board[y][x].hasFeed == true)
		return 'F';
	if (board[y][x].hasSnake == true)
		return 'S';
	if (board[y][x].isWall == true)
		return 'W';
	else return '_';
}



