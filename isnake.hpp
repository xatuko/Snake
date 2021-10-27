#ifndef ISNAKE_HPP
#define ISNAKE_HPP

#include "structs.hpp"

#include <vector>

class ISnake
{
public:
	ISnake() = default;
	virtual ~ISnake() = default;
	
	virtual void step() = 0;
	virtual void setDir(DIRECTION dir) = 0;
	virtual bool getStatus() = 0;
	virtual std::vector<Elem> getSnake() = 0;
	virtual std::pair<int,int> getHead() = 0;
	virtual void setNewHead(int x, int y) = 0;
	virtual bool init(const int & beg_size, const int & side_size) = 0;

};

#endif // ISNAKE_HPP