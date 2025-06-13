#include "door.hpp"
#include "../exceptions.hpp"

using namespace meme;

meme::Door::Door(std::string tex_path, sf::Vector2f possition, sf::Vector2i size, int variants_amount) : possition{possition}, size{size}
{
    if(!this->texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load door texture!\n"};
    }

    for(int i=0;i<variants_amount;i++)
    {
        All_sprite_variants.push_back({{i*size.x,0},{size.x,size.y}});
    }
    for(int i=0;i<3;i++)
    {
        Used_sprite_variants[i] = All_sprite_variants[i];
    }

    this->sprite.setTexture(texture,true);
    this->sprite.setTextureRect(Used_sprite_variants[0]);
    this->sprite.setPosition(possition);
}

void meme::Door::Open()
{
    power_status = open;
    if(light_status == up)
    {
        sprite.setTextureRect(Used_sprite_variants[1]);
    }
    else
    {
        sprite.setTextureRect(Used_sprite_variants[0]);
    }
}

meme::Door::Door(Door& orginal)
{
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);

    this->light_status = orginal.light_status;
    this->power_status = orginal.power_status;
    this->possition = orginal.possition;
    this->size = orginal.size;
    this->All_sprite_variants = orginal.All_sprite_variants;
    this->Used_sprite_variants = orginal.Used_sprite_variants;
}

void meme::Door::Close()
{
    power_status = close;
    sprite.setTextureRect(Used_sprite_variants[2]);
}

void meme::Door::Light_down()
{
    light_status = down;
    if(power_status == open)
    {
        sprite.setTextureRect(Used_sprite_variants[0]);
    }
}

void meme::Door::Light_up()
{
    light_status = up;
    if(power_status == open)
    {
        sprite.setTextureRect(Used_sprite_variants[1]);
    }
}

bool meme::Door::Get_if_light()
{
    if(light_status == up)
        return true;
    return false;
}

bool meme::Door::Get_if_open()
{
    if(power_status == open)
        return true;
    return false;
}
