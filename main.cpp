#include "coption.hpp"
#include "ccontroller.hpp"

#include <memory>
#include <chrono>

int main(int argc, const char *argv[])
{
	std::shared_ptr<IOption> opt = std::make_shared<COption>();
	if (!opt->init(argc, argv))
		return -1;
	if (opt->needHelp())
		return -1;

	std::shared_ptr<IController> app = std::make_shared<CController>();
	if (!app->init(opt->getInt("--side-size", 20),
				   opt->getInt("--snake-size", 3)))
		return -1;
	
	app->start();

	while (app->isInit());

	return 0;
}

// int main(int, char**)
// {
// 	std::shared_ptr<ISnake> snake = std::make_shared<CSnake>();
// 	std::unique_ptr<IBox> box = std::make_unique<CBox>();

// 	snake->setDir(DIRECTION::DOWN);
// 	box->addSnake(snake);
// 	box->setSideSize(20);
// 	if (!box->init())
// 		return -1;

// 	while (box->isRunning())
// 	{
// 		if (!box->isPause())
// 		{
// 			snake->step();

// 			if (!box->draw())
// 				break;
// 		}
// 		std::this_thread::sleep_for(std::chrono::milliseconds(250));
// 	}

// 	return 0;
// }
