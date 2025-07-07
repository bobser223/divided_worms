//
// Created by bylin on 07.07.2025.
//
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

vector<string> weapons{"rocket_launcher", "shotgun", "uzi"};


class Bullet(vector<pair> trajectory)
private:
    string type;
    int damage;
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



