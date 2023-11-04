cmake_minimum_required(VERSION 3.26)
project(CLI_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "")

add_executable(CLI_game main.cpp
        classes/Player.h
        headers/inventory_functions.h
        classes/inventory.h
        classes/Vector2D.h
        classes/renderer.h
        classes/WorldGenerator.h
        headers/kbhit_alternative.h
        classes/InputHandler.h
        classes/renderer_extension.h
        headers/functions.h)

add_executable(toRange_test tests/toRange_test.cpp
headers/functions.h)
enable_testing()
set(CTEST_OUTPUT_ON_FAILURE, True)
add_test(
    NAME toRange_test
        COMMAND $<TARGET_FILE:toRange_test>
)
