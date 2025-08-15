#ifndef TETSTER_H
#define TETSTER_H

#include "../../include/physics/PhysicsEngine.h"
#include <iostream>
#include <vector>
#include <cmath>

class Tetster {
public:

    explicit Tetster(PhysicsEngine& engine);


    bool run_all();

private:
    PhysicsEngine& engine_;


    bool test_basic_fall();
    bool test_horizontal_motion();
    bool test_timestep_influence();
};

#endif // TETSTER_H
