cmake_minimum_required(VERSION 3.0)

set(This pch)

project(${This} C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
enable_testing()

add_subdirectory(googletest)
set(Headers 
    pch.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../game/include/headers/
)
set(SOURCES
    pch.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../game/src/
)
include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/../game
${CMAKE_CURRENT_SOURCE_DIR}/../game/src
${CMAKE_CURRENT_SOURCE_DIR}/../game/include
${CMAKE_CURRENT_SOURCE_DIR}/../game/include/sdl
)
add_library(${This} STATIC ${SOURCES} ${HEADERS})
add_subdirectory(tests)
set(gtest_force_shared_crt:BOOL ON)