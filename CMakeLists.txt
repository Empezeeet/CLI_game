cmake_minimum_required(VERSION 3.26)
project(CLI_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-o a.out -lncurses")

add_executable(CLI_game main.cpp
        classes/Player.h
        headers/inventory_functions.h
        classes/inventory.h
        classes/Vector2D.h
        classes/renderer.h
        classes/InputHandler.h
        classes/WorldGenerator.h
        headers/worldgen_functions.h
        headers/kbhit_alternative.h)
