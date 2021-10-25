#include "csnake.hpp"
#include "cbox.hpp"

#include <memory>
#include <chrono>

int main(int, char**)
{
	std::shared_ptr<ISnake> snake = std::make_shared<CSnake>();
	std::unique_ptr<IBox> box = std::make_unique<CBox>();

	snake->setDir(DIRECTION::DOWN);
	box->addSnake(snake);
	box->setSideSize(20);
	if (!box->init())
		return -1;

	while (box->isRunning())
	{
		if (!box->isPause())
		{
			snake->step();

			if (!box->draw())
				break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	return 0;
}
