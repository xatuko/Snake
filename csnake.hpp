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
private:
// Members
	DIRECTION m_direction;
	std::vector<Elem> m_snake;
	int m_length;
	std::atomic_bool m_status;
// Methods
	std::pair<int,int> getHead() override;
	void setNewHead(int x, int y) override;
	void print(const std::string & text);
	bool error(const std::string & text);

public:
	CSnake();
	~CSnake() override;
	void setSize(const size_t & size) override;
	void setBegPos(const size_t & x, const size_t & y) override;
	bool init() override;

	void step() override;
	void draw(int x_size, int y_size, std::vector<std::string>&);
	void setDir(DIRECTION dir) override;
	bool getStatus() override;
	std::vector<Elem> getSnake() override { return m_snake; }
};

#endif // CSNAKE_HPP