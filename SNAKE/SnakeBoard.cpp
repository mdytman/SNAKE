#include "pch.h"
#include "SnakeBoard.h"


SnakeBoard::SnakeBoard(int windowHeight, int windowWidth)
{
	winHeight = windowHeight; //need to fix it
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

	snakePosition sP = { height / 2, width / 2 - 1 };
	snakePos.push_back(sP);
	

	for (int i3 = 0; i3 < snakePos.size(); ++i3)
	{
		if (i3 == 0)
		{
			board[snakePos[0].y][snakePos[0].x].hasSnakeHead = true;
		}
		if (i3 > 0)
		{
			board[snakePos[i3].y][snakePos[i3].x].hasSnake = true;
		}				
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
	} while (board[x][y].hasSnake == true || board[x][y].isWall == true || board[x][y].hasSnakeHead == true);
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
	return snakePos.size() - 2;
}

void SnakeBoard::changeDirection(Direction dir) 
{
	for (int k = 1; k < snakePos.size(); ++k)
	{
		board[snakePos[0].y][snakePos[0].x].hasSnakeHead = false;
		if (dir == RIGHT && direction != LEFT)
		{	
			snakePos[0].x = snakePos[0].x + 1;
			direction = RIGHT;
		}
		if (dir == LEFT && direction != RIGHT)
		{
			snakePos[0].x = snakePos[0].x - 1;
			direction = LEFT;
		}
		if (dir == UP && direction != DOWN)
		{
			snakePos[0].y = snakePos[0].y - 1;
			direction = UP;
		}
		if (dir == DOWN && direction != UP)
		{
			snakePos[0].y = snakePos[0].y + 1;
			direction = DOWN;
		}
		board[snakePos[0].x][snakePos[0].y].hasSnakeHead = true;			
				
		board[snakePos[k].y][snakePos[k].x].hasSnake = false;
		snakePos[k].x = snakePos[k - 1].x;
		snakePos[k].y = snakePos[k - 1].y;
		board[snakePos[k].y][snakePos[k].x].hasSnake = true;
	}
}

void SnakeBoard::move()
{
	for (int k = 1; k < snakePos.size(); ++k)
	{
		board[snakePos[0].y][snakePos[0].x].hasSnakeHead = false;
		
		if (direction == RIGHT)
			snakePos[0].x = snakePos[0].x + 1;
		if (direction == LEFT)
			snakePos[0].x = snakePos[0].x - 1;
		if (direction == UP)
			snakePos[0].y = snakePos[0].y - 1;
		if (direction == DOWN)
			snakePos[0].y = snakePos[0].y + 1;
									
		board[snakePos[0].y][snakePos[0].x].hasSnakeHead = true;

		board[snakePos[k].y][snakePos[k].x].hasSnake = false;
		snakePos[k].x = snakePos[k-1].x;
		snakePos[k].y = snakePos[k-1].y;					
		board[snakePos[k].y][snakePos[k].x].hasSnake = true;		
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

void SnakeBoard::lengthenSnake() //board
{
	if (isFeedEaten() == true)
	{
		int tmpx = snakePos[snakePos.size() - 1].x;
		int tmpy = snakePos[snakePos.size() - 1].y;
		if (snakePos[snakePos.size() - 2].x == tmpx - 1 && snakePos[snakePos.size() - 2].y == tmpy)
		{
			snakePosition sP = { tmpx + 1, tmpy };
			snakePos.push_back(sP);
			board[snakePos[snakePos.size() - 1].x][snakePos[snakePos.size() - 1].y].hasSnake = true;
		}
		if (snakePos[snakePos.size() - 2].x == tmpx + 1 && snakePos[snakePos.size() - 2].y == tmpy)
		{
			snakePosition sP = { tmpx - 1, tmpy };
			snakePos.push_back(sP);
			board[snakePos[snakePos.size() - 1].x][snakePos[snakePos.size() - 1].y].hasSnake = true;
		}
		if (snakePos[snakePos.size() - 2].x == tmpx && snakePos[snakePos.size() - 2].y == tmpy - 1)
		{
			snakePosition sP = { tmpx, tmpy + 1 };
			snakePos.push_back(sP);
			board[snakePos[snakePos.size() - 1].x][snakePos[snakePos.size() - 1].y].hasSnake = true;
		}
		if (snakePos[snakePos.size() - 2].x == tmpx && snakePos[snakePos.size() - 2].y == tmpy + 1)
		{
			snakePosition sP = { tmpx, tmpy - 1 };
			snakePos.push_back(sP);
			board[snakePos[snakePos.size() - 1].x][snakePos[snakePos.size() - 1].y].hasSnake = true;
		}
		
		//changing feed position
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (board[i][j].hasFeed == true)
				{
					board[i][j].hasFeed = false;
					setFeed();
					break;
				}
			}
		}
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



