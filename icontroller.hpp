#ifndef ICONTROLLER_HPP
#define ICONTROLLER_HPP

/**
 * @brief Основной управляющий класс.
 */
class IController
{
public:
	IController () = default;
	virtual ~IController () = default;

	/**
	 * @brief Инициализировать объект.
	 * @param side_size Размер стороны поля.
	 * @param snake_size Начальный размер змея.
	 */
	virtual bool init (const int & side_size, const int & snake_size) = 0;

	/**
	 * @brief Запустить.
	 */
	virtual void start () = 0;

	/**
	 * @brief Остановить.
	 */
	virtual void stop () = 0;

	/**
	 * @brief Статус объекта.
	 */
	virtual bool isInit () = 0;
};

#endif // ICONTROLLER_HPP