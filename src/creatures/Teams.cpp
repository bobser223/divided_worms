//
// Created by Volodymyr Avvakumov on 28.07.2025.
//

#include "../../include/creatures/Teams.h"

void Teams::create_new_team(size_t members_count, std::vector<hp_t> &start_hp, std::array<size_t, 2> &amo_starter_pack) {
    _teams.emplace_back(members_count, start_hp, amo_starter_pack);
    _teams_ids.insert(_teams.back().get_id());
}
