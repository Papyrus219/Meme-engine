#ifndef PAPYRUS_H
#define PAPYRUS_H

#include "animatron.hpp"
#include "../event system/subject.hpp"
#include<iostream>

namespace meme
{

class Papyrus: public Animatron, public Observer
{
public:
    Papyrus(int value, std::vector<int> move_path_, Cameras &camera_system, Office *office, int tic_duration_milisec): Animatron{value,move_path_,camera_system,office,tic_duration_milisec}
    {};
    void Under_door () override;
    void On_notify ( const Event event, const Direction direction ) override;

    Subject subject;
private:
    bool left_door_open{true};
    int chill{};
    int rage{};
};

}


#endif
