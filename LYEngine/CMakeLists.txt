
cmake_minimum_required(VERSION 3.4.1)

project( LYEngine )

set (engine_src android/native_main.cpp

                base/LogicThread.cpp
                base/Game.cpp

                base/event/EventDispatcher.cpp

                base/log/Log.cpp

                )

add_library( LYEngine STATIC ${engine_src} )

find_library( log-lib log )

target_link_libraries( LYEngine ${log-lib} )