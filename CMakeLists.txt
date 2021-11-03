cmake_minimum_required(VERSION 3.0.0)
project(Snake_v1.0 VERSION 1.0.0)

find_package(Threads REQUIRED)
add_executable(Snake_v1.0 main.cpp csnake.cpp cbox.cpp cfood.cpp ccontroller.cpp coption.cpp)
target_link_libraries(Snake_v1.0 Threads::Threads)