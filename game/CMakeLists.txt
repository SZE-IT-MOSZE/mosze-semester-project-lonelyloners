cmake_minimum_required(VERSION 3.25.0)
set(THIS LyrsGame)
project(${THIS} LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(SOURCES
    ./../src/csv2vector.cpp
    "./../src/Command.cpp"
    ./../src/csv2vector.cpp
    ./../src/entity.cpp
    ./../src/main.cpp
    ./../src/RenderWindow.cpp
    ./../src/Router.cpp
    ./../include/sdl/SDL2.dll
    ./../include/sdl/SDL2_image.dll
    ./../bin/SDL2_ttf.dll
    ./../font/PatrickHand-Regular.ttf
)
set(HEADERS
    # ./../include/headers/Collision.h
    # "./../include/headers/Command.h"
    # ./../include/headers/csv2vector.h
    # ./../include/headers/Dessert1.h
    # ./../include/headers/Dessert2.h
    # ./../include/headers/Entity.h
    # ./../include/headers/Glacies.h
    # ./../include/headers/Math.h
    # ./../include/headers/Menu.h
    # ./../include/headers/Planet1.h
    # ./../include/headers/Player.h
    # ./../include/headers/Prolog.h
    # ./../include/headers/RenderPlanets.h
    # ./../include/headers/RenderWindow.h
    # ./../include/headers/Router.h
    # ./../include/headers/Utils.h
    # ./../include/sdl/SDL.h
)
# set(LIBRARIES
#     ./../story
#     ./../res
#     ./../res/gfx
#     # ./../story/aeden1a1.txt
#     # ./../story/aeden1b.txt
#     # ./../story/bevezeto.txt
#     # ./../story/dessert1.1.txt
#     # ./../story/dessert1.2.txt
#     # ./../story/dessert1.3.txt
#     # ./../story/dessert1.4.txt
#     # ./../story/dessert2a1.txt
#     # ./../story/dessert2a2.txt
#     # ./../story/dessert2b.txt
#     # ./../story/dessert3a1.txt
#     # ./../story/dessert3a2.txt
#     # ./../story/dessert3a3.txt
#     # ./../story/dessert3b.txt
#     # ./../story/dessert3c.txt
#     # ./../story/dessert3d.txt
#     # ./../story/dessert4a.txt
#     # ./../story/dessert4b.txt
#     # ./../story/dessert4c.txt
#     # ./../story/dessert4d.txt
#     # ./../story/dessert4e.txt
#     # ./../story/dessert5a.txt
#     # ./../story/dessert5b.txt
#     # ./../story/glacies1.txt
#     # ./../story/glacies2.txt
#     # ./../story/glacies3a.txt
#     # ./../story/glacies3b.txt
#     # ./../story/glacies3c.txt
#     # ./../story/glacies3d.txt
#     # ./../story/glacies4a.txt
#     # ./../story/glacies4b.txt
#     # ./../story/glacies4c.txt
#     # ./../story/glacies4d.txt
#     # ./../story/glacies4e.txt
#     # ./../story/glacies4f.txt
#     # ./../story/glacies5a.txt
#     # ./../story/glacies5b.txt
#     # ./../story/nosoria1.txt
#     # ./../story/nosoria2b1.txt
#     # ./../story/nosoria2b2.txt
#     # ./../story/nosoria2b3.txt
#     # ./../story/nosoria3a.txt
#     # ./../story/nosoria3b.txt
#     # ./../story/planthea1b.txt
#     # ./../story/planthea1b1.txt
#     # ./../story/planthea1b2.txt
#     # ./../story/planthea1b3.txt
#     # ./../story/planthea1b4.txt
#     # ./../story/planthea2a1.txt
#     # ./../story/planthea2a2.txt
#     # ./../story/planthea2a3.txt
#     # ./../story/planthea2b1.txt
#     # ./../story/planthea2b2.txt
#     # ./../story/planthea3a1.txt
#     # ./../story/planthea3a2.txt
#     # ./../story/planthea3a3.txt
#     # ./../story/planthea3a4.txt
#     # ./../story/planthea3b1.txt
#     # ./../story/planthea3b2.txt
#     # ./../story/planthea3b3.txt
#     # ./../story/planthea3b4.txt
#     # ./../story/planthea3b5.txt
#     # ./../story/planthea3b6.txt
#     # ./../story/prologus.txt
#     # ./../story/segitseg.txt
# )
LIST(APPEND CMAKE_PROGRAM_PATH 
    # ./../include
    # ./../include/sdl
    ${CMAKE_CURRENT_SOURCE_DIR}/include/sdl
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ./../src
    ./../story
    ./../res
    ./../res/gfx
)
add_executable(${THIS} ./../src/main.cpp ${SOURCES} ${HEADERS} ${LIBRARIES})
target_include_directories(${THIS} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    # ./../src
    # ./../story
    ${CMAKE_CURRENT_SOURCE_DIR}/story
    ./../res
    # ./../res/gfx
    # ./../res/gfx/Animations
    # ./../res/gfx/Characters
    # ./../res/gfx/Dessert_Map1
    # ./../res/gfx/Dessert_Map2
    # ./../res/gfx/Menu
    # ./../res/gfx/Objects
    # ./../res/gfx/Animations
    # ./../res/gfx/Animations/Dessert_bolygo
    # ./../res/gfx/Animations/Glacies_bolygo
    # ./../res/gfx/Animations/Keszitok
    # ./../res/gfx/Animations/LyRs
    # ./../res/gfx/Animations/Nosoria_bolygo
    # ./../res/gfx/Animations/Planthea_bolygo
    # ./../res/gfx/Characters
    # ./../res/gfx/Dessert Map2
    # ./../res/gfx/Dessert_Map1
    # ./../res/gfx/Dessert_Map2
    # ./../res/gfx/Glacies_map
    # ./../res/gfx/Menu
    # ./../res/gfx/Nosoria_map
    # ./../res/gfx/Objects
    # ./../res/gfx/Planthea_map 
    )
 target_link_libraries(${THIS}
        ${CMAKE_SOURCE_DIR}/lib/libSDL2_image.dll.a
        ${CMAKE_SOURCE_DIR}/lib/libSDL2_ttf.dll.a
        ${CMAKE_SOURCE_DIR}/bin/SDL2_ttf.dll
        ${CMAKE_SOURCE_DIR}/SDL2_ttf.dll
        ${CMAKE_SOURCE_DIR}/lib/libSDL2.dll.a
       )
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")
 if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
   set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/SDL2main.lib")#x64/
 else ()
   set(SDL2_LIBRARIES "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2.lib;${CMAKE_CURRENT_LIST_DIR}/lib/SDL2main.lib")#x86/
 endif ()
string(STRIP "${SDL2_LIBRARIES}" SDL2_LIBRARIES)
if(NOT SDL2_DIR)
  set(SDL2_DIR "" CACHE PATH "SDL2 directory")
endif()
find_path(SDL2_INCLUDE_DIR SDL.h
  HINTS
    ENV SDL2DIR
    ${SDL2_DIR}
  PATH_SUFFIXES SDL2
                include/SDL2 include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(VC_LIB_PATH_SUFFIX lib/x64)
else()
  set(VC_LIB_PATH_SUFFIX lib/x86)
endif()
find_library(SDL2_LIBRARY_TEMP
  NAMES SDL2
  HINTS
    ENV SDL2DIR
    ${SDL2_DIR}
  PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
)
set_property(CACHE SDL2_LIBRARY_TEMP PROPERTY TYPE INTERNAL)
if(NOT SDL2_BUILDING_LIBRARY)
  if(NOT SDL2_INCLUDE_DIR MATCHES ".framework")
    find_library(SDL2MAIN_LIBRARY
      NAMES SDL2main
      HINTS
        ENV SDL2DIR
        ${SDL2_DIR}
      PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
      PATHS
      /sw
      /opt/local
      /opt/csw
      /opt
    )
  endif()
endif()
if(NOT APPLE)
  find_package(Threads)
endif()
if(MINGW)
  set(MINGW32_LIBRARY mingw32 "-mwindows" CACHE STRING "link flags for MinGW")
endif()
if(SDL2_LIBRARY_TEMP)
  if(SDL2MAIN_LIBRARY AND NOT SDL2_BUILDING_LIBRARY)
    list(FIND SDL2_LIBRARY_TEMP "${SDLMAIN_LIBRARY}" _SDL2_MAIN_INDEX)
    if(_SDL2_MAIN_INDEX EQUAL -1)
      set(SDL2_LIBRARY_TEMP "${SDLMAIN_LIBRARY}" ${SDL2_LIBRARY_TEMP})
    endif()
    unset(_SDL2_MAIN_INDEX)
  endif()
  if(APPLE)
    set(SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} "-framework Cocoa")
  endif()
  if(NOT APPLE)
    set(SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} ${CMAKE_THREAD_LIBS_INIT})
  endif()
  if(MINGW)
    set(SDL2_LIBRARY_TEMP ${MINGW32_LIBRARY} ${SDL2_LIBRARY_TEMP})
  endif()
  set(SDL2_LIBRARY ${SDL2_LIBRARY_TEMP} CACHE STRING "Where the SDL Library can be found")
endif()
if(SDL2_INCLUDE_DIR AND EXISTS "${SDL2_INCLUDE_DIR}/SDL2_version.h")
  file(STRINGS "${SDL2_INCLUDE_DIR}/SDL2_version.h" SDL2_VERSION_MAJOR_LINE REGEX "^#define[ \t]+SDL2_MAJOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_INCLUDE_DIR}/SDL2_version.h" SDL2_VERSION_MINOR_LINE REGEX "^#define[ \t]+SDL2_MINOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_INCLUDE_DIR}/SDL2_version.h" SDL2_VERSION_PATCH_LINE REGEX "^#define[ \t]+SDL2_PATCHLEVEL[ \t]+[0-9]+$")
  string(REGEX REPLACE "^#define[ \t]+SDL2_MAJOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_VERSION_MAJOR "${SDL2_VERSION_MAJOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL2_MINOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_VERSION_MINOR "${SDL2_VERSION_MINOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL2_PATCHLEVEL[ \t]+([0-9]+)$" "\\1" SDL2_VERSION_PATCH "${SDL2_VERSION_PATCH_LINE}")
  set(SDL2_VERSION_STRING ${SDL2_VERSION_MAJOR}.${SDL2_VERSION_MINOR}.${SDL2_VERSION_PATCH})
  unset(SDL2_VERSION_MAJOR_LINE)
  unset(SDL2_VERSION_MINOR_LINE)
  unset(SDL2_VERSION_PATCH_LINE)
  unset(SDL2_VERSION_MAJOR)
  unset(SDL2_VERSION_MINOR)
  unset(SDL2_VERSION_PATCH)
endif()
set(SDL2_LIBRARIES ${SDL2_LIBRARY} ${SDL2MAIN_LIBRARY})
set(SDL2_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL
                                  REQUIRED_VARS SDL2_LIBRARY SDL2_INCLUDE_DIR
                                  VERSION_VAR SDL2_VERSION_STRING)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(${THIS}  ${SDL2_IMAGE_LIBRARIES})#${SDL2_LIBRARIES}
if(NOT SDL2_IMAGE_INCLUDE_DIR AND SDL2IMAGE_INCLUDE_DIR)
  set(SDL2_IMAGE_INCLUDE_DIR ${SDL2IMAGE_INCLUDE_DIR} CACHE PATH "directory cache entry initialized from old variable name")
endif()
find_path(SDL2_IMAGE_INCLUDE_DIR SDL_image.h
  HINTS
    ENV SDL2IMAGEDIR
    ENV SDL2DIR
    ${SDL2_DIR}
  PATH_SUFFIXES SDL2
                include/SDL2 include
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(VC_LIB_PATH_SUFFIX lib/x64)
else()
  set(VC_LIB_PATH_SUFFIX lib/x86)
endif()
if(NOT SDL2_IMAGE_LIBRARY AND SDL2IMAGE_LIBRARY)
  set(SDL2_IMAGE_LIBRARY ${SDL2IMAGE_LIBRARY} CACHE FILEPATH "file cache entry initialized from old variable name")
endif()
find_library(SDL2_IMAGE_LIBRARY
  NAMES SDL2_image
  HINTS
    ENV SDL2IMAGEDIR
    ENV SDL2DIR
    ${SDL2_DIR}
  PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
)
if(SDL2_IMAGE_INCLUDE_DIR AND EXISTS "${SDL2_IMAGE_INCLUDE_DIR}/SDL2_image.h")
  file(STRINGS "${SDL2_IMAGE_INCLUDE_DIR}/SDL2_image.h" SDL2_IMAGE_VERSION_MAJOR_LINE REGEX "^#define[ \t]+SDL2_IMAGE_MAJOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_IMAGE_INCLUDE_DIR}/SDL2_image.h" SDL2_IMAGE_VERSION_MINOR_LINE REGEX "^#define[ \t]+SDL2_IMAGE_MINOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_IMAGE_INCLUDE_DIR}/SDL2_image.h" SDL2_IMAGE_VERSION_PATCH_LINE REGEX "^#define[ \t]+SDL2_IMAGE_PATCHLEVEL[ \t]+[0-9]+$")
  string(REGEX REPLACE "^#define[ \t]+SDL2_IMAGE_MAJOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_IMAGE_VERSION_MAJOR "${SDL2_IMAGE_VERSION_MAJOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL2_IMAGE_MINOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_IMAGE_VERSION_MINOR "${SDL2_IMAGE_VERSION_MINOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL2_IMAGE_PATCHLEVEL[ \t]+([0-9]+)$" "\\1" SDL2_IMAGE_VERSION_PATCH "${SDL2_IMAGE_VERSION_PATCH_LINE}")
  set(SDL2_IMAGE_VERSION_STRING ${SDL2_IMAGE_VERSION_MAJOR}.${SDL2_IMAGE_VERSION_MINOR}.${SDL2_IMAGE_VERSION_PATCH})
  unset(SDL2_IMAGE_VERSION_MAJOR_LINE)
  unset(SDL2_IMAGE_VERSION_MINOR_LINE)
  unset(SDL2_IMAGE_VERSION_PATCH_LINE)
  unset(SDL2_IMAGE_VERSION_MAJOR)
  unset(SDL2_IMAGE_VERSION_MINOR)
  unset(SDL2_IMAGE_VERSION_PATCH)
endif()
set(SDL2_IMAGE_LIBRARIES ${SDL2_IMAGE_LIBRARY})
set(SDL2_IMAGE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIR})
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_image
                                  REQUIRED_VARS SDL2_IMAGE_LIBRARIES SDL2_IMAGE_INCLUDE_DIRS
                                  VERSION_VAR SDL2_IMAGE_VERSION_STRING)
set(SDL2IMAGE_LIBRARY ${SDL2_IMAGE_LIBRARIES})
set(SDL2IMAGE_INCLUDE_DIR ${SDL2_IMAGE_INCLUDE_DIRS})
set(SDL2IMAGE_FOUND ${SDL2_IMAGE_FOUND})
mark_as_advanced(SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)
find_package(SDL2 REQUIRED)
if(NOT SDL2_FOUND)
  set(SDL2_TTF_SDL2_NOT_FOUND "Could NOT find SDL2 (SDL2 is required by SDL2_ttf).")
  if(SDL2_ttf_FIND_REQUIRED)
    message(FATAL_ERROR ${SDL2_TTF_SDL2_NOT_FOUND})
  else()
      if(NOT SDL2_ttf_FIND_QUIETLY)
        message(STATUS ${SDL2_TTF_SDL2_NOT_FOUND})
      endif()
    return()
  endif()
  unset(SDL2_TTF_SDL2_NOT_FOUND)
endif()
set(SDL2_TTF_PATH "./../lib" CACHE STRING "Custom SDL2_ttf Library path")
set(_SDL2_TTF_NO_DEFAULT_PATH OFF)
if(SDL2_TTF_PATH)
  set(_SDL2_TTF_NO_DEFAULT_PATH ON)
endif()
set(SDL2_TTF_NO_DEFAULT_PATH ${_SDL2_TTF_NO_DEFAULT_PATH}
    CACHE BOOL "Disable search SDL2_ttf Library in default path")
unset(_SDL2_TTF_NO_DEFAULT_PATH)
set(SDL2_TTF_NO_DEFAULT_PATH_CMD)
if(SDL2_TTF_NO_DEFAULT_PATH)
  set(SDL2_TTF_NO_DEFAULT_PATH_CMD NO_DEFAULT_PATH)
endif()
find_path(SDL2_TTF_INCLUDE_DIR SDL_ttf.h
  HINTS
    ENV SDL2TTFDIR
    ENV SDL2DIR
    ${SDL2_TTF_NO_DEFAULT_PATH_CMD}
  PATH_SUFFIXES SDL2
                include/SDL2 include
  PATHS ${SDL2_TTF_PATH}
  DOC "Where the SDL2_ttf headers can be found"
)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(VC_LIB_PATH_SUFFIX lib/x64)
else()
  set(VC_LIB_PATH_SUFFIX lib/x86)
endif()
find_library(SDL2_TTF_LIBRARY
  NAMES SDL2_ttf
  HINTS
    ENV SDL2TTFDIR
    ENV SDL2DIR
    ${SDL2_TTF_NO_DEFAULT_PATH_CMD}
  PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
  PATHS ${SDL2_TTF_PATH}
  DOC "Where the SDL2_ttf Library can be found"
)
if(SDL2_TTF_INCLUDE_DIR AND EXISTS "${CMAKE_CURRENT_SORCE_DIR}/include/sdl/SDL_ttf.h")
  file(STRINGS "${SDL2_TTF_INCLUDE_DIR}/SDL_ttf.h" SDL2_TTF_VERSION_MAJOR_LINE REGEX "^#define[ \t]+SDL_TTF_MAJOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_TTF_INCLUDE_DIR}/SDL_ttf.h" SDL2_TTF_VERSION_MINOR_LINE REGEX "^#define[ \t]+SDL_TTF_MINOR_VERSION[ \t]+[0-9]+$")
  file(STRINGS "${SDL2_TTF_INCLUDE_DIR}/SDL_ttf.h" SDL2_TTF_VERSION_PATCH_LINE REGEX "^#define[ \t]+SDL_TTF_PATCHLEVEL[ \t]+[0-9]+$")
  string(REGEX REPLACE "^#define[ \t]+SDL_TTF_MAJOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_TTF_VERSION_MAJOR "${SDL2_TTF_VERSION_MAJOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL_TTF_MINOR_VERSION[ \t]+([0-9]+)$" "\\1" SDL2_TTF_VERSION_MINOR "${SDL2_TTF_VERSION_MINOR_LINE}")
  string(REGEX REPLACE "^#define[ \t]+SDL_TTF_PATCHLEVEL[ \t]+([0-9]+)$" "\\1" SDL2_TTF_VERSION_PATCH "${SDL2_TTF_VERSION_PATCH_LINE}")
  set(SDL2_TTF_VERSION_STRING ${SDL2_TTF_VERSION_MAJOR}.${SDL2_TTF_VERSION_MINOR}.${SDL2_TTF_VERSION_PATCH})
  unset(SDL2_TTF_VERSION_MAJOR_LINE)
  unset(SDL2_TTF_VERSION_MINOR_LINE)
  unset(SDL2_TTF_VERSION_PATCH_LINE)
  unset(SDL2_TTF_VERSION_MAJOR)
  unset(SDL2_TTF_VERSION_MINOR)
  unset(SDL2_TTF_VERSION_PATCH)
endif()
set(SDL2_TTF_LIBRARIES ${SDL2_TTF_LIBRARY})
set(SDL2_TTF_INCLUDE_DIRS ${SDL2_TTF_INCLUDE_DIR})
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_ttf
                                  REQUIRED_VARS SDL2_TTF_LIBRARIES SDL2_TTF_INCLUDE_DIRS
                                  VERSION_VAR SDL2_TTF_VERSION_STRING)
mark_as_advanced(SDL2_TTF_PATH
                 SDL2_TTF_NO_DEFAULT_PATH
                 SDL2_TTF_LIBRARY
                 SDL2_TTF_INCLUDE_DIR)
if(SDL2_TTF_FOUND)
  if(SDL2_TTF_LIBRARY AND NOT TARGET SDL2::TTF)
    add_library(SDL2::TTF UNKNOWN IMPORTED)
    set_target_properties(SDL2::TTF PROPERTIES
                          IMPORTED_LOCATION "${SDL2_TTF_LIBRARY}"
                          INTERFACE_INCLUDE_DIRECTORIES "${SDL2_TTF_INCLUDE_DIR}"
                          INTERFACE_LINK_LIBRARIES SDL2::Core)
  endif()
endif()
if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(sdl2_ttf_config_path "${CMAKE_CURRENT_LIST_DIR}/../../i686-w64-mingw32/lib/cmake/SDL2_ttf/sdl2_ttf-config-version.cmake")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(sdl2_ttf_config_path "${CMAKE_CURRENT_LIST_DIR}/../../x86_64-w64-mingw32/lib/cmake/SDL2_ttf/sdl2_ttf-config-version.cmake")
else("${CMAKE_SIZEOF_VOID_P}" STREQUAL "")
    set(PACKAGE_VERSION_UNSUITABLE TRUE)
    return()
endif()
if(NOT EXISTS "${sdl2_ttf_config_path}")
    set(PACKAGE_VERSION_UNSUITABLE TRUE)
    return()
endif()
include("${sdl2_ttf_config_path}")
target_link_libraries(${THIS} PUBLIC SDL_ttf)