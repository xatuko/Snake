#include "csnake.hpp"

bool CSnake::getStatus()
{
	if(m_status == true)
		return true;
	return false;
}

void CSnake::setDir(DIRECTION dir)
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

bool CSnake::init(const int & beg_size, const int & side_size)
{
	if (beg_size > side_size / 2 || beg_size < 1 || side_size < 1)
		return error("Ошибка инициализации змея.");

	m_direction = DIRECTION::DOWN;

	m_snake.resize(beg_size);

	for (size_t i = m_snake.size() - 1; i > 0; i--)
	{
		m_snake[i].next = &m_snake[i-1];
		m_snake[i].x = side_size / 2;
		m_snake[i].y = side_size / 2 - i;
	}

	m_snake[0].next = nullptr;
	m_snake[0].x = side_size / 2;
	m_snake[0].y = side_size / 2;

	return true;
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

std::pair<int,int> CSnake::getHead()
{
	return std::make_pair(m_snake[0].x, m_snake[0].y);
}

void CSnake::setNewHead(int x, int y)
{
	Elem head = {.x = x, .y = y, .next = nullptr};
	m_snake.insert(m_snake.begin(), head);
	for (int i = m_snake.size()-1; i > 0; i--)
		m_snake[i].next = &m_snake[i-1];
}

CSnake::~CSnake()
{
	
}

void CSnake::print(const std::string & text)
{

}

bool CSnake::error(const std::string & text)
{
	print(text);
	print("Error № " + std::to_string(errno));
	return false;
}