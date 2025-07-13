//
// Created by Volodymyr Avvakumov on 13.07.2025.
//

#include <cmath>

#include "../../include/structures/Coordinate.h"
#include "../../include/structures/Coordinate.h"
#include "../../config/Defines.h"



#ifndef DIVIDED_WORMS_DISTANCE_H
#define DIVIDED_WORMS_DISTANCE_H


distace_rational_t count_distance(const Coordinate& c1, const Coordinate& c2){
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y -c2.y, 2));
}

#endif //DIVIDED_WORMS_DISTANCE_H


