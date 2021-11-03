#ifndef CBOX_HPP
#define CBOX_HPP

#include "ibox.hpp"
#include "cfood.hpp"

#include <vector>
#include <string>
#include <iostream>

/**
 * @brief Класс для отрисовки игрового поля.
 */
class CBox : public IBox
{
private:
// Members
	size_t m_side_size;					// Размер стороны поля.

	std::vector<std::string> m_box;		// Поле.
	std::shared_ptr<ISnake>  m_snake;	// Указатель на змея.
	std::shared_ptr<IFood>   m_food;	// Указатель на еду.

// Methods
	/**
	 * @brief Вывести сообщение класса.
	 */
	void print (const std::string & text);

	/**
	 * @brief Вывести ошибку класса.
	 * @param text Сообщение.
	 * @return int = -1;
	 */
	int  error (const std::string & text);

	/**
	 * @brief Очистить поле.
	 */
	void clearBuf ();

public:
	CBox () : IBox() { m_side_size = 0; };
	~CBox () override { };

	bool init () override;
	bool draw () override;

	void addSnake (std::shared_ptr<ISnake> snake) override
	{ m_snake = snake; }
	
	void addFood (std::shared_ptr<IFood> food) override
	{ m_food = food; }

	void setSideSize (const size_t & size) override
	{ m_side_size = size; }

	const size_t & getSideSize () override
	{ return m_side_size; }
	
	std::pair<size_t, size_t> getBegPos () override;

};

#endif // CBOX_HPP