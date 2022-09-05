cmake_minimum_required(VERSION 3.23)
project(END_Snake)

set(CMAKE_CXX_STANDARD 14)
link_libraries(libeasyx.a)

add_executable(END_Snake main.cpp SNAKE.h SNAKE.cpp)
