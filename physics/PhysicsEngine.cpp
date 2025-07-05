


#include "PhysicsEngine.h"


std::vector<Coordinate> count_balistics(
        Coordinate& start,
        Coordinate& initVelocity,
        gravity_t gravity = 9.81,
        time_step_t timeStep = 0.02,
        size_t maxSteps  = 500
){

}

std::vector<Coordinate>
PhysicsEngine::count_ballistics(Coordinate &start, Coordinate &initVelocity, gravity_t gravity, time_step_t timeStep,
                               size_t maxSteps) {
    std::vector<Coordinate> path;
    path.reserve(maxSteps+1);

    Vec2 pos = { start.x, start.y };
    Vec2 vel = { initVelocity.x, initVelocity.y };
    Vec2 accel = { double(wind_), -gravity };

    for (size_t i = 0; i < maxSteps; ++i) {
        path.push_back({ pos.x, pos.y });

        // Euler integration
        vel.x += accel.x * timeStep;
        vel.y += accel.y * timeStep;
        pos.x += vel.x * timeStep;
        pos.y += vel.y * timeStep;

        if (pos.y <= 0.0)  // hit ground
            break;
    }

    return path;
}
