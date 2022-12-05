cmake_minimum_required(VERSION 3.0)
set(THIS LyrsGame)
project(${THIS} LANGUAGES C CXX)
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../sdl/SDL_Main.h
)
add_library(HDR ${SOURCES})
target_include_directories(HDR PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../sdl/SDL_Main.h
)
