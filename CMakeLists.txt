cmake_minimum_required(VERSION 3.5.0)

project(HelloWorld VERSION 0.1.0 LANGUAGES CXX)

add_executable(Minesweeper src/main.cpp src/field.cpp src/cell.cpp)

set_property(TARGET Minesweeper PROPERTY CXX_STANDARD 23)
