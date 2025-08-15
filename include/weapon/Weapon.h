
#ifndef DIVIDED_WORMS_WEAPON_H
#define DIVIDED_WORMS_WEAPON_H

#include "../../include/weapon/Bullet.h"

#include "../../include/physics/PhysicsEngine.h"


gravity_t gravity = 9.81;

class Weapon
{
private:
public:
    Weapon() = default;
    ~Weapon() = default;



    void rocket_launcher(Bullet& rocket_launcher);


};







#endif //DIVIDED_WORMS_WEAPON_H