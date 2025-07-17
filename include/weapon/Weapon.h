
#ifndef DIVIDED_WORMS_WEAPON_H
#define DIVIDED_WORMS_WEAPON_H

#include "../../include/weapon/Bullet.h"

#include "../../include/physics/PhysicsEngine.h"


extern gravity_t gravity = 9.81;

class Weapon
{
private:
public:
    Weapon() = default;
    ~Weapon() = default;

    int wind; // from -4 to 4

    void set_start()
    {
        // TODO: using the location of the worm we will put the correct start
    }

    void theta()
    {
        // TODO: using the choice of the worm with what angle does he shoot
    }

    void speed()
    {
        // TODO: using the choice of the worm with what speed does he shoot
    }


    void rocket_launcher(Bullet& rocket_launcher);


};







#endif //DIVIDED_WORMS_WEAPON_H