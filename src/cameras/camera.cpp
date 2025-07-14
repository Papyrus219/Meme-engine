#include "camera.hpp"
#include "../exceptions.hpp"

#include<iostream>

using namespace meme;

int Camera::cameras_amount{};

int Camera::get_cameras_amount()
{
    return cameras_amount;
}

Camera::Camera(sf::Texture &texture_source, sf::IntRect texture_fragment ,sf::Vector2i size, std::vector<int> variants_val): texture_ptr{&texture_source}, size{size}
{
    this->camera_id = cameras_amount;
    cameras_amount++;

    for(int i=0;i<variants_val.size();i++)
    {
        std::cerr << "Adding " << variants_val[i] << " for " << camera_id << '\n';

        this->variants[variants_val[i]] = {{size.x*i,texture_fragment.position.y},{size.x,size.y}};
    }
    this->actual_variant = 0;
}

Camera::Camera(const Camera& orginal)
{
        this->camera_id = cameras_amount;
        cameras_amount++;

        for(auto const &[var_id,var_rect] : orginal.variants)
        {
            this->variants[var_id] = var_rect;
        }

        this->texture_ptr = orginal.texture_ptr;
        this->size = orginal.size;
        this->actual_variant = orginal.actual_variant;
}

Camera::Camera(Camera && orginal)
{
    this->camera_id = orginal.camera_id;
    cameras_amount++;

    for(auto const &[var_id,var_rect] : orginal.variants)
    {
        this->variants[var_id] = var_rect;
    }

    this->texture_ptr = orginal.texture_ptr;
    this->size = orginal.size;
    this->actual_variant = orginal.actual_variant;
}

sf::IntRect Camera::Get_camera()
{
    sf::IntRect result{};

    try
    {
        result = this->variants.at(actual_variant);
    }
    catch(const std::out_of_range& e)
    {
        throw Camera_Exeption{"Camera variant Imposible on camera. ",camera_id,actual_variant};
    }

    return result;
}

Camera::~Camera()
{
    cameras_amount--;
}
