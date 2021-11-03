#ifndef CFOOD_HPP
#define CFOOD_HPP

#include "ifood.hpp"

#include <random>

/**
 * @brief Класс генерации еды.
 */
class CFood : public IFood
{
private:
	size_t m_x, m_y;						// Координаты еды.
	bool  m_has_food;						// Флаг наличия еды.
	std::vector<int> m_free_x, m_free_y;	// Массив свободных координат.
	
public:
	CFood () : IFood() { m_has_food = false; }
	~CFood () override { }

	std::pair<size_t,size_t> getNewFood
		(const std::vector<std::string> & buf) override;

	std::pair<size_t,size_t> getFood () override
	{ return std::make_pair(m_x, m_y); }
	
	bool hasFood () override { return m_has_food; }
	void eatFood () override { m_has_food = false; }
};

#endif // CFOOD_HPP