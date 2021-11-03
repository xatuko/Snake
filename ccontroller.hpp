#ifndef CCONTROLLER_HPP
#define CCONTROLLER_HPP

#include "icontroller.hpp"
#include "cbox.hpp"
#include "cfood.hpp"
#include "csnake.hpp"

#include <memory>
#include <termios.h>
#include <atomic>
#include <thread>

class CController : public IController
{
private:
// Members
	std::shared_ptr<ISnake> m_snake;	// Змей.
	std::shared_ptr<IFood>  m_food;		// Еда.
	std::shared_ptr<IBox>   m_box;		// Поле.
	
	// Флаг процесса ввода.
	std::atomic_bool m_keyboard_thread_run	{ false };
	// Флаг процесса отрисовки.
	std::atomic_bool m_draw_thread_run		{ false };
	// Флаг инициализации.
	std::atomic_bool m_is_init				{ false };
	// Флаг паузы
	std::atomic_bool m_pause				{ false };

	termios m_old_termios;		// Начальные параметры консоли.
	termios m_current_termios;	// Параметры консоли для игры.

	// Поток отрисовки.
	std::unique_ptr<std::thread> m_draw_thread;
	// Поток чтения ввода.
	std::unique_ptr<std::thread> m_keyboard_thread;

// Methods
	/**
	 * @brief Потоковый метод чтения ввода.
	 */
	void keyboardThread ();
	
	/**
	 * @brief Потоковый метод отрисовки.
	 */
	void drawThread ();

	/**
	 * @brief Установить параметры консоли для игры.
	 */
	void initTermios ();

	/**
	 * @brief Вернуть исходные параметры консоли.
	 */
	void resetTermios ();

	/**
	 * @brief Вывод сообщения класса.
	 */
	void print (const std::string & text);

	/**
	 * @brief Вывод ошибки класса.
	 */
	void error (const std::string & text);

public:
// Methods
	CController () : IController() { }
	~CController () override;

	bool init (const int & side_size, const int & snake_size) override;
	bool isInit () override { return m_is_init; }
	
	void start () override;
	void stop  () override;
};

#endif // CCONTROLLER_HPP