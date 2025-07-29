//
// Created by Volodymyr Avvakumov on 28.07.2025.
//

#include "../../include/creatures/Team.h"

id_t Team::_next_id = 0;

//Team::Team(): _team_id(++_next_id) {
//    for (int i = 0; i < WEAPON_TYPE_COUNT;i++){
//        _available_amo[i] = 0;
//    }
//    _members_ids = {};
//    }

Team::Team(size_t members_count, std::vector<hp_t> &start_hp, const std::array<size_t, 2> &available_amo) {

    size_t i = 0;
    for (auto& hp_t :start_hp){
        i++;

        if (i > members_count) break;

        _members.emplace_back(hp_t);
        _members_ids.push_back(_members.back().get_id()); //TODO: delete this shit;
    }

    _available_amo = available_amo;

    _team_id = ++_next_id;
}

id_t Team::get_id() {
    return _team_id;
}


