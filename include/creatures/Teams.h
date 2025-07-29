//
// Created by Volodymyr Avvakumov on 28.07.2025.
//



#ifndef DIVIDED_WORMS_TEAMS_H
#define DIVIDED_WORMS_TEAMS_H

#include <vector>
#include <unordered_set>

#include "../../config/Defines.h"
#include "../../include/weapon/Weapon.h"
#include "../../include/creatures/Team.h"

class Teams {
private:
    std::unordered_set<size_t> _teams_ids;
    std::vector<Team> _teams;
public:
    Teams() = default;
    ~Teams() = default;

    void create_new_team(){
        std::vector<hp_t> hp_tmp(DEFAULT_TEAM_MEMBERS_COUNT, 100);
        std::array<size_t, WEAPON_TYPE_COUNT> amo_tmp{};
        amo_tmp.fill(BASIC_AMO_COUNT_FOR_EACH_WEAPON);

        create_new_team(DEFAULT_TEAM_MEMBERS_COUNT, hp_tmp, amo_tmp);
    }

    void create_new_team(size_t members_count, std::vector<hp_t>& start_hp, std::array<size_t, WEAPON_TYPE_COUNT>& amo_starter_pack);

    exit_code_t add_worm_to_team(id_t team_id, Worm& worm){
        if (!_teams_ids.contains(team_id)){
            return WRONG_INCOME;
        }

        for(auto& team: _teams){
            if (team.get_id() == team_id){
                team.add_member(worm);
            }
        }

        return OK;
    }

};




#endif //DIVIDED_WORMS_TEAMS_H
