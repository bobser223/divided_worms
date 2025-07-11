//
// Created by Volodymyr Avvakumov on 06.07.2025.
//

#include "../../include/map/map.h"


map_value_t gameMap[MAP_HEIGHT][MAP_WIDTH] = {
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

map_durability_t durabilityMap[MAP_HEIGHT][MAP_WIDTH] = {
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,9,9,9,9,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,9,9,9,9,9,9,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,9,9,9,9,9,9,9,9,0,0,0,0,0,0},
        {0,0,0,0,0,9,9,9,9,9,9,9,9,9,9,0,0,0,0,0},
        {0,0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0,0},
        {0,0,0,9,9,9,9,9,9,9,9,9,9,9,9,9,9,0,0,0},
        {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9}
};


