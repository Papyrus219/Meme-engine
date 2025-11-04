#include "cameras.hpp"
#include "../animatrons/animatron.hpp"

using namespace meme;

meme::Cameras::Cameras(int cameras_amount)
{
    cameras_value.resize(0,cameras_amount);
}

void meme::Cameras::Move_in_camera(int camera_id, Animatron anim)
{
    if(camera_id >= cameras_value.size() || camera_id < 0) return;

    cameras_value[camera_id] += anim.Get_value();
}

void meme::Cameras::Move_out_camera(int camera_id, Animatron anim)
{
    if(camera_id >= cameras_value.size() || camera_id < 0) return;

    cameras_value[camera_id] -= anim.Get_value();
}
