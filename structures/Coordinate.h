//
// Created by Volodymyr Avvakumov on 05.07.2025.
//

#ifndef DIVIDED_WORMS_COORDINATE_H
#define DIVIDED_WORMS_COORDINATE_H

using coordinate_value_t = long long;

class Coordinate {
private:
    coordinate_value_t  x, y;
public:
    Coordinate(coordinate_value_t _x, coordinate_value_t _y): x(_x), y(_y) {};

    void operator=(Coordinate& other){
        this->x = other.x;
        this->y = other.y;
    }

    ~Coordinate() = default;

    bool operator==(Coordinate& other) const {
        return this->x == other.x && this->y == other.y;
    }



};


#endif //DIVIDED_WORMS_COORDINATE_H
