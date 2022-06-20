cmake_minimum_required(VERSION 3.5)

project(JSON_Parsing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(JSON_Parsing main.cpp)

target_link_libraries(JSON_Parsing PRIVATE nlohmann_json::nlohmann_json)
