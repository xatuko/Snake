#include "csnake.hpp"
#include "cbox.hpp"

#include <memory>
#include <chrono>

int dir = 1;
std::atomic_int ex {0};
std::atomic<bool> status {true};
std::atomic_bool is_pause {false};

void reader(std::shared_ptr<ISnake> snake)
{
	int c;
	while(status)
	{
		c = getc(stdin);
		switch(c)
		{
			case 66:
				dir = 1;
				break;
			case 65:
				dir = 0;
				break;
			case 67:
				dir = 3;
				break;
			case 68:
				dir = 2;
				break;
			case 113:
				status = false;
			case 112:
				is_pause = !is_pause;
			default:
				break;
		}
		snake->setDir(dir);
	}
}

int main(int, char**)
{
	std::shared_ptr<ISnake> snake = std::make_shared<CSnake>();
	std::unique_ptr<IBox> box = std::make_unique<CBox>();
	std::thread thr(reader, std::ref(snake));

	snake->setDir(1);
	box->addSnake(snake);
	box->setSideSize(20);
	if (!box->init())
		return -1;

	while (status)
	{
		if (!is_pause)
		{
			//snake->setDir(dir);
			snake->step();

			if (!box->draw())
			{
				status = false;
			}
			std::cout << "Длина змея: " << snake->getSnake().size();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	thr.join();
	return 0;
}

// int mai2n(int, char**) {
// 	dir = {1};
// 	status = {true};
// 	Snake kobra;
// 	std::thread thr(reader);
	
	
// 	system("clear");
// 	std::vector<std::string> buf;
	
// 	kobra.draw(10,10, buf);
// 	printBuf(buf);
// 	sleep(1);

// 	for(int i = 0; i < 20; i++)
// 	{
		
// 		system("clear");
// 		kobra.setDir(dir);
// 		kobra.step();
// 		kobra.draw(10,10, buf);
// 		printBuf(buf);
// 		sleep(1);
// 	}
// 	status = {false};
// 	thr.join();
// 	return 0;
// }
