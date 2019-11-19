cmake_minimum_required (VERSION 2.6)
project (TP3)
add_executable(TP3 main.cpp
        Client.cpp
        ClientPrestige.cpp
        ClientRegulier.cpp
        Menu.cpp
        Plat.cpp
        PlatBio.cpp
        PlatCustom.cpp
        Restaurant.cpp
        Table.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/polyFood.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)