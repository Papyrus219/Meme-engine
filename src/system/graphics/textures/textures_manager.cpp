#include "textures_manager.hpp"
#include "../../../exceptions/meme_exception.hpp"

using namespace meme;

void meme::Textures_manager::Init_background_manager()
{
    background_manager.emplace();
}

void meme::Textures_manager::Init_cameras_manager(std::shared_ptr<Cameras> cameras)
{
    cameras_manager.emplace(cameras);
}

void meme::Textures_manager::Setup_background_textures(std::string tex_path, int backgrounds_amount, sf::Vector2i background_size, std::vector<Scene> scenes)
{
    if(!background_manager)
    {
        throw Texture_exception{"Backgrounds texture manager is not init."};
    }

    background_manager->Setup_textures(tex_path,backgrounds_amount,background_size,scenes);
}

void meme::Textures_manager::Setup_cameras_textures(std::string tex_path, sf::Vector2i camera_size, std::vector<std::vector<int>> &cameras_values)
{
    if(!cameras_manager)
    {
        throw Texture_exception{ "Cameras texture manager is not init." };
    }

    cameras_manager->Setup_textures(tex_path,camera_size,cameras_values);
}

void meme::Textures_manager::Set_background_texture_to_sprite(sf::Sprite& sprite, Scene scene_to_set)
{
    if(!background_manager)
    {
        throw Texture_exception{"Backgrounds texture manager is not init."};
    }

    background_manager->Set_texture_to_sprite(sprite,scene_to_set);
}

void meme::Textures_manager::Set_camera_texture_to_sprite(sf::Sprite& sprite)
{
    if(!cameras_manager)
    {
        throw Texture_exception{ "Cameras texture manager is not init." };
    }

    cameras_manager->Set_texture_to_sprite(sprite);
}
