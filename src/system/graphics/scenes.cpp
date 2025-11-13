#include "scenes.hpp"

namespace meme
{
    std::string Get_string_for_scene(Scene scene) noexcept
    {
        switch(scene)
        {
            case Scene::office:
                return "Office";
            case Scene::cameras:
                return "Cameras";
            case Scene::menu:
                return "Menu";
            default:
                return "";
        }
    }

}
