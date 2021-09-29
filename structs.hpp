#ifndef STRUCTS_HPP
#define STRUCTS_HPP

enum class DIRECTION
{
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

struct Elem
{
	int x;
	int y;
	Elem *next;
};

#endif // STRUCTS_HPP