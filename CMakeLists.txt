cmake_minimum_required(VERSION 3.1)
project(Tic_Tac_Toe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -static-libgcc -static-libstdc++")

set(SOURCE_FILES main.cpp)
add_executable(Tic_Tac_Toe ${SOURCE_FILES})