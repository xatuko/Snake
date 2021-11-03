#include "ccontroller.hpp"

bool CController::init(const int & side_size, const int & snake_size)
{
	// Инициализация поля.
	m_box = std::make_shared<CBox>();
	m_box->setSideSize(side_size);
	if (!m_box->init())
		return false;

	if (m_box->getSideSize() / 2 < snake_size)
	{
		print("Начальный размер змея слишком велик.");
		return false;
	}

	// Инициализация змея.
	m_snake = std::make_shared<CSnake>();
	m_snake->setSize(snake_size);
	auto beg = m_box->getBegPos();
	m_snake->setBegPos(beg.first, beg.second);
	if (!m_snake->init())
		return false;

	// Инициализация еды.
	m_food = std::make_shared<CFood>();

	m_box->addSnake(m_snake);
	m_box->addFood(m_food);
	// Изменение параметров консоли.
	initTermios();

	m_is_init = true;
	
	return true;
}

void CController::drawThread()
{
	if (!m_box->draw())
	{
		m_is_init = false;
		return;
	}

	while (m_draw_thread_run)
	{
		m_snake->step();

		if (!m_box->draw())
		{
			m_is_init = false;
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
}

void CController::keyboardThread()
{
	int c;
	while (m_keyboard_thread_run)
	{
		c = getc(stdin);
		switch (c)
		{
			case 66: m_snake->setDir(DIRECTION::DOWN); break;
			case 65: m_snake->setDir(DIRECTION::UP); break;
			case 67: m_snake->setDir(DIRECTION::RIGHT); break;
			case 68: m_snake->setDir(DIRECTION::LEFT); break;
			case 113: m_is_init = false; break;
			case 112: m_pause = !m_pause; break;
		}
	}
}

void CController::start()
{
	m_draw_thread_run	  = true;
	m_keyboard_thread_run = true;

	m_draw_thread 	  = std::make_unique<std::thread>
						(&CController::drawThread, this);
	m_keyboard_thread = std::make_unique<std::thread>
						(&CController::keyboardThread, this);
}

void CController::stop()
{
	m_draw_thread_run	  = false;
	m_keyboard_thread_run = false;
}

void CController::print(const std::string & text)
{
	std::cout << "[CController] " << text << std::endl;
}

void CController::error(const std::string & text)
{
	print(text);
	print("Error № " + std::to_string(errno));
}

void CController::initTermios ()
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

void CController::resetTermios ()
{
	tcsetattr(0, TCSANOW, &m_old_termios);
}

CController::~CController()
{
	m_draw_thread_run	  = false;
	m_keyboard_thread_run = false;

	if (m_keyboard_thread->joinable())
		m_keyboard_thread->join();
	
	if (m_draw_thread->joinable())
		m_draw_thread->join();

	resetTermios();
}