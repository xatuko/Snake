cmake_minimum_required(VERSION 3.0.0)
project(Snake VERSION 0.1.0)

find_package(Threads REQUIRED)
add_executable(Snake main.cpp csnake.cpp cbox.cpp cfood.cpp ccontroller.cpp coption.cpp)
target_link_libraries(Snake Threads::Threads)