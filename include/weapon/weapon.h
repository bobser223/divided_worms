//
// Created by Volodymyr Avvakumov on 10.07.2025.
//

#ifndef DIVIDED_WORMS_BULLET_PROTOTYPE_H
#define DIVIDED_WORMS_BULLET_PROTOTYPE_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include <map>

#include "map.h"

float epsilon = 0.001;


using namespace std; // TODO: remove this and use manual namespaces like std::something

vector<string> weapons{"rocket_launcher", "shotgun", "uzi"};


class Bullet
{

    private:
    string type;
    int maximal_damage; // TODO: make something like using damage_t = int;
    string shape;
    int recoil;
    int time;
    float speed;

    public:
    vector<pair<float, float>> trajectory;
    pair<float, float> current_position;

    void set_type(string& type)
    {
        this->type = type;
    }

    void set_damage(int damage)
    {
        this->maximal_damage = damage;
    }

    void set_shape(string& shape)
    {
        this->shape = shape;
    }

    void set_recoil(int recoil)
    {
        this->recoil = recoil;
    }

    void set_time(int time)
    {
        this->time = time;
    }



    const std::string& get_type() const
    {
        return type;
    }

    int get_damage() const
    {
        return maximal_damage;
    }

    const std::string& get_shape() const
    {
        return shape;
    }

    int get_recoil() const
    {
        return recoil;
    }

    int get_time() const
    {
        return time;
    }

    void notifier()
    {
        // TODO: make observer
    }

    void change_position(){
        const auto delay = chrono::milliseconds(time);

        for (int i = 0; i < trajectory.size(); ++i) {

            this_thread::sleep_for(delay);
            current_position = trajectory[i];
            if(map_value_t gameMap[current_position
                ][1] )
            {
                notifier();
                // TODO: we have no worm yet
            }
        }

    }

    void visual_change_position(){}
};

#endif //DIVIDED_WORMS_BULLET_PROTOTYPE_H
