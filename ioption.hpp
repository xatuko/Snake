#ifndef IOPTION_HPP
#define IOPTION_HPP

#include <string>

/**
 * @brief Интерфейс класса для разбора флагов.
 */
class IOption
{
public:
	IOption() = default;
	virtual ~IOption() = default;

	/**
	 * @brief Инициализировать объект.
	 * 
	 * @param argc Количество аргументов.
	 * @param argv Массив аргументов.
	 * @returns true - в случае успешной инициализации,
	 * 			false - в случае ошибки.
	 */
	virtual bool init(const int & argc, const char ** argv) = 0;

	/**
	 * @brief Получить целочисленное значение параметра.
	 * @param name Имя параметра.
	 * @param def_val Значение по умолчанию.
	 */
	virtual int getInt(const std::string & name, const int & def_val) = 0;

	/**
	 * @brief Получить строковое значение параметра.
	 * @param name Имя параметра.
	 * @param def_val Значение по умолчанию.
	 */
	virtual std::string getString(const std::string & name, 
								  const std::string & def_val) = 0;

	/**
	 * @brief Получить значение параметра в виде числа с плавающей точкой.
	 * @param name Имя параметра.
	 * @param def_val Значение по умолчанию.
	 * @return double 
	 */
	virtual double getDouble(const std::string & name,
							 const double & def_val) = 0;
	
	/**
	 * @brief Узнать, установлен ли флаг '--help'.
	 * @returns true - если установлен, false - если не установлен.
	 */
	virtual bool needHelp() = 0;
};

#endif // IOPTION_HPP