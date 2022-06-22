cmake_minimum_required(VERSION 3.5)

project(Shopping_basket LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS basket.h)
set(SRC main.cpp basket.cpp)

add_executable(Shopping_basket ${SRC} ${HEADERS})
