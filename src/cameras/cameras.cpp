#include "cameras.hpp"
#include "../exceptions.hpp"
#include<iostream>

using namespace meme;

Cameras::Cameras(std::string tex_path, sf::Vector2i size, std::vector<std::vector<int>> cam_val)
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load cameras textures!"};
    }

    sprite.setTexture(texture,true);
    standart_size = size;

    actual_possition = 0;

    if(cam_val.size() > 1)
    {
        Cameras_setup(std::move(cam_val));
        sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
    }
}

Cameras::Cameras ( const Cameras& orginal )
{
    this->standart_size = orginal.standart_size;
    this->actual_possition = orginal.actual_possition;
    for(auto camera : orginal.cameras_vector)
        this->cameras_vector.push_back(camera);
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
}

Cameras::Cameras ( Cameras && orginal )
{
    this->standart_size = orginal.standart_size;
    this->actual_possition = orginal.actual_possition;
    for(auto camera : orginal.cameras_vector)
        this->cameras_vector.push_back(camera);
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
}

void Cameras::Render()
{
    sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
    assigned_window->draw(sprite);
}

void Cameras::Event()
{
    while (const std::optional event = assigned_window->pollEvent())
    {
        if(event->is<sf::Event::MouseButtonPressed>())
        {

        }
        else if(event->is<sf::Event::Closed>())
        {
            assigned_window->close();
            return;
        }
    }
}

void Cameras::Cameras_setup(std::vector<std::vector<int>> &&cam_val)
{
    for(int cam_set = 0;cam_set < cam_val.size(); cam_set++)
    {
        std::cerr << cam_val.size() << " huh\n";

        cameras_vector.push_back(Camera{texture, {{0,standart_size.y*cam_set},{standart_size.x*static_cast<int>(cam_val[cam_set].size()),standart_size.y}}, standart_size, cam_val[cam_set]});
    }

    sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
}

void Cameras::Cameras_setup(std::vector<std::vector<int>> &&cam_val, std::vector<sf::Vector2i> &&cam_sizes)
{
    if(cam_val.size() != cam_sizes.size()) throw Exeption{"Cam_values size don't match cam_sizes size."};

    sf::Vector2i current_possition{};

    for(int cam_set = 0;cam_set < cam_val.size(); cam_set++)
    {
        cameras_vector.push_back(Camera{texture, {{0,current_possition.y},{cam_sizes[cam_set].x*static_cast<int>(cam_val[cam_set].size()),cam_sizes[cam_set].y}}, cam_sizes[cam_set], cam_val[cam_set]});

        current_possition += cam_sizes[cam_set];
    }
}

