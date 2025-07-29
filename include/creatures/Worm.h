//
// Created by Volodymyr Avvakumov on 10.07.2025.
//

#include <vector>
#include <unordered_set>

#include "../../config/Defines.h"
#include "../../include/weapon/Weapon.h"




#ifndef DIVIDED_WORMS_WORM_H
#define DIVIDED_WORMS_WORM_H




class Worm {
private:

    hp_t _hp;
    id_t _id;
    // Static counter shared by all Worms:
    static id_t _next_id;
public:

    Worm();

    explicit Worm(hp_t hp = 100, id_t id = ++_next_id);

    ~Worm() = default;

    Worm operator = (const Worm& other) = delete;

    id_t get_id() const{
        return this->_id;
    }


};


#endif //DIVIDED_WORMS_WORM_H
