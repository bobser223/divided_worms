//
// Created by Volodymyr Avvakumov on 10.07.2025.
//

#include "../../include/creatures/Worm.h"



id_t Worm::_next_id = 0;


Worm::Worm()
        : _hp(100),
          _id(++_next_id)
{
    // set some basic waepon

}

Worm::Worm(hp_t hp, id_t id):
    _hp(hp),
    _id(id)
{}
