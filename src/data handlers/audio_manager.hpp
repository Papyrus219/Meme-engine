#ifndef AUDIO_MANAGER
#define AUDIO_MANAGER

#include<SFML/Audio.hpp>
#include<vector>

namespace meme
{

class Audio_manager
{
public:
    Audio_manager(std::string audio_path, int jumpscares_amount=0, int sound_clues_amount=0, int sound_effects_amount=0, int phone_guy_amount=0, int tracks_amount=0);
    Audio_manager() = default;

    void Load_jumpscares_sounds(int jumpscares_amount);
    void Load_sound_clues(int sound_clues_amount);
    void Load_sound_effects(int sound_effects_amount);
    void Load_phone_guy(int phone_guy_amount);
    void Load_soundtrack(int tracks_amount);

    sf::Sound* Get_jumpscare_sound_ptr(int wich);
    sf::Sound* Get_sound_clue_ptr(int wich);
    sf::Sound* Get_sound_effect_ptr(int wich);
    sf::Sound* Get_phone_guy_ptr(int wich);
    sf::Music* Get_sound_track_ptr(int wich);

    int Get_jumpscare_amount(){return jumpscares_sounds.size();};
    int Get_sound_clue_amount(){return sound_clues_sounds.size();};
    int Get_sound_effects_amount(){return sound_effects_sounds.size();};
    int Get_phone_calls_amount(){return phone_guy_sounds.size();};
    int Get_sound_track_amount(){return soundtrack.size();};

    void Change_volume(int jumpscare_volume, int sound_clues_volume, int sound_effects_volume, int phone_guy_volume, int soundtrack_volume);

private:
    std::vector<sf::SoundBuffer> jumpscares_buffors{};
    std::vector<sf::SoundBuffer> sound_clues_buffors{};
    std::vector<sf::SoundBuffer> sound_effects_buffors{};
    std::vector<sf::SoundBuffer> phone_guy_buffors{};

    std::vector<sf::Sound> jumpscares_sounds{};
    std::vector<sf::Sound> sound_clues_sounds{};
    std::vector<sf::Sound> sound_effects_sounds{};
    std::vector<sf::Sound> phone_guy_sounds{};
    std::vector<sf::Music> soundtrack{};

    std::string audio_path{};
};

}

#endif
