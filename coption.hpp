#ifndef COPTION_HPP
#define COPTION_HPP

#include "ioption.hpp"
#include "structs.hpp"

#include <vector>
#include <iostream>

// Пространство имен для списка аргументов и справки.
namespace def {

const std::string help =
"Флаги:\n"
"--help			- Показать справку.\n"
"--snake-size	[val]	- Установить начальный размер змея.\n"
"--side-size	[val]	- Установть размер стороны поля.\n";

const std::vector<option> arg_list =
{	
	option{	.name = "--help", 
			.value = "",
			.has_value = false},

	option{ .name = "--snake-size",
			.value = "",
			.has_value = true},

	option{	.name = "--side-size",
			.value = "",
			.has_value = true}
};

} // namespace def

/**
 * @brief Класс для разбора параметров запуска.
 */
class COption : public IOption
{
private:
// Members	
	std::vector<option> m_arg_list;		// Прочитанные аргументы.

// Methods
	/**
	 * @brief Определить, является ли аргумент флагом.
	 * @param opt Строковое значение аргумента.
	 * @return std::pair<bool, option>: first == true, если является флагом.
	 */
	std::pair<bool, option> isOption (const std::string & opt);

	/**
	 * @brief Печать сообщения от класса.
	 * @param text Сообщение.
	 */
	void print (const std::string & text);

	/**
	 * @brief Печать ошибки от класса.
	 * @param text Сообщение.
	 */
	void error (const std::string & text);

public:
// Methods	
	COption ();
	~COption () override;

	/**
	 * @brief Инициализировать объект.
	 * 
	 * @param argc Количество аргументов.
	 * @param argv Массив аргументов.
	 * @returns true - в случае успешной инициализации,
	 * 			false - в случае ошибки.
	 */
	bool init (const int & argc, const char ** argv) override;

	/**
	 * @brief Получить целочисленное значение параметра.
	 * @param name Имя параметра.
	 * @param def_val Значение по умолчанию.
	 */
	int getInt (const std::string & name, const int & def_val) override;

	/**
	 * @brief Получить строковое значение параметра.
	 * @param name Имя параметра.
	 * @param def_val Значение по умолчанию.
	 */
	std::string getString (const std::string & name, 
								  const std::string & def_val) override;

	/**
	 * @brief Получить значение параметра в виде числа с плавающей точкой.
	 * @param name Имя параметра.
	 * @param def_val Значение по умолчанию.
	 * @return double 
	 */
	double getDouble (const std::string & name,
							 const double & def_val) override;
	
	/**
	 * @brief Узнать, установлен ли флаг '--help'.
	 * @returns true - если установлен, false - если не установлен.
	 */
	bool needHelp () override;
};

#endif // COPTION_HPP