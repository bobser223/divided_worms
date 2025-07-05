//
// Created by Volodymyr Avvakumov on 05.07.2025.
//

#ifndef DIVIDED_WORMS_VEC2_H
#define DIVIDED_WORMS_VEC2_H


// Vec2.h
#pragma once

struct Vec2 {
    double x;
    double y;

    Vec2()           : x(0.0), y(0.0) {}
    Vec2(double _x, double _y) : x(_x), y(_y) {}

    Vec2& operator+=(Vec2 const& o) { x += o.x; y += o.y; return *this; }
    Vec2  operator+(Vec2 const& o) const { return Vec2{x + o.x, y + o.y}; }
    Vec2  operator*(double s)      const { return Vec2{x * s, y * s}; }
};


#endif //DIVIDED_WORMS_VEC2_H
