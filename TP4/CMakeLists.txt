cmake_minimum_required (VERSION 2.8)
project (TP4)
set(CMAKE_CXX_STANDARD 17)

file(GLOB tp_SRC
    "*.h"
    "*.cpp"
)
add_executable(TP4 ${tp_SRC})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/polyFood.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
