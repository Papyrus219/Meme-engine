#ifndef MEME_PARAMETER_OPTION_H
#define MEME_PARAMETER_OPTION_H

#include<SFML/Graphics.hpp>
#include<array>

namespace meme {

/**
 * @todo write docs
 */
class Volume_manipulator
{
public:
    Volume_manipulator(int *parameter, sf::Texture &button_texture, sf::Texture &icon_texture, sf::IntRect button_rect, sf::IntRect icon_rect, sf::Vector2f possition);
    void Render(sf::RenderWindow *assign_window);
    bool Click(sf::Vector2f mouse_possition);

private:
    int *assign_parameter{};

    sf::Vector2i possition{};
    sf::IntRect button_tex_fragment{};
    sf::IntRect icon_tex_fragment{};
    sf::Texture *assign_button_texture{};
    sf::Texture *assign_icon_texture{};
    std::array<sf::Sprite,2> button_sprites{sf::Sprite{*assign_button_texture},sf::Sprite{*assign_button_texture}};
    sf::Sprite icon_sprite{*assign_icon_texture};
};

}

#endif // MEME_PARAMETER_OPTION_H
