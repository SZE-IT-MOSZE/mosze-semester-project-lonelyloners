cmake_minimum_required(VERSION 3.0)
set(THIS LyrsGame)
project(${THIS})
set(SOURCES
    Command.cpp
    csv2vector.cpp
    entity.cpp
    RenderWindow.cpp
    Router.cpp
)
add_library(sdl  ${SOURCES})
target_include_directories(sdl PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
