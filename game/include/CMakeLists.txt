set(THIS LyrsGame)
project(${THIS})# LANGUAGES C CXX)
#set(CMAKE_C_STANDARD 99)
#set(CMAKE_CXX_STANDARD 11)
add_subdirectory(sdl)
add_subdirectory(headers)
# set(THIS HDR)
# target_include_directories(${THIS} PUBLIC
#     ${CMAKE_CURRENT_SOURCE_DIR}/../include/*
#     ${CMAKE_CURRENT_SOURCE_DIR}/../include/sdl/*
#     ${CMAKE_CURRENT_SOURCE_DIR}/../include/headers/*
# )
# target_link_libraries(${THIS} PUBLIC
#     LyrsGame
#     SDL2
#     SRC
# )
# add_subdirectory(Headers)
# add_subdirectory(sdl)