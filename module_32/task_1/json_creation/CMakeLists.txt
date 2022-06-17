cmake_minimum_required(VERSION 3.5)

project(json_creation LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(json_creation main.cpp)

target_link_libraries(json_creation PRIVATE nlohmann_json::nlohmann_json)


