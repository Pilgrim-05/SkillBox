cmake_minimum_required(VERSION 3.5)

project(Fisherman LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(HEADERS field.h)
set(SRC main.cpp field.cpp)

add_executable(Fisherman ${SRC} ${HEADERS})
