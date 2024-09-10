cmake_minimum_required(VERSION 3.1)
project(SUDOKU)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


set(SOURCES src/main.cpp
src/board.cpp
src/gui.cpp
)


add_executable(
    play ${SOURCES}
)

# include_directories(include)
target_include_directories(play PRIVATE include)
