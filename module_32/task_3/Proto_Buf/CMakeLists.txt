cmake_minimum_required(VERSION 3.5)

project(Proto_Buf LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Proto_Buf main.cpp Company.proto)
