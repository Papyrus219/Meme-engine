#ifndef MEME_SCENES_HPP
#define MEME_SCENES_HPP

#include <string>

namespace meme
{
    enum class Scene
    {
        none = 0,
        office = 1,
        cameras = 2,
        menu = 3,
    };

    std::string Get_string_for_scene(Scene scene);
}

#endif
