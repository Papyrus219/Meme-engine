#include "menu_button.h"

using namespace meme;

Menu_button::Menu_button ( sf::Texture& texture, sf::IntRect part_of_texture, sf::Vector2f possition, std::function<void () > function_state ): function_state{function_state}
{
    sprite.setTexture(texture);
    sprite.setTextureRect(part_of_texture);
    sprite.setPosition(possition);

    size.x = part_of_texture.size.x;
    size.y = part_of_texture.size.y;
    this->possition = possition;
}


Menu_button::Menu_button ( const Menu_button& orginal ): Button{orginal}
{
    this->function_state = orginal.function_state;
}

Menu_button::Menu_button ( Menu_button && orginal ): Button{std::move(orginal)}
{
    this->function_state = orginal.function_state;
}

bool Menu_button::Clicked ( sf::Vector2f Mouse_pos )
{
    if(sprite.getGlobalBounds().contains(Mouse_pos))
    {
        function_state();

        return true;
    }

    return false;
}
