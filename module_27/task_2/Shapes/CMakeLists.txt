cmake_minimum_required(VERSION 3.5)

project(Shapes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Shapes main.cpp shapes.cpp shapes.h)
