#include "cameras.hpp"
#include "../exceptions.hpp"

using namespace meme;

Cameras::Cameras(std::string tex_path, sf::Vector2i size, std::vector<std::vector<int>> cam_val)
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to lad cameras textures!"};
    }

    sprite.setTexture(texture,true);
    standart_size = size;

    if(cam_val.size() != 0)
    {
        Cameras_setup(cam_val);
        sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
    }
}

void Cameras::Cameras_setup(std::vector<std::vector<int>> cam_val)
{
    for(int cam_set = 0;cam_set < cam_val.size(); cam_set++)
    {
        cameras_vector.push_back(Camera{texture, {{0,standart_size.y*cam_set},{standart_size.x*static_cast<int>(cam_val[cam_set].size()),standart_size.y}}, standart_size, cam_val[cam_set]});
    }

    sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
}

void Cameras::Cameras_setup(std::vector<std::vector<int>> cam_val, std::vector<sf::Vector2i> cam_sizes)
{
    if(cam_val.size() != cam_sizes.size()) throw Exeption{"Cam_values size don't match cam_sizes size."};

    sf::Vector2i current_possition{};

    for(int cam_set = 0;cam_set < cam_val.size(); cam_set++)
    {
        cameras_vector.push_back(Camera{texture, {{0,current_possition.y},{cam_sizes[cam_set].x*static_cast<int>(cam_val[cam_set].size()),cam_sizes[cam_set].y}}, cam_sizes[cam_set], cam_val[cam_set]});

        current_possition += cam_sizes[cam_set];
    }
}
