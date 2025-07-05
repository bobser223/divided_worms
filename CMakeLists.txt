cmake_minimum_required(VERSION 3.31)
project(divided_worms)

set(CMAKE_CXX_STANDARD 23)

add_executable(divided_worms main.cpp
        physics/PhysicsEngine.h
        structures/Coordinate.cpp
        structures/Coordinate.h
        physics/PhysicsEngine.cpp
        structures/Vec2.cpp
        structures/Vec2.h
)
