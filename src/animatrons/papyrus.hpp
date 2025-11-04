#ifndef PAPYRUS_H
#define PAPYRUS_H

#include <initializer_list>
#include "animatron.hpp"
#include "../event system/subject.hpp"


namespace meme
{

class Papyrus: public Animatron, public Observer
{
public:
    Papyrus(int value, std::initializer_list<int> move_path_, Cameras &camera_system, Office *office, int tic_duration_milisec): Animatron{value,move_path_,camera_system,office,tic_duration_milisec}
    {};
    void Move() override;
    void Under_door ();
    void On_notify ( const Event event, const Direction direction ) override;

    Subject subject;
private:
    bool left_door_open{true};
    bool is_under_door{false};
};

}


#endif
