#ifndef MEME_LIGHT_HPP
#define MEME_LIGHT_HPP

#include"animatron.hpp"
#include"../event system/subject.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Light : public Animatron, public Observer
{
public:
    Light(int value, std::initializer_list<int> move_path_, Cameras &camera_system, Office *office, int tic_duration_milisec): Animatron{value,move_path_,camera_system,office,tic_duration_milisec}
    {};
    void Move() override;
    void Under_door();
    void On_notify ( const Event event, const Direction direction ) override;

    Subject subject{};
private:
    bool right_door_open{true};
    bool is_under_door{false};
};

}

#endif // MEME_LIGHT_H
