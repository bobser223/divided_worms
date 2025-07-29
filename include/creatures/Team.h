//
// Created by Volodymyr Avvakumov on 28.07.2025.
//



#ifndef DIVIDED_WORMS_TEAM_H
#define DIVIDED_WORMS_TEAM_H

#include <vector>

#include "../../config/Defines.h"
#include "../../config/Settings.h"
#include "../../include/creatures/Worm.h"


class Team {
private:
    id_t _team_id;
    std::vector<id_t> _members_ids;
    std::vector<Worm> _members;
    std::array<size_t, WEAPON_TYPE_COUNT> _available_amo{};

    static id_t _next_id;
public:
//    Team();

    Team(size_t members_count, std::vector<hp_t>& start_hp, const std::array<size_t, WEAPON_TYPE_COUNT>& available_amo);

    ~Team() = default;

    id_t get_id();

    exit_code_t add_member(Worm& worm){
        _members.push_back(worm);
        _members_ids.push_back(worm.get_id());

        return OK;
    }





};


#endif //DIVIDED_WORMS_TEAM_H
