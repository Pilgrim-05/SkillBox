cmake_minimum_required(VERSION 3.5)

project(PC_simulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC main.cpp cpu.cpp ram.cpp disk.cpp gpu.cpp kbd.cpp)
set(HEAD cpu.h ram.h disk.h gpu.h kbd.h)

add_executable(PC_simulator ${SRC} ${HEAD})