#include "options.hpp"
#include "../exceptions.hpp"

using namespace meme;

Options::Options(std::string tex_path, sf::Vector2i size, Telephone& telephone): size{size}, telephone_ptr{&telephone}
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load option texture!\n"};
    }
    sprite.setTexture(texture,true);
}

void Options::Up(int& x)
{
    if(x+5 <= 100) x+=5;
}

void Options::Down(int& x)
{
    if(x-5 >= 0) x-=5;
}

void Options::Update()
{
    for(int i=0;i<telephone_ptr->Get_jumpscare_amount();i++)
    {
        auto jumpscare_sound = telephone_ptr->Get_jumpscare_sound_ptr(i);
        jumpscare_sound->setVolume(100 - jumpscare_volume);
    }
    for(int i=0;i<telephone_ptr->Get_sound_clue_amount();i++)
    {
        auto sound_clue = telephone_ptr->Get_sound_clue_ptr(i);
        sound_clue->setVolume(clues_volume);
    }
    for(int i=0;i<telephone_ptr->Get_sound_effects_amount();i++)
    {
        auto sound_effect = telephone_ptr->Get_sound_clue_ptr(i);
        sound_effect->setVolume(efect_volume);
    }
    for(int i=0;i<telephone_ptr->Get_phone_calls_amount();i++)
    {
        auto phone_call = telephone_ptr->Get_phone_guy_ptr(i);
        phone_call->setVolume(dialog_volume);
    }
    for(int i=0;i<telephone_ptr->Get_sound_track_amount();i++)
    {
        auto track = telephone_ptr->Get_sound_track_ptr(i);
        track->setVolume(music_volume);
    }
}
