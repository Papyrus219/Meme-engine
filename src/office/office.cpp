#include"office.hpp"
#include"../exceptions.hpp"
using namespace meme;

office::office(std::string tex_path, sf::Vector2i size): size{size}
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load office texture!\n"};
    }

    this->sprite.setTexture(texture,true);
}

office::office(const office &orginal)
{
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
    this->size = orginal.size;

    for(auto door : orginal.doors)
        this->doors.push_back(door);
    for(auto button : orginal.buttons)
        this->buttons.push_back(button);
}

office::office(office &&orginal)
{
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
    this->size = orginal.size;

    for(auto door : orginal.doors)
        this->doors.push_back(door);
    for(auto button : orginal.buttons)
        this->buttons.push_back(button);
}
