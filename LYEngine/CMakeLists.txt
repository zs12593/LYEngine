
cmake_minimum_required(VERSION 3.4.1)

project( LYEngine )

set (engine_src android/native_main.cpp

                base/Game.cpp
                base/Camera.cpp

                base/event/Event.cpp
                base/event/EventDispatcher.cpp
                base/event/EventListener.cpp
                base/event/EventManager.cpp

                base/log/Log.cpp

                base/node/Node.cpp
                base/node/InputEventNode.cpp
                base/node/Scene.cpp
                base/node/Sprite.cpp

                base/renderer/Renderer.cpp
                base/renderer/RendererCommand.cpp

                base/texture/Texture.cpp
                base/texture/TextureManager.cpp

                )

add_library( LYEngine STATIC ${engine_src} )

find_library( log-lib log )

target_link_libraries( LYEngine ${log-lib} )