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
    Cameras(int cameras_amount);

    void Move_in_camera(int camera_id, Animatron anim);
    void Move_out_camera(int camera_id, Animatron anim);
private:
    std::vector<int> cameras_value{};

};

}

#endif // MEME_CAMERAS_HPP
