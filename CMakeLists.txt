cmake_minimum_required(VERSION 3.0.0)
project(Snake VERSION 0.1.0)

find_package(Threads REQUIRED)
#find_library(PTHREAD_LIBRARY pthread)
add_executable(Snake main.cpp csnake.cpp cbox.cpp cfood.cpp)
target_link_libraries(Snake Threads::Threads)