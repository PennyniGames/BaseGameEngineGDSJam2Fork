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
        EActorType.h)
