#include <iostream>

#include "include/physics/PhysicsEngine.h"
#include "include/map/map.h"

void drawMap() {
    for (const auto & y : gameMap) {
        for (int x : y) {
            switch (x) {
                case (0):
                    std::cout << ' ';
                    break;
                case (1):
                    std::cout << '#';
                    break;

                case(2):
                    std::cout << '*';
                    break;
            }
        }
        std::cout << '\n';
    }
}

int main() {
    PhysicsEngine pe;
//    drawMap();


    auto vec = pe.count_ballistics({19, 8}, {-10,1});

    for (auto &coord : vec) {
        std::cout << coord.x << " " << coord.y << "\n";
        gameMap[coord.y][coord.x] = 2;
    }

    drawMap();


    return 0;
}