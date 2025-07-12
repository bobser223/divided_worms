
#include "Bullet.h"

void Bullet::change_position()
{
    const auto delay = chrono::milliseconds(time);

    for (int i = 0; i < trajectory.size(); ++i) {

        this_thread::sleep_for(delay);
        current_position = trajectory[i];
        if(danger_checker())
        {
            notifier();
            // TODO: we have no worm yet
        }
    }

}