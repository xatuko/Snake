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

	// members
	int m_side_size;
	bool m_is_init;
	std::vector<std::string> m_box;
	termios m_old_termios, m_current_termios;
	std::shared_ptr<ISnake> m_snake;
	std::unique_ptr<IFood> m_food;

	// methods
	void initTermios();
	void resetTermios();

	void print(const std::string & text);
	int  error(const std::string & text);

public:
	CBox();
	~CBox() override { resetTermios(); }

	// methods
	void setSideSize(const int & size) override { m_side_size = size; }
	bool init() override;
	bool draw() override;
	bool isInit() override { return m_is_init; }
	void addSnake(std::shared_ptr<ISnake> snake) override { m_snake = snake; }
	void clearBuf() override;

};

#endif // CBOX_HPP