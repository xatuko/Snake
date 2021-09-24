#include "cbox.hpp"

void CBox::initTermios()
{
	tcgetattr(0, &m_old_termios);			/* grab old terminal i/o settings */
	m_current_termios = m_old_termios;		/* make new settings same as old settings */
	m_current_termios.c_lflag &= ~ICANON;	/* disable buffered i/o */
	m_current_termios.c_lflag &= ~ECHO;		/* set no echo mode */
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
		return false;

	m_box.resize(m_side_size + 2);
	for (int i = 0; i < m_box.size(); i++)
	{
		m_box[i].resize(m_side_size + 2, ' ');
		if (i == 0)
		{
			for (auto & s : m_box[i])
				s = '-';
			m_box[i][0] = '+';
			m_box[i][m_box[i].size() - 1] = '+';
		}
		else if (i == m_box.size() - 1)
		{
			for (auto & s : m_box[i])
				s = '-';
			m_box[i][0] = '+';
			m_box[i][m_box[i].size() - 1] = '+';
		}
		else
		{
			m_box[i][0] = '|';
			m_box[i][m_box[i].size() - 1] = '|';
		}
	}

	initTermios();

	m_is_init = true;

	return true;
}

void CBox::draw()
{
	system("clear");
	for (auto & s : m_box)
		std::cout << s << std::endl;
}