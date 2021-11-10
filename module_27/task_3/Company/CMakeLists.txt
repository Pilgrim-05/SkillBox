cmake_minimum_required(VERSION 3.5)

project(Company LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADER employee.h)
set(SRC main.cpp employee.cpp)

add_executable(Company ${HEADER} ${SRC})
