#include "cbox.hpp"

CBox::CBox() : IBox()
{
	m_side_size = 0;
}

bool CBox::init()
{
	if (m_side_size < 1)
	{
		print("Указан неверный размер поля.");
		return false;
	}

	m_box.resize(m_side_size);
	for (auto & val : m_box)
		val.resize(m_side_size, ' ');

	return true;
}

bool CBox::draw()
{
	clearBuf();
	if (m_food->hasFood())
	{
		auto p = m_food->getFood();
		m_box[p.second][p.first] = 'O';
		if (p == m_snake->getHead())
		{
			m_food->eatFood();
			m_snake->setNewHead(p.first, p.second);
		}
	}

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

	for (size_t i = 2; i < m_snake->getSnake().size(); i++)
		if (m_snake->getHead().first == m_snake->getSnake()[i].x &&
			m_snake->getHead().second == m_snake->getSnake()[i].y)
		{
			print("Змей съел сам себя.");
			print("Игра окончена.");
			return false;
		}

	system("clear");
	std::string border(m_side_size + 2, '-');
	border[0] = '+';
	border[border.size() - 1] = '+';
	std::cout << border << std::endl;
	for (auto & s : m_box)
		std::cout << '|' << s << '|' << std::endl;
	std::cout << border << std::endl;
	std::cout << "Длина змея: " << m_snake->getSnake().size() << std::endl;
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

std::pair<size_t, size_t> CBox::getBegPos()
{
	return std::make_pair(m_side_size / 2, m_side_size / 2);
}

CBox::~CBox()
{
	
}