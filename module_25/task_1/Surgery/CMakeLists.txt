cmake_minimum_required(VERSION 3.5)

project(Surgery LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Surgery main.cpp surgery.cpp surgery.h)
