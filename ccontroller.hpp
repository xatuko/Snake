#ifndef CCONTROLLER_HPP
#define CCONTROLLER_HPP

#include "icontroller.hpp"
#include "cbox.hpp"
#include "cfood.hpp"
#include "csnake.hpp"

#include <memory>
#include <termios.h>

class CController : public IController
{
private:
// Members
	std::shared_ptr<ISnake> m_snake;
	std::shared_ptr<IFood>  m_food;
	std::shared_ptr<IBox>   m_box;

	std::atomic_bool m_keyboard_thread_run	{ false },
					 m_draw_thread_run		{ false },
					 m_is_init				{ false },
					 m_pause				{ false };

	termios m_old_termios,
			m_current_termios;

	std::unique_ptr<std::thread> m_draw_thread,
								 m_keyboard_thread;

// Methods
	void keyboardThread();
	void drawThread();

	void initTermios();
	void resetTermios();

	void print(const std::string & text);
	void error(const std::string & text);

public:
// Methods
	CController() : IController() { }
	~CController() override;

	bool init(const int & side_size, const int & snake_size) override;
	void start() override;
	void stop() override;
	bool isInit() override { return m_is_init; }
};

#endif // CCONTROLLER_HPP