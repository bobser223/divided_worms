#include <iostream>

#include "physics/PhysicsEngine.h"
#include "map/map.h"

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

    for (auto[x, y]:vec){
        std::println("{} {}", x, y);
        gameMap[y][x] = 2;
    }

    drawMap();


    return 0;
}