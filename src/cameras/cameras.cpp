#include "cameras.hpp"
#include "../animatrons/animatron.hpp"
#include "../exceptions/meme_exception.hpp"

using namespace meme;

meme::Cameras::Cameras(int cameras_amount_) noexcept: cameras_amount{cameras_amount_}
{
    cameras_value.resize(0,cameras_amount_);
}

void meme::Cameras::Move_in_camera(int camera_id, Animatron anim)
{
    if(camera_id >= cameras_amount || camera_id < 0)
    {
        throw Camera_exception{ "Camera id: " + std::to_string(camera_id) + " is out of range." };
    }

    cameras_value[camera_id] += anim.Get_value();
}

void meme::Cameras::Move_out_camera(int camera_id, Animatron anim)
{
    if(camera_id >= cameras_amount || camera_id < 0)
    {
        throw Camera_exception{ "Camera id: " + std::to_string(camera_id) + " is out of range." };
    }

    cameras_value[camera_id] -= anim.Get_value();
}

void meme::Cameras::Change_current_camera(int camera_id)
{
    if(camera_id >= cameras_amount || camera_id < 0)
    {
        throw Camera_exception{ "Camera id: " + std::to_string(camera_id) + " is out of range." };
    }

    current_camera = camera_id;
}
