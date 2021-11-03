#ifndef ICONTROLLER_HPP
#define ICONTROLLER_HPP

class IController
{
public:
	IController() = default;
	virtual ~IController() = default;

	virtual bool init(const int & side_size, const int & snake_size) = 0;
	
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual bool isInit() = 0;
};

#endif // ICONTROLLER_HPP