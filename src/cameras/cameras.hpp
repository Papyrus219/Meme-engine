#ifndef MEME_CAMERAS_HPP
#define MEME_CAMERAS_HPP

#include <vector>

namespace meme {

class Animatron;

/**
 * @todo write docs
 */
class Cameras
{
public:
    Cameras(int cameras_amount) noexcept;

    void Change_current_camera(int camera_id);

    void Move_in_camera(int camera_id, Animatron anim);
    void Move_out_camera(int camera_id, Animatron anim);

    int Get_cameras_amount() noexcept {return cameras_amount;};
    int Get_current_camera_id() noexcept {return current_camera;};
    int Get_current_camera_value() noexcept {return cameras_value[current_camera];};
private:
    std::vector<int> cameras_value{};
    int cameras_amount{};
    int current_camera{};
};

}

#endif // MEME_CAMERAS_HPP
