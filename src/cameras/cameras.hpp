#ifndef MEME_CAMERAS_H
#define MEME_CAMERAS_H

#include"../system/scene.hpp"
#include"camera.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Cameras: public Scene
{
public:
    std::vector<Camera> cameras_vector{};
private:
    int actual_possition;
};

}

#endif // MEME_CAMERAS_H
