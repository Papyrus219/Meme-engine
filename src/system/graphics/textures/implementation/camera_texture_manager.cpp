#include "camera_texture_manager.hpp"
#include "../../../../exceptions/meme_exception.hpp"

using namespace meme;

void meme::Camera_texture_manager::Setup_textures(std::string tex_path, sf::Vector2i camera_size, std::vector<std::vector<int>> &cameras_values)
{
    if(!cameras_texture.loadFromFile(tex_path))
    {
        throw Texture_exception{ "Invalide cameras texture path." };
    }

    const int cameras_amount = assigned_cameras->Get_cameras_amount();
    if(cameras_amount != cameras_values.size())
    {
        throw Texture_exception{ "Amount of cameras values: " + std::to_string(cameras_values.size()) + " in cameras texure manager don't match amount of cameras: " + std::to_string(cameras_amount) + "." };
    }

    cameras_tex_rects.resize(cameras_amount,std::map<int,sf::IntRect>{});

    sf::Vector2i possition{};
    for(int i=0;i<cameras_amount;i++)
    {
        for(int j=0;j<cameras_values[i].size();j++)
        {
            cameras_tex_rects[i][ cameras_values[i][j] ] = {possition,camera_size};

            possition.x += camera_size.x;
        }

        possition.x = 0;
        possition.y += camera_size.y;
    }
}

void meme::Camera_texture_manager::Set_texture_to_sprite(sf::Sprite& sprite)
{
    const int actual_camera = assigned_cameras->Get_current_camera_id();
    const int actual_camera_value = assigned_cameras->Get_current_camera_value();

    sf::IntRect tex_rect{};

    try
    {
        tex_rect = cameras_tex_rects[actual_camera].at(actual_camera_value);
    }
    catch(std::out_of_range)
    {
        throw Texture_exception{"Invalid wanted value: " + std::to_string(actual_camera_value) + " from cameras texture manager."};
    }

    sprite.setTexture(cameras_texture);
    sprite.setTextureRect(tex_rect);
}
