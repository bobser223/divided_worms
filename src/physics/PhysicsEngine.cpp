


#include "../../include/physics/PhysicsEngine.h"




std::vector<Coordinate>
PhysicsEngine::count_ballistics(
        const Coordinate &start,
        const Coordinate &initVelocity,
        gravity_t gravity,
        time_step_t timeStep,
        size_t maxSteps) const {

    std::vector<Coordinate> path;
    path.reserve(maxSteps+1);

    Vec2 pos = { static_cast<Vec2_value_t>(start.x), static_cast<Vec2_value_t>(start.y) };
    Vec2 vel = { static_cast<Vec2_value_t>(initVelocity.x), static_cast<Vec2_value_t>(initVelocity.y) };
    Vec2 accel = { double(wind_), -gravity };

    for (size_t i = 0; i < maxSteps; ++i) {
        path.emplace_back( static_cast<coordinate_value_t>(pos.x), static_cast<coordinate_value_t>(pos.y) );

        // Euler integration
        vel.x += accel.x * timeStep;
        vel.y += accel.y * timeStep;
        pos.x += vel.x * timeStep;
        pos.y += vel.y * timeStep;

        if (gameMap[static_cast<map_value_t>(pos.y)][static_cast<map_value_t>(pos.x)] == 1) // hit ground
            break;




        if (pos.y <= 0.0)  // hit ground
            break;
    }

    return path;
}
