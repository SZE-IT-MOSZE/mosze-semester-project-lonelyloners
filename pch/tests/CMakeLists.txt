cmake_minimum_required(VERSION 3.0)

set(This gametest)

set(Sources
    gametest.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This} PUBLIC
    gtest_main
    pch
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
