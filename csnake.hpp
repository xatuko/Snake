#ifndef CSNAKE_HPP
#define CSNAKE_HPP

#include "isnake.hpp"

#include <vector>
#include <string>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <termios.h>
#include <atomic>


void printBuf(std::vector<std::string> &buf);



class CSnake : public ISnake
{
public:
	CSnake();
	~CSnake() override;
	void step() override;
	void draw(int x_size, int y_size, std::vector<std::string>&);
	void setDir(int) override;
	bool getStatus() override;
	std::vector<Elem> getSnake() override { return m_snake; }
	
private:
	DIRECTION m_direction;
	std::vector<Elem> m_snake;
	int m_length;
	struct std::atomic<bool> m_status;
	std::pair<int,int> getHead() override;
	void setNewHead(int x, int y) override;
};

#endif // CSNAKE_HPP