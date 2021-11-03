#ifndef IBOX_HPP
#define IBOX_HPP

#include <memory>

#include "isnake.hpp"
#include "ifood.hpp"

/**
 * @brief Класс для отрисовки поля. 
 */
class IBox
{
public:
	IBox () = default;
	virtual ~IBox () = default;

	/**
	 * @brief Инициализировать объект.
	 */
	virtual bool init () = 0;

	/**
	 * @brief Отрисовать поле.
	 */
	virtual bool draw () = 0;

	/**
	 * @brief Установить размер стороны поля.
	 * @param size Размер.
	 */
	virtual void setSideSize (const size_t & size) = 0;
	
	/**
	 * @brief Добавить змея.
	 */
	virtual void addSnake (std::shared_ptr<ISnake> snake) = 0;

	/**
	 * @brief Добавить еду.
	 */
	virtual void addFood (std::shared_ptr<IFood> food) = 0;

	/**
	 * @brief Получить размер стороны поля.
	 */
	virtual const size_t & getSideSize () = 0; 

	/**
	 * @brief Получить начальное положение головы змея.
	 */
	virtual std::pair<size_t, size_t> getBegPos () = 0;
};

#endif // IBOX_HPP