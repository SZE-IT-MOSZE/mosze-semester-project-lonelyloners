cmake_minimum_required(VERSION 3.25.0)
set(THIS LyrsGame)
project(${THIS} LANGUAGES C CXX)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_EXE_LINKER_FLAGS "-static -libgcc -static -libstdc++")
set(SOURCES
    ./src/csv2vector.cpp
    "./src/Command.cpp"
    ./src/csv2vector.cpp
    ./src/entity.cpp
    ./src/main.cpp
    ./src/RenderWindow.cpp
    ./src/Router.cpp
    ./include/sdl/SDL2.dll
    ./include/sdl/SDL2_image.dll
    ./bin/SDL2_ttf.dll
    ./font/PatrickHand-Regular.ttf
    # "./build/LyrsGame.dir/src/Command.obj"
    # ./build/LyrsGame.dir/src/csv2vector.obj
    # ./build/LyrsGame.dir/src/entity.obj
    # ./build/LyrsGame.dir/src/math.obj
    # ./build/LyrsGame.dir/src/RenderWindow.obj
    # ./build/LyrsGame.dir/src/Router.obj
)

set(HEADERS
    ./include/headers/Collision.h
    "./include/headers/Command.h"
    ./include/headers/csv2vector.h
    ./include/headers/Dessert1.h
    ./include/headers/Dessert2.h
    ./include/headers/Entity.h
    ./include/headers/Glacies.h
    ./include/headers/Math.h
    ./include/headers/Menu.h
    ./include/headers/Planet1.h
    ./include/headers/Player.h
    ./include/headers/Prolog.h
    ./include/headers/RenderPlanets.h
    ./include/headers/RenderWindow.h
    ./include/headers/Router.h
    ./include/headers/Utils.h
    ./include/sdl/begin_code.h
    ./include/sdl/close_code.h
    ./include/sdl/SDL_assert.h
    ./include/sdl/SDL_atomic.h
    ./include/sdl/SDL_audio.h
    ./include/sdl/SDL_bits.h
    ./include/sdl/SDL_blendmode.h
    ./include/sdl/SDL_clipboard.h
    ./include/sdl/SDL_config.h
    ./include/sdl/SDL_cpuinfo.h
    ./include/sdl/SDL_egl.h
    ./include/sdl/SDL_endian.h
    ./include/sdl/SDL_error.h
    ./include/sdl/SDL_events.h
    ./include/sdl/SDL_filesystem.h
    ./include/sdl/SDL_gamecontroller.h
    ./include/sdl/SDL_gesture.h
    ./include/sdl/SDL_guid.h
    ./include/sdl/SDL_haptic.h
    ./include/sdl/SDL_hidapi.h
    ./include/sdl/SDL_hints.h
    ./include/sdl/SDL_image.h
    ./include/sdl/SDL_joystick.h
    ./include/sdl/SDL_keyboard.h
    ./include/sdl/SDL_keycode.h
    ./include/sdl/SDL_loadso.h
    ./include/sdl/SDL_locale.h
    ./include/sdl/SDL_log.h
    ./include/sdl/SDL_main.h
    ./include/sdl/SDL_messagebox.h
    ./include/sdl/SDL_metal.h
    ./include/sdl/SDL_misc.h
    ./include/sdl/SDL_mouse.h
    ./include/sdl/SDL_mutex.h
    ./include/sdl/SDL_name.h
    ./include/sdl/SDL_opengl_glext.h
    ./include/sdl/SDL_opengl.h
    ./include/sdl/SDL_opengles.h
    ./include/sdl/SDL_opengles2_gl2.h
    ./include/sdl/SDL_opengles2_gl2ext.h
    ./include/sdl/SDL_opengles2_gl2platform.h
    ./include/sdl/SDL_opengles2_khrplatform.h
    ./include/sdl/SDL_opengles2.h
    ./include/sdl/SDL_pixels.h
    ./include/sdl/SDL_platform.h
    ./include/sdl/SDL_power.h
    ./include/sdl/SDL_quit.h
    ./include/sdl/SDL_rect.h
    ./include/sdl/SDL_render.h
    ./include/sdl/SDL_revision.h
    ./include/sdl/SDL_rwops.h
    ./include/sdl/SDL_scancode.h
    ./include/sdl/SDL_sensor.h
    ./include/sdl/SDL_shape.h
    ./include/sdl/SDL_stdinc.h
    ./include/sdl/SDL_surface.h
    ./include/sdl/SDL_system.h
    ./include/sdl/SDL_syswm.h
    ./include/sdl/SDL_test_assert.h
    ./include/sdl/SDL_test_common.h
    ./include/sdl/SDL_test_compare.h
    ./include/sdl/SDL_test_crc32.h
    ./include/sdl/SDL_test_font.h
    ./include/sdl/SDL_test_fuzzer.h
    ./include/sdl/SDL_test_harness.h
    ./include/sdl/SDL_test_images.h
    ./include/sdl/SDL_test_log.h
    ./include/sdl/SDL_test_md5.h
    ./include/sdl/SDL_test_memory.h
    ./include/sdl/SDL_test_random.h
    ./include/sdl/SDL_test.h
    ./include/sdl/SDL_thread.h
    ./include/sdl/SDL_timer.h
    ./include/sdl/SDL_touch.h
    ./include/sdl/SDL_ttf.h
    ./include/sdl/SDL_types.h
    ./include/sdl/SDL_version.h
    ./include/sdl/SDL_video.h
    ./include/sdl/SDL_vulkan.h
    ./include/sdl/SDL.h
    
)
set(LIBRARIES
    ./story
    ./res
    ./res/gfx
    ./../story
    ./../res
    ./../res/gfx
    ./story/aeden1a1.txt
    ./story/aeden1b.txt
    ./story/bevezeto.txt
    ./story/dessert1.1.txt
    ./story/dessert1.2.txt
    ./story/dessert1.3.txt
    ./story/dessert1.4.txt
    ./story/dessert2a1.txt
    ./story/dessert2a2.txt
    ./story/dessert2b.txt
    ./story/dessert3a1.txt
    ./story/dessert3a2.txt
    ./story/dessert3a3.txt
    ./story/dessert3b.txt
    ./story/dessert3c.txt
    ./story/dessert3d.txt
    ./story/dessert4a.txt
    ./story/dessert4b.txt
    ./story/dessert4c.txt
    ./story/dessert4d.txt
    ./story/dessert4e.txt
    ./story/dessert5a.txt
    ./story/dessert5b.txt
    ./story/glacies1.txt
    ./story/glacies2.txt
    ./story/glacies3a.txt
    ./story/glacies3b.txt
    ./story/glacies3c.txt
    ./story/glacies3d.txt
    ./story/glacies4a.txt
    ./story/glacies4b.txt
    ./story/glacies4c.txt
    ./story/glacies4d.txt
    ./story/glacies4e.txt
    ./story/glacies4f.txt
    ./story/glacies5a.txt
    ./story/glacies5b.txt
    ./story/nosoria1.txt
    ./story/nosoria2b1.txt
    ./story/nosoria2b2.txt
    ./story/nosoria2b3.txt
    ./story/nosoria3a.txt
    ./story/nosoria3b.txt
    ./story/planthea1b.txt
    ./story/planthea1b1.txt
    ./story/planthea1b2.txt
    ./story/planthea1b3.txt
    ./story/planthea1b4.txt
    ./story/planthea2a1.txt
    ./story/planthea2a2.txt
    ./story/planthea2a3.txt
    ./story/planthea2b1.txt
    ./story/planthea2b2.txt
    ./story/planthea3a1.txt
    ./story/planthea3a2.txt
    ./story/planthea3a3.txt
    ./story/planthea3a4.txt
    ./story/planthea3b1.txt
    ./story/planthea3b2.txt
    ./story/planthea3b3.txt
    ./story/planthea3b4.txt
    ./story/planthea3b5.txt
    ./story/planthea3b6.txt
    ./story/prologus.txt
    ./story/segitseg.txt
)

LIST(APPEND CMAKE_PROGRAM_PATH 
    ./include
    ./include/sdl
    ./src
    ./story
    ./res
    ./res/gfx
    ./../include
    ./../include/sdl
    ./../src
    ./../story
    ./../res
    ./../res/gfx
)


add_executable(${THIS} ./src/main.cpp ${SOURCES} ${HEADERS} ${LIBRARIES})
#add_executable(${THIS} ${SOURCES} ${HEADERS} ${LIBRARIES})
target_include_directories(${THIS} PUBLIC
    ./include
    ./include/sdl
    ./src
    ./story
    ${CMAKE_CURRENT_SOURCE_DIR}/story
    ./res
    ./res/gfx
    ./res/gfx/Animations
    ./res/gfx/Characters
    ./res/gfx/Dessert_Map1
    ./res/gfx/Dessert_Map2
    ./res/gfx/Menu
    ./res/gfx/Objects
    ./res/gfx/Animations
    ./res/gfx/Animations/Dessert_bolygo
    ./res/gfx/Animations/Glacies_bolygo
    ./res/gfx/Animations/Keszitok
    ./res/gfx/Animations/LyRs
    ./res/gfx/Animations/Nosoria_bolygo
    ./res/gfx/Animations/Planthea_bolygo
    ./res/gfx/Characters
    ./res/gfx/Dessert Map2
    ./res/gfx/Dessert_Map1
    ./res/gfx/Dessert_Map2
    ./res/gfx/Glacies_map
    ./res/gfx/Menu
    ./res/gfx/Nosoria_map
    ./res/gfx/Objects
    ./res/gfx/Planthea_map 
    
    )
include_directories(${THIS} PUBLIC
    ./include
    ./include/sdl
    ./src
    ./story
    ./res/gfx
    ./res/gfx/Animations
    ./res/gfx/Characters
    ./res/gfx/Dessert_Map1
    ./res/gfx/Dessert_Map2
    ./res/gfx/Menu
    ./res/gfx/Objects
    ./res/gfx/Animations
    ./res/gfx/Animations/Dessert_bolygo
    ./res/gfx/Animations/Glacies_bolygo
    ./res/gfx/Animations/Keszitok
    ./res/gfx/Animations/LyRs
    ./res/gfx/Animations/Nosoria_bolygo
    ./res/gfx/Animations/Planthea_bolygo
    ./res/gfx/Characters
    ./res/gfx/Dessert Map2
    ./res/gfx/Dessert_Map1
    ./res/gfx/Dessert_Map2
    ./res/gfx/Glacies_map
    ./res/gfx/Menu
    ./res/gfx/Nosoria_map
    ./res/gfx/Objects
    ./res/gfx/Planthea_map 
)
 target_link_libraries(${THIS}
        #${CMAKE_SOURCE_DIR}/lib/libSDL2_image.a
        #${CMAKE_SOURCE_DIR}/lib/libSDL2_ttf.a
        #${CMAKE_SOURCE_DIR}/lib/libSDL2.a
        #${CMAKE_SOURCE_DIR}/lib/libSDL2main.a
        ${CMAKE_SOURCE_DIR}/lib/libSDL2_image.dll.a
        ${CMAKE_SOURCE_DIR}/lib/libSDL2_ttf.dll.a
        ${CMAKE_SOURCE_DIR}/bin/SDL2_ttf.dll
        ${CMAKE_SOURCE_DIR}/SDL2_ttf.dll
        ${CMAKE_SOURCE_DIR}/lib/libSDL2.dll.a

       )
set(SDL2_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/include")

#Support both 32 and 64 bit builds
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
                # path suffixes to search inside ENV{SDL2DIR}
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

# Hide this cache variable from the user, it's an internal implementation
# detail. The documented library variable for the user is SDL2_LIBRARY
# which is derived from SDL2_LIBRARY_TEMP further below.
set_property(CACHE SDL2_LIBRARY_TEMP PROPERTY TYPE INTERNAL)

if(NOT SDL2_BUILDING_LIBRARY)
  if(NOT SDL2_INCLUDE_DIR MATCHES ".framework")
    # Non-OS X framework versions expect you to also dynamically link to
    # SDLmain. This is mainly for Windows and OS X. Other (Unix) platforms
    # seem to provide SDLmain for compatibility even though they don't
    # necessarily need it.
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

# SDL may require threads on your system.
# The Apple build may not need an explicit flag because one of the
# frameworks may already provide it.
# But for non-OSX systems, I will use the CMake Threads package.
if(NOT APPLE)
  find_package(Threads)
endif()

# MinGW needs an additional link flag, -mwindows
# It's total link flags should look like -lmingw32 -lSDLmain -lSDL -mwindows
if(MINGW)
  set(MINGW32_LIBRARY mingw32 "-mwindows" CACHE STRING "link flags for MinGW")
endif()

if(SDL2_LIBRARY_TEMP)
  # For SDLmain
  if(SDL2MAIN_LIBRARY AND NOT SDL2_BUILDING_LIBRARY)
    list(FIND SDL2_LIBRARY_TEMP "${SDLMAIN_LIBRARY}" _SDL2_MAIN_INDEX)
    if(_SDL2_MAIN_INDEX EQUAL -1)
      set(SDL2_LIBRARY_TEMP "${SDLMAIN_LIBRARY}" ${SDL2_LIBRARY_TEMP})
    endif()
    unset(_SDL2_MAIN_INDEX)
  endif()

  # For OS X, SDL uses Cocoa as a backend so it must link to Cocoa.
  # CMake doesn't display the -framework Cocoa string in the UI even
  # though it actually is there if I modify a pre-used variable.
  # I think it has something to do with the CACHE STRING.
  # So I use a temporary variable until the end so I can set the
  # "real" variable in one-shot.
  if(APPLE)
    set(SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} "-framework Cocoa")
  endif()

  # For threads, as mentioned Apple doesn't need this.
  # In fact, there seems to be a problem if I used the Threads package
  # and try using this line, so I'm just skipping it entirely for OS X.
  if(NOT APPLE)
    set(SDL2_LIBRARY_TEMP ${SDL2_LIBRARY_TEMP} ${CMAKE_THREAD_LIBS_INIT})
  endif()

  # For MinGW library
  if(MINGW)
    set(SDL2_LIBRARY_TEMP ${MINGW32_LIBRARY} ${SDL2_LIBRARY_TEMP})
  endif()

  # Set the final string here so the GUI reflects the final state.
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
                # path suffixes to search inside ENV{SDL2DIR}
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

# for backward compatibility
set(SDL2IMAGE_LIBRARY ${SDL2_IMAGE_LIBRARIES})
set(SDL2IMAGE_INCLUDE_DIR ${SDL2_IMAGE_INCLUDE_DIRS})
set(SDL2IMAGE_FOUND ${SDL2_IMAGE_FOUND})

mark_as_advanced(SDL2_IMAGE_LIBRARY SDL2_IMAGE_INCLUDE_DIR)

# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#  Copyright 2019 Amine Ben Hassouna <amine.benhassouna@gmail.com>
#  Copyright 2000-2019 Kitware, Inc. and Contributors
#  All rights reserved.

#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:

#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.

#  * Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.

#  * Neither the name of Kitware, Inc. nor the names of Contributors
#    may be used to endorse or promote products derived from this
#    software without specific prior written permission.

#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
#  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
#  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
#  HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
#  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
#  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
#  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
#  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
#  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
#  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#[=======================================================================[.rst:
FindSDL2_ttf
------------

Locate SDL2_ttf library

This module defines the following 'IMPORTED' target:

::

  SDL2::TTF
    The SDL2_ttf library, if found.
    Have SDL2::Core as a link dependency.



This module will set the following variables in your project:

::

  SDL2_TTF_LIBRARIES, the name of the library to link against
  SDL2_TTF_INCLUDE_DIRS, where to find the headers
  SDL2_TTF_FOUND, if false, do not try to link against
  SDL2_TTF_VERSION_STRING - human-readable string containing the
                            version of SDL2_ttf



This module responds to the following cache variables:

::

  SDL2_TTF_PATH
    Set a custom SDL2_ttf Library path (default: empty)

  SDL2_TTF_NO_DEFAULT_PATH
    Disable search SDL2_ttf Library in default path.
      If SDL2_TTF_PATH (default: ON)
      Else (default: OFF)

  SDL2_TTF_INCLUDE_DIR
    SDL2_ttf headers path.

  SDL2_TTF_LIBRARY
    SDL2_ttf Library (.dll, .so, .a, etc) path.


Additional Note: If you see an empty SDL2_TTF_LIBRARY in your project
configuration, it means CMake did not find your SDL2_ttf library
(SDL2_ttf.dll, libsdl2_ttf.so, etc). Set SDL2_TTF_LIBRARY to point
to your SDL2_ttf library, and  configure again. This value is used to
generate the final SDL2_TTF_LIBRARIES variable and the SDL2::TTF target,
but when this value is unset, SDL2_TTF_LIBRARIES and SDL2::TTF does not
get created.


$SDL2TTFDIR is an environment variable that would correspond to the
./configure --prefix=$SDL2TTFDIR used in building SDL2_ttf.

$SDL2DIR is an environment variable that would correspond to the
./configure --prefix=$SDL2DIR used in building SDL2.



Created by Amine Ben Hassouna:
  Adapt FindSDL_ttf.cmake to SDL2_ttf (FindSDL2_ttf.cmake).
  Add cache variables for more flexibility:
    SDL2_TTF_PATH, SDL2_TTF_NO_DEFAULT_PATH (for details, see doc above).
  Add SDL2 as a required dependency.
  Modernize the FindSDL2_ttf.cmake module by creating a specific target:
    SDL2::TTF (for details, see doc above).

Original FindSDL_ttf.cmake module:
  Created by Eric Wing.  This was influenced by the FindSDL.cmake
  module, but with modifications to recognize OS X frameworks and
  additional Unix paths (FreeBSD, etc).
#]=======================================================================]

# SDL2 Library required
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


# Define options for searching SDL2_ttf Library in a custom path

set(SDL2_TTF_PATH "./lib" CACHE STRING "Custom SDL2_ttf Library path")

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

# Search for the SDL2_ttf include directory
find_path(SDL2_TTF_INCLUDE_DIR SDL_ttf.h
  HINTS
    ENV SDL2TTFDIR
    ENV SDL2DIR
    ${SDL2_TTF_NO_DEFAULT_PATH_CMD}
  PATH_SUFFIXES SDL2
                # path suffixes to search inside ENV{SDL2DIR}
                # and ENV{SDL2TTFDIR}
                include/SDL2 include
  PATHS ${SDL2_TTF_PATH}
  DOC "Where the SDL2_ttf headers can be found"
)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
  set(VC_LIB_PATH_SUFFIX lib/x64)
else()
  set(VC_LIB_PATH_SUFFIX lib/x86)
endif()

# Search for the SDL2_ttf library
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

# Read SDL2_ttf version
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
#set(SDL2_TTF_INCLUDE_DIRS ./lib/SDL_ttf.dll)
include(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_ttf
                                  REQUIRED_VARS SDL2_TTF_LIBRARIES SDL2_TTF_INCLUDE_DIRS
                                  VERSION_VAR SDL2_TTF_VERSION_STRING)


mark_as_advanced(SDL2_TTF_PATH
                 SDL2_TTF_NO_DEFAULT_PATH
                 SDL2_TTF_LIBRARY
                 SDL2_TTF_INCLUDE_DIR)


if(SDL2_TTF_FOUND)

  # SDL2::TTF target
  if(SDL2_TTF_LIBRARY AND NOT TARGET SDL2::TTF)
    add_library(SDL2::TTF UNKNOWN IMPORTED)
    set_target_properties(SDL2::TTF PROPERTIES
                          IMPORTED_LOCATION "${SDL2_TTF_LIBRARY}"
                          INTERFACE_INCLUDE_DIRECTORIES "${SDL2_TTF_INCLUDE_DIR}"
                          INTERFACE_LINK_LIBRARIES SDL2::Core)
                          
  endif()
endif()

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
    set(sdl2_ttf_config_path "${CMAKE_CURRENT_LIST_DIR}/../i686-w64-mingw32/lib/cmake/SDL2_ttf/sdl2_ttf-config-version.cmake")
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(sdl2_ttf_config_path "${CMAKE_CURRENT_LIST_DIR}/../x86_64-w64-mingw32/lib/cmake/SDL2_ttf/sdl2_ttf-config-version.cmake")
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