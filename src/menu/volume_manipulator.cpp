#include "volume_manipulator.hpp"

using namespace meme;

Volume_manipulator::Volume_manipulator ( int* parameter, const sf::Texture& button_texture, const sf::Texture& icon_texture, sf::IntRect button_rect, sf::IntRect icon_rect, sf::Vector2f possition, sf::Font &font): assign_parameter{parameter},possition{possition}, assign_button_texture{&button_texture}, assign_icon_texture{&icon_texture}, font{font}
{
    button_sprites[0].setTexture(*assign_button_texture,true);
    button_sprites[0].setScale({0.4,0.4});
    button_sprites[0].setTextureRect(button_rect);
    button_sprites[0].setPosition(possition);

    button_sprites[1].setTexture(*assign_button_texture,true);
    button_sprites[1].setScale({0.4,0.4});
    button_sprites[1].setTextureRect(button_rect);
    button_sprites[1].scale({-1,1});
    button_sprites[1].setPosition({possition.x + (button_rect.size.x * static_cast<float>(0.4)) +20, possition.y});
    button_sprites[1].move({button_sprites[1].getLocalBounds().size.x * static_cast<float>(0.4) ,0});

    icon_sprite.setTexture(*assign_icon_texture,true);
    icon_sprite.setScale({0.4,0.4});
    icon_sprite.setTextureRect(icon_rect);
    icon_sprite.setPosition({possition.x + (2*button_rect.size.x * static_cast<float>(0.4) +60), possition.y});

    vareible_string.setFont(font);
    vareible_string.setFillColor(sf::Color::Green);
    vareible_string.setCharacterSize(button_rect.size.y * 0.4);
    vareible_string.setPosition({possition.x + (3*button_rect.size.x * static_cast<float>(0.4) + 80), possition.y});
}

bool Volume_manipulator::Click ( sf::Vector2f mouse_possition )
{
    if(button_sprites[0].getGlobalBounds().contains(mouse_possition))
    {
        if(*assign_parameter > 0) *assign_parameter -= 10;

        return true;
    }
    else if(button_sprites[1].getGlobalBounds().contains(mouse_possition))
    {
        if(*assign_parameter < 100) *assign_parameter += 10;

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

    vareible_string.setString(std::to_string(*assign_parameter));
    assign_window->draw(vareible_string);
}
