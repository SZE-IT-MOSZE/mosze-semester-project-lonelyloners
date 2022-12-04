cmake_minimum_required(VERSION 3.0)
set(THIS LyrsGame)
project(${THIS} LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(include)
add_subdirectory(src)
Option(BUILD_EXAMPLES "WHETER OR NOT TO BUILD"
ON)

if(BUILD_EXAMPLES)
    message(STATUS "BUILDING MAIN")
    add_executable(main src/main.cpp)
endif()

target_link_libraries(main
    PRIVATE
    sdl
    headers
    HDR
)