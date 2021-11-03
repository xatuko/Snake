#ifndef IBOX_HPP
#define IBOX_HPP

#include "csnake.hpp"
#include "ifood.hpp"

class IBox
{
public:
	IBox() = default;
	virtual ~IBox() = default;

	virtual void setSideSize(const int & size) = 0;
	virtual void addSnake(std::shared_ptr<ISnake> snake) = 0;
	virtual void addFood(std::shared_ptr<IFood> food) = 0;
	virtual void clearBuf() = 0;

	virtual bool isInit() = 0;
	virtual bool draw() = 0;
	virtual bool init() = 0;

	virtual const size_t & getSideSize() = 0; 

	virtual std::pair<size_t, size_t> getBegPos() = 0;


};

#endif // IBOX_HPP