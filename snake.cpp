#include "snake.hpp"

bool Snake::getStatus()
{
	if(status == true)
		return true;
	return false;
}

void Snake::setDir(int dir)
{
	switch(dir)
	{
		case 0:
			direct = DIRECTION::UP;
			break;
		case 1:
			direct = DIRECTION::DOWN;
			break;
		case 2:
			direct = DIRECTION::LEFT;
			break;
		case 3:
			direct = DIRECTION::RIGHT;
			break;
	}
}

void Snake::initTermios()
{

	tcgetattr(0, &old);         /* grab old terminal i/o settings */
	current = old;              /* make new settings same as old settings */
	current.c_lflag &= ~ICANON; /* disable buffered i/o */
	current.c_lflag &= ~ECHO;   /* set no echo mode */
	tcsetattr(0, TCSANOW, &current);
}

void Snake::resetTermios()
{
	tcsetattr(0, TCSANOW, &old);
}

void printBuf(std::vector<std::string> &buf)
{
	for (int i = 0; i < buf.size(); i++)
		std::cout << buf[i] << std::endl;
}

Snake::Snake()
{
	direct = DIRECTION::DOWN;
	snake.resize(3);
	snake[0].next = nullptr;
	snake[1].next = &snake[0];
	snake[2].next = &snake[1];

	snake[0].x = 5;
	snake[0].y = 2;

	snake[1].x = 5;
	snake[1].y = 1;

	snake[2].x = 5;
	snake[2].y = 0;
	status = false;

	initTermios();
}

void Snake::step()
{
	for (int i = snake.size()-1; i > 0; i--)
	{
		snake[i].x = snake[i].next->x;
		snake[i].y = snake[i].next->y;
	}
	switch(direct)
	{
		case DIRECTION::DOWN:
			snake[0].y++;
			break;
		case DIRECTION::UP:
			snake[0].y--;
			break;
		case DIRECTION::LEFT:
			snake[0].x--;
			break;
		case DIRECTION::RIGHT:
			snake[0].x++;
			break;
	}
}

void Snake::draw(int x_size, int y_size, std::vector<std::string>& buf)
{
	buf.resize(y_size);
	for (int i = 0; i < buf.size(); i++)
	{
		buf[i].clear();
		buf[i].resize(x_size, ' ');
	}
	
	for (int i = 0; i < snake.size(); i++)
		buf[snake[i].y][snake[i].x] = 'O';
}

Snake::~Snake()
{
	resetTermios();
}