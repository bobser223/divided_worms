//
// Created by Volodymyr Avvakumov on 06.07.2025.
//


#ifndef DIVIDED_WORMS_MAP_H
#define DIVIDED_WORMS_MAP_H


#include <iostream>


const long long MAP_HEIGHT = 10;
const long long MAP_WIDTH  = 20;

// 0 = порожнє (повітря), 1 = земля
const int gameMap[MAP_HEIGHT][MAP_WIDTH] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void drawMap() {
    for (const auto & y : gameMap) {
        for (int x : y) {
            std::cout << (x ? '#' : ' ');
        }
        std::cout << '\n';
    }
}



#endif //DIVIDED_WORMS_MAP_H
