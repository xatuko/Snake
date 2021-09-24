#ifndef IBOX_HPP
#define IBOX_HPP

class IBox
{
public:
	IBox() = default;
	virtual ~IBox() = default;

	virtual void setSideSize(const int & size) = 0;
	virtual bool init() = 0;
	virtual void draw() = 0;
	virtual bool isInit() = 0;
};

#endif // IBOX_HPP