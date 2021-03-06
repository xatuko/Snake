#include "csnake.hpp"

bool CSnake::init ()
{
	m_direction = DIRECTION::DOWN;

	for (size_t i = 1; i < m_snake.size(); i++)
	{
		m_snake[i].next = &m_snake[i-1];
		m_snake[i].x	= m_snake[i-1].x;
		m_snake[i].y	= m_snake[i-1].y-1;
	}

	return true;
}

void CSnake::setSize (const size_t & size)
{
	m_snake.resize(size);
}

void CSnake::setBegPos (const size_t & x, const size_t & y)
{
	m_snake[0].next = nullptr;
	m_snake[0].x = x;
	m_snake[0].y = y;
}

void CSnake::setDir (DIRECTION dir)
{	
	switch(dir)
	{
		case DIRECTION::UP:
			if (m_direction != DIRECTION::DOWN)
				m_direction = DIRECTION::UP;
			break;
		case DIRECTION::DOWN:
			if (m_direction != DIRECTION::UP)
				m_direction = DIRECTION::DOWN;
			break;
		case DIRECTION::LEFT:
			if (m_direction != DIRECTION::RIGHT)
				m_direction = DIRECTION::LEFT;
			break;
		case DIRECTION::RIGHT:
			if (m_direction != DIRECTION::LEFT)
				m_direction = DIRECTION::RIGHT;
			break;
	}
}

void CSnake::step ()
{
	for (size_t i = m_snake.size()-1; i > 0; i--)
	{
		m_snake[i].x = m_snake[i].next->x;
		m_snake[i].y = m_snake[i].next->y;
	}
	switch(m_direction)
	{
		case DIRECTION::DOWN:	m_snake[0].y++; break;
		case DIRECTION::UP:		m_snake[0].y--; break;
		case DIRECTION::LEFT:	m_snake[0].x--; break;
		case DIRECTION::RIGHT:	m_snake[0].x++; break;
	}
}

std::pair<size_t,size_t> CSnake::getHead ()
{
	return std::make_pair(m_snake[0].x, m_snake[0].y);
}

void CSnake::setNewHead (size_t x, size_t y)
{
	Elem head = {.x = x, .y = y, .next = nullptr};
	m_snake.insert(m_snake.begin(), head);
	for (size_t i = m_snake.size()-1; i > 0; i--)
		m_snake[i].next = &m_snake[i-1];
}

void CSnake::print (const std::string & text)
{
	std::cout << "[CSnake] " << text << std::endl;
}

bool CSnake::error (const std::string & text)
{
	print(text);
	print("Error № " + std::to_string(errno));
	return false;
}