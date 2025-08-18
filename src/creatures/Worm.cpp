//
// Created by Volodymyr Avvakumov on 10.07.2025.
//

#include "../../include/creatures/Worm.h"

id_t Worm::_next_id = 0;

Worm::Worm(Coordinate position, hp_t hp, id_t id)
    : _position(position), _hp(hp), _id(id) {}
