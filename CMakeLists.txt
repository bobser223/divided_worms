cmake_minimum_required(VERSION 3.31)
project(divided_worms)

set(CMAKE_CXX_STANDARD 23)

add_executable(divided_worms main.cpp
        include/physics/PhysicsEngine.h
        src/structures/Coordinate.cpp
        include/structures/Coordinate.h
        src/physics/PhysicsEngine.cpp
        src/structures/Vec2.cpp
        include/structures/Vec2.h
        include/map/map.h
        src/map/map.cpp
        src/creature/Creature.cpp
        include/creature/creature.h
        src/creature/Creature.cpp
        include/creature/Creature.h
        include/weapon/bullet_prototype.h
        config/Defines.h
        config/Settings.h
        src/drop/Drop.cpp
        include/drop/Drop.h
)
