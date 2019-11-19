cmake_minimum_required (VERSION 2.6)
project (TP2)
add_executable(TP2 main.cpp
        Menu.cpp
        Plat.cpp
        Restaurant.cpp
        Table.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/polyFood.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)