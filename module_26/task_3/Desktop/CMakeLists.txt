cmake_minimum_required(VERSION 3.5)

project(Desktop LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER desktop.h My_window.h point.h)
set(SRC main.cpp desktop.cpp My_window.cpp point.cpp)

add_executable(Desktop ${SRC} ${HEADER})
