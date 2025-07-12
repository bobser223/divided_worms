// Created by Volodymyr Avvakumov on 10.07.2025.

#ifndef DIVIDED_WORMS_BULLET_PROTOTYPE_H
#define DIVIDED_WORMS_BULLET_PROTOTYPE_H

#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

#include <map>

#include "../../include/map/map.h"

extern const float epsilon = 0.001f;



static std::vector<std::string> weapons{"rocket_launcher", "shotgun", "uzi"};

class Bullet
{

private:
    std::string type;
    static int maximal_damage; // TODO: make something like using damage_t = int;
    std::string shape;
    static int recoil;
    static int time;
    static float speed;

public:
    std::vector<std::pair<float, float>> trajectory;
    std::pair<float, float> current_position;

    void set_type(const std::string& type)
    {
        this->type = type;
    }

    void set_damage(int damage)
    {
        maximal_damage = damage;
    }

    void set_shape(const std::string& shape)
    {
        this->shape = shape;
    }

    void set_shape(std::string&& shape)
    {
        this->shape = std::move(shape);
    }

    void set_recoil(int recoil)
    {
        Bullet::recoil = recoil;
    }

    void set_time(int time)
    {
        Bullet::time = time;
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

    bool danger_checker()
    {
        // TODO: implement
        return false;
    }

    void change_position();

    void visual_change_position(){}
};

#endif //DIVIDED_WORMS_BULLET_PROTOTYPE_H
