cmake_minimum_required(VERSION 3.15)
project(8puzzle)

set(CMAKE_CXX_STANDARD 14)

add_executable(8puzzle main.cpp game_state.h game_state.cpp solver.cpp solver.h greater_state.h)