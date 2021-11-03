#ifndef CSNAKE_HPP
#define CSNAKE_HPP

#include "isnake.hpp"

#include <string>
#include <iostream>

class CSnake : public ISnake
{
private:
// Members
	DIRECTION m_direction;		// Направление движения.
	std::vector<Elem> m_snake;	// Змей.

// Methods
	/**
	 * @brief Печать сообщения класса.
	 */
	void print (const std::string & text);

	/**
	 * @brief Печать ошибки из класса.
	 * @return Всегда false.
	 */
	bool error (const std::string & text);

public:
	CSnake() : ISnake() { }
	~CSnake() override { }

	bool init () override;

	void setDir (DIRECTION dir) override;
	void setSize (const size_t & size) override;
	void setBegPos (const size_t & x, const size_t & y) override;
	void setNewHead (size_t x, size_t y) override;

	void step () override;
	
	std::pair<size_t,size_t> getHead () override;
	const std::vector<Elem> & getSnake () override { return m_snake; }
};

#endif // CSNAKE_HPP