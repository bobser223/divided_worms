
#include "../../include/weapon/Weapon.h"
#include "weapon/Bullet.h"

void Weapon::rocket_launcher()
{
    Bullet rocket_launcher;
    rocket_launcher.set_damage(60);
    rocket_launcher.set_recoil(10);
    rocket_launcher.set_shape("standard_bullet");
    rocket_launcher.set_time(1);
    set_start();
}
