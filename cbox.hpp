#ifndef CBOX_HPP
#define CBOX_HPP

#include "ibox.hpp"
#include "cfood.hpp"

#include <vector>
#include <string>
#include <termios.h>
#include <iostream>

/**
 * @brief Класс для отрисовки игрового поля.
 */
class CBox : public IBox
{
private:
// Members
	size_t m_side_size;
	bool m_is_init;
	std::vector<std::string> m_box;
	std::shared_ptr<ISnake> m_snake;
	std::shared_ptr<IFood> m_food;

// Methods
	void print(const std::string & text);
	int  error(const std::string & text);

public:
	CBox();
	~CBox() override;

	void setSideSize(const int & size) override { m_side_size = size; }
	void addSnake(std::shared_ptr<ISnake> snake) override { m_snake = snake; }
	void addFood(std::shared_ptr<IFood> food) override { m_food = food; }
	void clearBuf() override;

	bool init() override;
	bool draw() override;
	bool isInit() override { return m_is_init; }

	const size_t & getSideSize() override { return m_side_size; }
	std::pair<size_t, size_t> getBegPos() override;

};

#endif // CBOX_HPP