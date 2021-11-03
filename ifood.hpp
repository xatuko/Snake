#ifndef IFOOD_HPP
#define IFOOD_HPP

#include <vector>
#include <string>

/**
 * @brief Класс генерации еды.
 */
class IFood
{
public:
	IFood () = default;
	virtual ~IFood () = default;

	/**
	 * @brief Получить координаты новой еды.
	 * @param buf Поле с текущим положением змея.
	 * @return std::pair<size_t,size_t> - Новые координаты 
	 * (first = x, second = y).
	 */
	virtual std::pair<size_t,size_t> getNewFood
		(const std::vector<std::string> & buf) = 0;

	/**
	 * @brief Есть ли еда на поле.
	 */
	virtual bool hasFood () = 0;

	/**
	 * @brief Съесть еду.
	 */
	virtual void eatFood () = 0;

	/**
	 * @brief Получить текущие координаты еды.
	 * @return std::pair<size_t,size_t> - Координаты (first = x, second = y).
	 */
	virtual std::pair<size_t,size_t> getFood () = 0;
};

#endif // IFOOD_HPP