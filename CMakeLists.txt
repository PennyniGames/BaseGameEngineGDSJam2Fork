cmake_minimum_required(VERSION 3.31)
project(BaseGameEngine)

set(CMAKE_CXX_STANDARD 20)

include_directories(/home/penny/CLionProjects/BaseGameEngine/ExtraIncludes)
add_executable(BaseGameEngine
        GameWorld.cpp
        GameWorld.h
        Actor.cpp
        Actor.h
        Character.cpp
        Character.h
        TVector2D.h
        AnimatedSprite.cpp
        AnimatedSprite.h
        GlobalConstants.h
        GameJamWorld.cpp
        GameJamWorld.h
        SnakeGame.cpp
        SnakeGame.h
        MiniGamePlayers/SnakePlayer.cpp
        MiniGamePlayers/SnakePlayer.h
        EActorType.h
        main.cpp)

find_package(OpenGL REQUIRED)
find_package(PNG REQUIRED)
find_package(X11 REQUIRED)

target_link_libraries(BaseGameEngine
        PRIVATE
        ${OPENGL_LIBRARIES}
        ${PNG_LIBRARIES}
        ${X11_LIBRARIES})