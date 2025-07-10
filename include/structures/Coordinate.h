//
// Created by Volodymyr Avvakumov on 05.07.2025.
//

#ifndef DIVIDED_WORMS_COORDINATE_H
#define DIVIDED_WORMS_COORDINATE_H

using coordinate_value_t = long long;

struct Coordinate {

    coordinate_value_t  x, y;

    Coordinate(coordinate_value_t _x, coordinate_value_t _y): x(_x), y(_y) {};

    void operator=(const Coordinate& other){
        this->x = other.x;
        this->y = other.y;
    }

    ~Coordinate() = default;

    bool operator==(Coordinate& other) const {
        return this->x == other.x && this->y == other.y;
    }



};


#endif //DIVIDED_WORMS_COORDINATE_H
