#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <string>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <termios.h>
#include <atomic>


void printBuf(std::vector<std::string> &buf);

enum class DIRECTION
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

struct Elem
{
    int x;
    int y;
    Elem *next;
};

class Snake
{
public:
    Snake();
    ~Snake();
    void step();
    void draw(int x_size, int y_size, std::vector<std::string>&);
    void setDir(int);
    bool getStatus();
    void initTermios();
    void resetTermios();
    
private:
    DIRECTION direct;
    std::vector<Elem> snake;
    int length;
    struct std::atomic<bool> status;
    struct termios old, current;
};

#endif