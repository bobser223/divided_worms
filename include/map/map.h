//
// Created by Volodymyr Avvakumov on 06.07.2025.
//


#ifndef DIVIDED_WORMS_MAP_H
#define DIVIDED_WORMS_MAP_H


#pragma once

#include <iostream>

using map_value_t = int;

const size_t MAP_HEIGHT = 10;
const size_t MAP_WIDTH  = 20;

// 0 = порожнє (повітря), 1 = земля
extern map_value_t gameMap[MAP_HEIGHT][MAP_WIDTH];




#endif //DIVIDED_WORMS_MAP_H
