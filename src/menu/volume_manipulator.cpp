#include "volume_manipulator.hpp"

using namespace meme;

Volume_manipulator::Volume_manipulator ( int* parameter, sf::Texture& button_texture, sf::Texture& icon_texture, sf::IntRect button_rect, sf::IntRect icon_rect, sf::Vector2f possition ): assign_parameter{parameter},possition{possition}, assign_button_texture{&button_texture}, assign_icon_texture{&icon_texture}
{
    button_sprites[0].setTexture(*assign_button_texture,true);
    button_sprites[0].setTextureRect(button_rect);
    button_sprites[0].setPosition(possition);

    button_sprites[1].setTexture(*assign_button_texture,true);
    button_sprites[1].setTextureRect(button_rect);
    button_sprites[1].scale({-1,0});
    button_sprites[1].setPosition({possition.x + button_rect.size.x, possition.y});

    icon_sprite.setTexture(*assign_icon_texture,true);
    icon_sprite.setTextureRect(icon_rect);
    icon_sprite.setPosition({possition.x + (2*button_rect.size.x), possition.y});
}

bool Volume_manipulator::Click ( sf::Vector2f mouse_possition )
{
    if(button_sprites[0].getGlobalBounds().contains(mouse_possition))
    {
        if(*assign_parameter > 0) assign_parameter -= 10;

        return true;
    }
    else if(button_sprites[1].getGlobalBounds().contains(mouse_possition))
    {
        if(*assign_parameter < 100) assign_parameter += 10;

        return true;
    }

    return false;
}

void Volume_manipulator::Render ( sf::RenderWindow* assign_window )
{
    for(auto &button : button_sprites)
    {
        assign_window->draw(button);
    }

    assign_window->draw(icon_sprite);
}
