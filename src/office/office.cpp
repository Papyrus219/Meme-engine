#include"office.hpp"
#include"../exceptions.hpp"
using namespace meme;

meme::office::office(std::string tex_path, sf::Vector2i size): size{size}
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load office texture!\n"};
    }

    this->sprite.setTexture(texture,true);
}

meme::office::office(office& orginal)
{
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture);

    this->size = orginal.size;
    for(int i=0;i<orginal.doors.size();i++)
    {
        this->doors.push_back(orginal.doors[i]);
    }
}
