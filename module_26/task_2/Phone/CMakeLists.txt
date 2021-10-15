cmake_minimum_required(VERSION 3.5)

project(Phone LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS phone.h contact.h)
set(SRC main.cpp phone.cpp contact.cpp)

add_executable(Phone ${SRC} ${HEADERS})
