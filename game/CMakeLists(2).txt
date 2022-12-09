cmake_minimum_required(VERSION 3.0)
set(THIS LyrsGame)
project(${THIS} LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/SDL2.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_image.dll
    ${CMAKE_CURRENT_SOURCE_DIR}/SDL2_ttf.dll
)
add_executable(${THIS} src/main.cpp)