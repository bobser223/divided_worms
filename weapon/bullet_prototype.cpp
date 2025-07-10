//
// Created by bylin on 07.07.2025.
//
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>


using namespace std; // TODO: remove this and use manual namespaces like std::something

vector<string> weapons{"rocket_launcher", "shotgun", "uzi"};


class Bullet(vector<pair> trajectory) // TODO: make this class virtual and all the methods also;
private:
    string type;
    int damage; // TODO: make something like using damage_t = int;
    string shape;
    int recoil;
    int position;
    float time;

public:
    int current_status;

    void setTrajectory(vector<pair> trajectory);

    void change_position(){
        const auto delay = chrono::milliseconds(time);
        current_status = 2;
        for (int i = 0; i < trajectory.size(); ++i) {

            this_thread::sleep_for(delay);
            position = i;
        }
        current_status = 3;
    }

    void visual_change_position(){}



