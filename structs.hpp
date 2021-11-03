#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <string>

enum class DIRECTION
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

struct Elem
{
	size_t x;
	size_t y;
	Elem *next;
};

struct option
{
	std::string name;
	std::string value;
	bool has_value;
};

#endif // STRUCTS_HPP