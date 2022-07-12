cmake_minimum_required(VERSION 3.14)

project(HTMLEditor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets WebEngineWidgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets WebEngineWidgets REQUIRED)

add_executable(HTMLEditor
  main.cpp
)
target_link_libraries(HTMLEditor Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::WebEngineCore Qt${QT_VERSION_MAJOR}::WebEngineWidgets)
