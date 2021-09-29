#include "csnake.hpp"

bool CSnake::getStatus()
{
	if(m_status == true)
		return true;
	return false;
}

void CSnake::setDir(int dir)
{
	switch(dir)
	{
		case 0:
			m_direction = DIRECTION::UP;
			break;
		case 1:
			m_direction = DIRECTION::DOWN;
			break;
		case 2:
			m_direction = DIRECTION::LEFT;
			break;
		case 3:
			m_direction = DIRECTION::RIGHT;
			break;
	}
}

void printBuf(std::vector<std::string> &buf)
{
	for (int i = 0; i < buf.size(); i++)
		std::cout << buf[i] << std::endl;
}

CSnake::CSnake() : ISnake()
{
	m_direction = DIRECTION::DOWN;
	m_snake.resize(3);
	m_snake[0].next = nullptr;
	m_snake[1].next = &m_snake[0];
	m_snake[2].next = &m_snake[1];

	m_snake[0].x = 5;
	m_snake[0].y = 2;

	m_snake[1].x = 5;
	m_snake[1].y = 1;

	m_snake[2].x = 5;
	m_snake[2].y = 0;
	m_status = false;
}

void CSnake::step()
{
	for (int i = m_snake.size()-1; i > 0; i--)
	{
		m_snake[i].x = m_snake[i].next->x;
		m_snake[i].y = m_snake[i].next->y;
	}
	switch(m_direction)
	{
		case DIRECTION::DOWN:
			m_snake[0].y++;
			break;
		case DIRECTION::UP:
			m_snake[0].y--;
			break;
		case DIRECTION::LEFT:
			m_snake[0].x--;
			break;
		case DIRECTION::RIGHT:
			m_snake[0].x++;
			break;
	}
}

void CSnake::draw(int x_size, int y_size, std::vector<std::string>& buf)
{
	buf.resize(y_size);
	for (int i = 0; i < buf.size(); i++)
	{
		buf[i].clear();
		buf[i].resize(x_size, ' ');
	}
	
	for (int i = 0; i < m_snake.size(); i++)
		buf[m_snake[i].y][m_snake[i].x] = 'O';
}

CSnake::~CSnake()
{
	
}