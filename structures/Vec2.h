//
// Created by Volodymyr Avvakumov on 05.07.2025.
//

#ifndef DIVIDED_WORMS_VEC2_H
#define DIVIDED_WORMS_VEC2_H


// Vec2.h
#pragma once

using Vec2_value_t = double;

struct Vec2 {
    Vec2_value_t x;
    Vec2_value_t y;

    Vec2()           : x(0.0), y(0.0) {}
    Vec2(Vec2_value_t _x, Vec2_value_t _y) : x(_x), y(_y) {}

    Vec2& operator+=(Vec2 const& o) { x += o.x; y += o.y; return *this; }
    Vec2  operator+(Vec2 const& o) const { return Vec2{x + o.x, y + o.y}; }
    Vec2  operator*(double s)      const { return Vec2{x * s, y * s}; }
};


#endif //DIVIDED_WORMS_VEC2_H
