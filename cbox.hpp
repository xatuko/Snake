#ifndef CBOX_HPP
#define CBOX_HPP

#include "ibox.hpp"

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

	// methods
	void initTermios();
	void resetTermios();

public:
	CBox() : IBox()  { m_side_size = 0; m_is_init = false;};
	~CBox() override { resetTermios(); }

	void setSideSize(const int & size) override { m_side_size = size; }
	bool init() override;
	void draw() override;
	bool isInit() override { return m_is_init; }

};

#endif // CBOX_HPP