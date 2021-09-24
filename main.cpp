#include "snake.hpp"
#include "cbox.hpp"

#include <memory>

std::atomic<uint8_t> dir;
std::atomic<bool> status;


void reader()
{
	int c;
	while(status)
	{
		c = getc(stdin);
		switch(c)
		{
			case 66:
				dir = {1};
				break;
			case 65:
				dir = {0};
				break;
			case 67:
				dir = {3};
				break;
			case 68:
				dir = {2};
				break;
			default:
				break;
		}
	}
}

int main(int, char**)
{
	std::unique_ptr<IBox> box = std::make_unique<CBox>();
	box->setSideSize(20);
	if (box->init())
		box->draw();
	return 0;
}

int mai2n(int, char**) {
	dir = {1};
	status = {true};
	Snake kobra;
	std::thread thr(reader);
	
	
	system("clear");
	std::vector<std::string> buf;
	
	kobra.draw(10,10, buf);
	printBuf(buf);
	sleep(1);

	for(int i = 0; i < 20; i++)
	{
		
		system("clear");
		kobra.setDir(dir);
		kobra.step();
		kobra.draw(10,10, buf);
		printBuf(buf);
		sleep(1);
	}
	status = {false};
	thr.join();
	return 0;
}
