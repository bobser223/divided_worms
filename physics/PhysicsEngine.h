//
// Created by Volodymyr Avvakumov on 05.07.2025.
//

#include <vector>

#include "../structures/Coordinate.h"
#include "../structures/Vec2.h"
#include "../map/map.h"

#ifndef DIVIDED_WORMS_PHYSICS_ENGINE_H
#define DIVIDED_WORMS_PHYSICS_ENGINE_H

#endif //DIVIDED_WORMS_PHYSICS_ENGINE_H

using wind_t = long long;
using exit_code_t = short;
using gravity_t = double;
using time_step_t = double;


class PhysicsEngine{
private:
    wind_t wind_;

public:
    explicit PhysicsEngine(wind_t _wind=0): wind_(_wind) {}

    ~PhysicsEngine() = default;


    exit_code_t set_wind(wind_t value){

        wind_ = value;
        return 0; //good
    }


    [[nodiscard]] wind_t get_wind() const{
        return wind_;
    }

    /// Compute the projectile’s trajectory under gravity + wind.
    /// @param start         Initial position (world coords).
    /// @param initVelocity  Initial velocity vector (units/sec).
    /// @param gravity       Downward acceleration (units/sec²). Default ≈ Earth.
    /// @param timeStep      Simulation delta‐time (sec). Defaults to 0.02s (~50Hz).
    /// @param maxSteps      Hard cap on number of samples to avoid infinite loops.
    /// @returns             Sequence of positions until it hits y≤0 or maxSteps.
    std::vector<Coordinate> count_ballistics(
            const Coordinate& start,
            const Coordinate& initVelocity,
            gravity_t gravity = 9.81,
            time_step_t timeStep = 0.02,
            size_t maxSteps  = 500
            ) const;

};