
cmake_minimum_required(VERSION 3.4.1)

project( LYGame )

add_subdirectory( ../LYEngine LYEngine )

set ( app_src src/main/cpp/Test.cpp )

add_library( LYGame SHARED ${app_src} )

target_link_libraries( LYGame
    "-Wl,--whole-archive"
    LYEngine
    "-Wl,--no-whole-archive" )
