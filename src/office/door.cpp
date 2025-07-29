#include "door.hpp"
#include "../exceptions.hpp"
#include"iostream"

using namespace meme;

meme::Door::Door(sf::Texture &texture, sf::Vector2f possition, sf::Vector2i size, int variants_amount, Direction direction, bool flip):    door_sound{nullptr}, light_sound{nullptr}, possition{possition}, size{size}, flip{flip}, direction{direction}
{
    this->texture_ptr = &texture;

    for(int i=0;i<variants_amount;i++)
    {
        all_sprite_variants.push_back({{i*size.x,0},{size.x,size.y}});
    }
    for(int i=0;i<3;i++)
    {
        used_sprite_variants[i] = all_sprite_variants[i];
    }

    this->sprite.setTexture(*texture_ptr,true);
    this->sprite.setTextureRect(used_sprite_variants[0]);
    this->sprite.setPosition(possition);

    if(this->flip)
    {
        this->sprite.setScale({-1.0,1.0});
    }
}

meme::Door::Door(const Door &orginal)
{
    this->light_status = orginal.light_status;
    this->power_status = orginal.power_status;
    this->possition = orginal.possition;
    this->size = orginal.size;
    this->all_sprite_variants = orginal.all_sprite_variants;
    this->used_sprite_variants = orginal.used_sprite_variants;
    this->flip = orginal.flip;

    this->door_sound = orginal.door_sound;
    this->light_sound = orginal.light_sound;

    this->texture_ptr = orginal.texture_ptr;
    this->sprite.setTexture(*this->texture_ptr,true);
    this->sprite.setTextureRect(this->used_sprite_variants[0]);
    this->sprite.setPosition(this->possition);

    if(this->flip)
    {
        this->sprite.setScale({-1.0,1.0});
    }
}

meme::Door::Door(Door &&orginal)
{
    this->light_status = orginal.light_status;
    this->power_status = orginal.power_status;
    this->possition = orginal.possition;
    this->size = orginal.size;
    this->all_sprite_variants = orginal.all_sprite_variants;
    this->used_sprite_variants = orginal.used_sprite_variants;
    this->flip = orginal.flip;

    this->door_sound = orginal.door_sound;
    this->light_sound = orginal.light_sound;

    this->texture_ptr = orginal.texture_ptr;
    this->sprite.setTexture(*this->texture_ptr,true);
    this->sprite.setTextureRect(this->used_sprite_variants[0]);
    this->sprite.setPosition(this->possition);

    if(this->flip)
    {
        this->sprite.setScale({-1.0,1.0});
    }
}

void Door::On_notify ( const Event event, const Direction direction )
{

    switch(event)
    {
        case Event::ENTER:
            switch(direction)
            {
                case Direction::LEFT:
                    used_sprite_variants[2] = all_sprite_variants[3];
                    break;
                case Direction::RIGHT:
                    used_sprite_variants[2] = all_sprite_variants[4];
                    break;
            }
            break;
        case Event::LEAVE:
            used_sprite_variants[2] = all_sprite_variants[2];
            break;
    }

    Texture_update();
}

void Door::Texture_update()
{
    switch(power_status)
    {
        case open:
            switch(light_status)
            {
                case up:
                    sprite.setTextureRect(used_sprite_variants[2]);
                    break;
                case down:
                    sprite.setTextureRect(used_sprite_variants[0]);
                    break;
            }
        case close:
            sprite.setTextureRect(used_sprite_variants[1]);
    }
}


void meme::Door::Open()
{
    power_status = open;
    if(light_status == up)
    {
        sprite.setTextureRect(used_sprite_variants[2]);
    }
    else
    {
        sprite.setTextureRect(used_sprite_variants[0]);
    }

    subject.Notify(Event::DOOR_OPEN,direction);
}

void meme::Door::Close(void)
{
    if(door_sound != nullptr) door_sound->play();

    power_status = close;
    sprite.setTextureRect(used_sprite_variants[1]);

    subject.Notify(Event::DOOR_CLOSED,direction);
}

void meme::Door::Light_down()
{
    if(light_sound != nullptr) light_sound->stop();

    light_status = down;
    if(power_status == open)
    {
        sprite.setTextureRect(used_sprite_variants[0]);
    }

    subject.Notify(Event::DOOR_LIGHT_DOWN,direction);
}

void meme::Door::Light_up()
{
    if(light_sound != nullptr)
    {
        light_sound->setLooping(true);
        light_sound->play();
    }

    light_status = up;
    if(power_status == open)
    {
        sprite.setTextureRect(used_sprite_variants[2]);
    }

    subject.Notify(Event::DOOR_LIGHT_UP,direction);
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
