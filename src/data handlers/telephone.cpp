#include"telephone.hpp"
using namespace meme;

Telephone::Telephone(std::string audio_path, int jumpscares_amount, int sound_clues_amount, int sound_effects_amount, int phone_guy_amount, int tracks_amount): audio_path{audio_path}
{
    jumpscares_buffors.reserve(jumpscares_amount);
    jumpscares_sounds.reserve(jumpscares_amount);
    sound_clues_buffors.reserve(sound_clues_amount);
    sound_clues_sounds.reserve(sound_clues_amount);
    sound_effects_buffors.reserve(sound_effects_amount);
    sound_effects_sounds.reserve(sound_effects_amount);
    phone_guy_buffors.reserve(phone_guy_amount);
    phone_guy_sounds.reserve(phone_guy_amount);
    soundtrack.reserve(tracks_amount);

    for(int i=0;i<jumpscares_amount;i++)
    {
        jumpscares_buffors.emplace_back(sf::SoundBuffer{audio_path + "/jumpscares/jumpscare" + std::to_string(i+1) + ".wav"});
        jumpscares_sounds.emplace_back(sf::Sound{jumpscares_buffors[i]});
    }
    for(int i=0;i<sound_clues_amount;i++)
    {
        sound_clues_buffors.emplace_back(sf::SoundBuffer{audio_path + "/clues/clue" + std::to_string(i+1) + ".wav"});
        sound_clues_sounds.emplace_back(sf::Sound{sound_clues_buffors[i]});
    }
    for(int i=0;i<sound_effects_amount;i++)
    {
        sound_effects_buffors.emplace_back(sf::SoundBuffer{audio_path + "/effects/effect" + std::to_string(i+1) + ".wav"});
        sound_effects_sounds.emplace_back(sf::Sound{sound_effects_buffors[i]});
    }
    for(int i=0;i<phone_guy_amount;i++)
    {
        phone_guy_buffors.emplace_back(sf::SoundBuffer{audio_path + "/phone_guy/record" +std::to_string(i+1) + ".wav"});
        phone_guy_sounds.emplace_back(sf::Sound{phone_guy_buffors[i]});
    }
    for(int i=0;i<tracks_amount;i++)
    {
        soundtrack.emplace_back(sf::Music{audio_path + "/soundtrack/track" + std::to_string(i+1)});
    }
}

void Telephone::Load_jumpscares_sounds(int jumpscares_amount)
{
    jumpscares_buffors.clear();
    jumpscares_sounds.clear();
    jumpscares_buffors.reserve(jumpscares_amount);
    jumpscares_sounds.reserve(jumpscares_amount);

    for(int i=0;i<jumpscares_amount;i++)
    {
        jumpscares_buffors.emplace_back(sf::SoundBuffer{audio_path + "/buffers/buffer_" + std::to_string(i+1) + ".wav"});
        jumpscares_sounds.emplace_back(sf::Sound{jumpscares_buffors[i]});
    }
}

void Telephone::Load_sound_clues(int sound_clues_amount)
{
    sound_clues_buffors.clear();
    sound_clues_sounds.clear();
    sound_clues_buffors.reserve(sound_clues_amount);
    sound_clues_sounds.reserve(sound_clues_amount);

    for(int i=0;i<sound_clues_amount;i++)
    {
        sound_clues_buffors.emplace_back(sf::SoundBuffer{audio_path + "/clues/clue_" + std::to_string(i+1) + ".wav"});
        sound_clues_sounds.emplace_back(sf::Sound{sound_clues_buffors[i]});
    }
}

void Telephone::Load_sound_effects(int sound_effects_amount)
{
    sound_effects_buffors.clear();
    sound_effects_sounds.clear();
    sound_effects_buffors.reserve(sound_effects_amount);
    sound_effects_sounds.reserve(sound_effects_amount);

    for(int i=0;i<sound_effects_amount;i++)
    {
        sound_effects_buffors.emplace_back(sf::SoundBuffer{audio_path + "/effects/effect_" + std::to_string(i+1) + ".wav"});
        sound_effects_sounds.emplace_back(sf::Sound{sound_effects_buffors[i]});
    }
}

void Telephone::Load_phone_guy(int phone_guy_amount)
{
    phone_guy_buffors.clear();
    phone_guy_sounds.clear();
    phone_guy_buffors.reserve(phone_guy_amount);
    phone_guy_sounds.reserve(phone_guy_amount);

    for(int i=0;i<phone_guy_amount;i++)
    {
        phone_guy_buffors.emplace_back(sf::SoundBuffer{audio_path + "/phone_guy/record_" +std::to_string(i+1) + ".wav"});
        phone_guy_sounds.emplace_back(sf::Sound{phone_guy_buffors[i]});
    }
}

void Telephone::Load_soundtrack(int tracks_amount)
{
    soundtrack.clear();
    soundtrack.reserve(tracks_amount);

    for(int i=0;i<tracks_amount;i++)
    {
        soundtrack.emplace_back(sf::Music{audio_path + "/soundtrack/track_" + std::to_string(i+1) + ".wav"});
    }
}

sf::Sound *Telephone::Get_jumpscare_sound_ptr(int wich)
{
    if(wich < 0 || wich >= jumpscares_sounds.size()) return nullptr;

    return &jumpscares_sounds[wich];
}

sf::Sound *Telephone::Get_sound_clue_ptr(int wich)
{
    if(wich < 0 || wich >= sound_clues_sounds.size()) return nullptr;

    return &sound_clues_sounds[wich];
}

sf::Sound *Telephone::Get_sound_effect_ptr(int wich)
{
    if(wich < 0 || wich >= sound_effects_sounds.size()) return nullptr;

    return &sound_effects_sounds[wich];
}

sf::Sound *Telephone::Get_phone_guy_ptr(int wich)
{
    if(wich < 0 || wich >= phone_guy_sounds.size()) return nullptr;

    return &phone_guy_sounds[wich];
}

sf::Music *Telephone::Get_sound_track_ptr(int wich)
{
    if(wich < 0 || wich >= soundtrack.size()) return nullptr;

    return &soundtrack[wich];
}
