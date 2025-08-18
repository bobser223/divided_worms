//
// Created by Volodymyr Avvakumov on 28.07.2025.
//

#include "../../include/creatures/Teams.h"

void Teams::create_new_team(size_t members_count, std::vector<hp_t> &start_hp, std::array<size_t, WEAPON_TYPE_COUNT> &amo_starter_pack) {
    _teams.emplace_back(members_count, start_hp, amo_starter_pack);
    _teams_ids.insert(_teams.back().get_id());
}

exit_code_t Teams::add_amo_to_team(id_t team_id, id_t weapon_id, size_t amo_cnt) {
    if (weapon_id >= WEAPON_TYPE_COUNT)
        return OUT_OF_RANGE_ERROR;

    Team* curr_team = team_by_id(team_id);
    if (!curr_team)
        return NOT_FOUND_ERROR;


    return curr_team->fill_amo(weapon_id, amo_cnt);
}
