#ifndef IBOX_HPP
#define IBOX_HPP

#include "csnake.hpp"

class IBox
{
public:
	IBox() = default;
	virtual ~IBox() = default;

	virtual void setSideSize(const int & size) = 0;
	virtual bool init() = 0;
	virtual bool draw() = 0;
	virtual bool isInit() = 0;
	virtual void addSnake(std::shared_ptr<ISnake> snake) = 0;
	virtual void clearBuf() = 0;
};

#endif // IBOX_HPP