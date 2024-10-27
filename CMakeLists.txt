cmake_minimum_required(VERSION 3.29)
project(IDJ_2024_2)

set(CMAKE_CXX_STANDARD 11)
set(SDL2_INCLUDE_DIR D:/Admin/Documents/SDL-2.30.8/include/SDL2)
set(SDL2_LIB_DIR D:/Admin/Documents/SDL-2.30.8/lib)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
link_libraries(Mingw32 SDL2main SDL2_image SDL2_mixer SDL2_ttf SDL2)

add_executable(IDJ_2024_2 src/main.cpp
        include/Game.h
        include/State.h
        include/Sprite.h
        include/Music.h
        src/Game.cpp
        src/State.cpp
        src/Sprite.cpp
        src/Music.cpp)
