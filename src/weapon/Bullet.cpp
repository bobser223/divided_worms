
#include "../../include/weapon/Bullet.h"

void Bullet::change_position()
{
    const auto delay = std::chrono::milliseconds(time);

    for (int i = 0; i < trajectory.size(); ++i) {

        std::this_thread::sleep_for(delay);
        current_position = trajectory[i];
        if(danger_checker())
        {
            notifier();
            // TODO: we have no worm yet
        }
    }

}

exit_code_t Bullet::explode(const Coordinate& hit_point) {
    if (hit_point.x < 0 || hit_point.x >= MAP_WIDTH || hit_point.y < 0 || hit_point.y >= MAP_HEIGHT)
        return OUT_OF_RANGE_ERROR;



    //                   coordinate, damage impuls
    std::queue<std::pair<Coordinate, int>> q;
    q.push({hit_point, recoil});


    std::vector<std::vector<bool>> visited(MAP_HEIGHT,
                                           std::vector<bool>(MAP_WIDTH, false));
    visited[hit_point.y][hit_point.x] = true;


    while(!q.empty()){
        auto [curr_coord, curr_damage] = q.front(); q.pop();
        if (curr_damage <= 0) continue;

        auto [x, y] = curr_coord;

        if (durabilityMap[y][x] > 0){
            auto new_curr_damage = curr_damage - durabilityMap[y][x];

            durabilityMap[y][x] -= curr_damage;

            if (durabilityMap[y][x] <= 0){
                destroy_map_cell({x, y});
                curr_damage = new_curr_damage;
            } else { // new_curr_damage >= 0, so no more damage
                continue;
            }


        }

        
        for (size_t iter = 0; iter < DIRECTIONS_SIZE; iter++){
            auto [i, j] = DIRECTIONS[iter];
            auto xi = x+i, yj = y+j;

            if(xi <  0 || xi >= MAP_WIDTH || yj < 0 || yj >= MAP_HEIGHT) continue;

            if (count_distance(hit_point, {xi, yj}) >= recoil) continue;

            if (visited[yj][xi]) continue;

            q.push({{xi, yj}, curr_damage});
            visited[yj][xi] = true;


        }
    }
    
    return OK;
}
