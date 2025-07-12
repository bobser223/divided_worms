//
// Created by bylin on 07.07.2025.
//

#include "../../include/weapon/weapon.h"

#include "../../include/physics/PhysicsEngine.h"

gravity_t gravity = 9.81;

class Weapon
{
    private:
    public:
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


    void rocket_launcher()
    {

        Bullet rocket_launcher;
        rocket_launcher.set_damage(60);
        rocket_launcher.set_recoil(10);
        rocket_launcher.set_shape("standard_bullet");
        rocket_launcher.set_time(1);
        set_start();


    }


};