#ifndef MEME_DOOR_H
#define MEME_DOOR_H

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<array>

namespace meme
{

/**
 * Classs representing office door.
 */
class Door
{
public:
    Door(sf::Texture &texture, sf::Vector2f possition, sf::Vector2i size, int variants_amount);
    Door(const Door &orginal);
    Door(Door &&orginal);

    std::vector<sf::IntRect> All_sprite_variants;
    std::array<sf::IntRect,3> Used_sprite_variants;
    sf::Sound *door_sound;
    sf::Sound *light_sound;

    void Open();
    void Close();
    void Light_up();
    void Light_down();

    bool Get_if_open();
    bool Get_if_light();
    const sf::Sprite* Get_sprite_ptr(){return &sprite;};

private:
    sf::Vector2f possition;
    sf::Vector2f size;
    sf::Texture *texture_ptr{};
    sf::Texture tmp_texture;
    sf::Sprite sprite{tmp_texture};

    enum power_states{open,close};
    enum light_states{up,down};
    power_states power_status{open};
    light_states light_status{up};
};

}

#endif // MEME_DOOR_H
