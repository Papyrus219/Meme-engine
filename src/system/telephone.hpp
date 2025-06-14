#ifndef TELEPHONE
#define TELEPHONE

#include<SFML/Audio.hpp>
#include<vector>

namespace meme
{

struct Telephone
{
    Telephone(std::string audio_path, int jumpscares_amount, int sound_clues_amount, int tracks_amount);

    std::vector<sf::SoundBuffer> jumpscares_buffors;
    std::vector<sf::Sound> jumpscares_sounds;

    std::vector<sf::SoundBuffer> sound_clues_buffors;
    std::vector<sf::Sound> sound_clues_sounds;

    std::vector<sf::Music> soundtracks;
};

}

#endif
