cmake_minimum_required(VERSION 3.5)

project(Data_register LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS register.h)
set(SRC main.cpp register.cpp)

add_executable(Data_register ${SRC} ${HEADERS})
