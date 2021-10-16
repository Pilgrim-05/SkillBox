cmake_minimum_required(VERSION 3.5)

project(AudioPlayer LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS track.h player.h)
set(SRC main.cpp track.cpp player.cpp)

add_executable(AudioPlayer ${SRC} ${HEADERS})
