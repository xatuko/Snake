#include "cbox.hpp"

CBox::CBox() : IBox()
{
	m_side_size = 0;
	m_is_init = false;
	m_food = std::make_unique<CFood>();
}

void CBox::initTermios()
{
	// grab old terminal i/o settings
	tcgetattr(0, &m_old_termios);
	// make new settings same as old settings
	m_current_termios = m_old_termios;
	// disable buffered i/o
	m_current_termios.c_lflag &= ~ICANON;
	// set no echo mode
	m_current_termios.c_lflag &= ~ECHO;

	tcsetattr(0, TCSANOW, &m_current_termios);
}

void CBox::resetTermios()
{
	if (m_is_init)
		tcsetattr(0, TCSANOW, &m_old_termios);
}

bool CBox::init()
{
	if (m_side_size == 0)
	{
		print("Указан нулевой размер поля.");
		return false;
	}

	m_box.resize(m_side_size);
	for (auto & val : m_box)
		val.resize(m_side_size, ' ');

	initTermios();

	m_is_init = true;

	return true;
}

bool CBox::draw()
{
	system("clear");
	clearBuf();
	for (auto & el : m_snake->getSnake())
	{
		if (el.x >= m_side_size || el.x < 0 || 
		    el.y >= m_side_size || el.y < 0)
		{
			print("Змей заполз на бордюр.");
			print("Игра окончена.");
			return false;
		}
		m_box[el.y][el.x] = 'X';
	}

	if (!m_food->hasFood())
	{
		auto p = m_food->getNewFood(m_box);
		m_box[p.second][p.first] = 'O';
	}
	else
	{
		auto p = m_food->getFood();
		m_box[p.second][p.first] = 'O';
	}

	std::string border(m_side_size + 2, '-');
	border[0] = '+';
	border[border.size() - 1] = '+';
	std::cout << border << std::endl;
	for (auto & s : m_box)
		std::cout << '|' << s << '|' << std::endl;
	std::cout << border << std::endl;
	return true;
}

void CBox::print(const std::string & text)
{
	std::cout << "[CBox] " << text << std::endl;
}

int CBox::error(const std::string & text)
{
	print(text);
	print("Error № " + std::to_string(errno));
	return -1;
}

void CBox::clearBuf()
{
	for (auto & str : m_box)
		str = std::string(m_side_size, ' ');
}