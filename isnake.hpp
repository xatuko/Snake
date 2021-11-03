#ifndef ISNAKE_HPP
#define ISNAKE_HPP

#include "structs.hpp"

#include <vector>

/**
 * @brief Класс змея.
 */
class ISnake
{
public:
	ISnake () = default;
	virtual ~ISnake () = default;

	/**
	 * @brief Инициализация объекта.
	 */
	virtual bool init () = 0;

	/**
	 * @brief Задать размер змея.
	 */
	virtual void setSize (const size_t & size) = 0;

	/**
	 * @brief Задать начальную позицию змея.
	 */
	virtual void setBegPos (const size_t & x, const size_t & y) = 0;

	/**
	 * @brief Задать направление.
	 */
	virtual void setDir (DIRECTION dir) = 0;

	/**
	 * @brief Задать новые координаты головы.
	 */
	virtual void setNewHead (size_t x, size_t y) = 0;

	/**
	 * @brief Получить координаты головы.
	 * @return std::pair<size_t,size_t> - firsr = x, second = y.
	 */
	virtual std::pair<size_t,size_t> getHead () = 0;

	/**
	 * @brief Получить массив элеметов змея.
	 */
	virtual const std::vector<Elem> & getSnake () = 0;

	/**
	 * @brief Сделать шаг.
	 */
	virtual void step () = 0;
};

#endif // ISNAKE_HPP