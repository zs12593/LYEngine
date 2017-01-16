
cmake_minimum_required(VERSION 3.4.1)

project( LYGame )

include_directories( ../LYEngine )

add_subdirectory( ../LYEngine LYEngine )

set ( app_src src/main/cpp/main.cpp
              src/main/cpp/FirstScene.cpp
                )

add_library( LYGame SHARED ${app_src} )

target_link_libraries( LYGame
    "-Wl,--whole-archive"
    LYEngine
    "-Wl,--no-whole-archive" )
