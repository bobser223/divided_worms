//
// Created by Volodymyr Avvakumov on 10.07.2025.
//

#ifndef DIVIDED_WORMS_DEFINES_H
#define DIVIDED_WORMS_DEFINES_H

// CREATURES

using hp_t = short;

#define DEFAULT_TEAM_MEMBERS_COUNT 5

// WEAPON
#define WEAPON_TYPE_COUNT 2
#define BASIC_AMO_COUNT_FOR_EACH_WEAPON 0
// ID
#ifndef _ID_T // id_t is already defined on aple silicon
using id_t = unsigned short;
#endif //_ID_T


// DISTANCE
using distace_rational_t = double;
using distance_t = size_t;

// LOGGER

#define LOGGER_ON

// EXIT CODES
using exit_code_t = short;

#define OK 0
#define BASIC_ERROR 1
#define OUT_OF_RANGE_ERROR 2
#define LOGIC_OVERFLOW 3
#define WRONG_INCOME 4


#endif //DIVIDED_WORMS_DEFINES_H
