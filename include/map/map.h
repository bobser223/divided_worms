//
// Created by Volodymyr Avvakumov on 06.07.2025.
//


#ifndef DIVIDED_WORMS_MAP_H
#define DIVIDED_WORMS_MAP_H


#pragma once

#include <iostream>

#include "../../include/structures/Coordinate.h"

#define AIR 0

using map_value_t = int;
using map_durability_t = long long;

extern const size_t MAP_HEIGHT = 10;
extern const size_t MAP_WIDTH  = 20;

// 0 = порожнє (повітря), 1 = земля
extern map_value_t gameMap[MAP_HEIGHT][MAP_WIDTH];
extern map_durability_t durabilityMap[MAP_HEIGHT][MAP_WIDTH];

void destroy_map_cell(const Coordinate& position);




#endif //DIVIDED_WORMS_MAP_H
