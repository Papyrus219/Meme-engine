#include "door.hpp"
#include "../exceptions.hpp"

using namespace meme;

meme::Door::Door(std::string tex_path, sf::Vector2f possition, sf::Vector2i size, int variants_amount):    door_sound{nullptr}, light_sound{nullptr}, possition{possition}, size{size}
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

    this->light_sound->setLooping(true);
}

meme::Door::Door(const Door &orginal)
{
    this->light_status = orginal.light_status;
    this->power_status = orginal.power_status;
    this->possition = orginal.possition;
    this->size = orginal.size;
    this->All_sprite_variants = orginal.All_sprite_variants;
    this->Used_sprite_variants = orginal.Used_sprite_variants;

    this->door_sound = orginal.door_sound;
    this->light_sound = orginal.light_sound;
    this->light_sound->setLooping(true);

    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
    this->sprite.setTextureRect(this->Used_sprite_variants[0]);
}

meme::Door::Door(Door &&orginal)
{
    this->light_status = orginal.light_status;
    this->power_status = orginal.power_status;
    this->possition = orginal.possition;
    this->size = orginal.size;
    this->All_sprite_variants = orginal.All_sprite_variants;
    this->Used_sprite_variants = orginal.Used_sprite_variants;

    this->door_sound = orginal.door_sound;
    this->light_sound = orginal.light_sound;
    this->light_sound->setLooping(true);

    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
    this->sprite.setTextureRect(this->Used_sprite_variants[0]);
}

void meme::Door::Open()
{
    if(door_sound != nullptr) door_sound->play();

    power_status = open;
    if(light_status == up)
    {
        sprite.setTextureRect(Used_sprite_variants[0]);
    }
    else
    {
        sprite.setTextureRect(Used_sprite_variants[2]);
    }
}

void meme::Door::Close(void)
{
    if(door_sound != nullptr) door_sound->play();

    power_status = close;
    sprite.setTextureRect(Used_sprite_variants[1]);
}

void meme::Door::Light_down()
{
    if(light_sound != nullptr) light_sound->stop();

    light_status = down;
    if(power_status == open)
    {
        sprite.setTextureRect(Used_sprite_variants[0]);
    }
}

void meme::Door::Light_up()
{
    if(light_sound != nullptr) light_sound->play();

    light_status = up;
    if(power_status == open)
    {
        sprite.setTextureRect(Used_sprite_variants[2]);
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
