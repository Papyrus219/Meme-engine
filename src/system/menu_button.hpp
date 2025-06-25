#ifndef MEME_MENU_BUTTON_H
#define MEME_MENU_BUTTON_H

#include"../office/button.hpp"

namespace meme {

/**
 * Special kind of button, that don't change state after clicked. It just execute function.
 */
class Menu_button: public Button
{
public:
    Menu_button(sf::Texture &texture, sf::IntRect part_of_texture, sf::Vector2f possition, std::function<void()> function_state);
    Menu_button() = default;
    Menu_button(const Menu_button& orginal);
    Menu_button(Menu_button&& orginal);

    bool Clicked(sf::Vector2f Mouse_pos);

protected:
    std::function<void()> function_state;
};

}

#endif // MEME_MENU_BUTTON_H
