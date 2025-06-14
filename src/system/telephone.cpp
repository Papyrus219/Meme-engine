#include"telephone.hpp"
using namespace meme;

Telephone::Telephone(std::string audio_path, int jumpscares_amount, int sound_clues_amount, int tracks_amount)
{
    for(int i=0;i<jumpscares_amount;i++)
    {
        jumpscares_buffors.emplace_back(sf::SoundBuffer{audio_path + "/buffers/buffer" + std::to_string(i)});
        jumpscares_sounds.emplace_back(sf::Sound{jumpscares_buffors[i]});
    }
    for(int i=0;i<sound_clues_amount;i++)
    {
        sound_clues_buffors.emplace_back(sf::SoundBuffer{audio_path + "/clues/clue" + std::to_string(i)});
        sound_clues_sounds.emplace_back(sf::Sound{sound_clues_buffors[i]});
    }
    for(int i=0;i<tracks_amount;i++)
    {
        soundtracks.emplace_back(sf::Music{audio_path + "/soundtrack/track" + std::to_string(i)});
    }
}
