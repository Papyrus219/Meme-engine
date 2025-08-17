#include "menu.hpp"
#include"../exceptions.hpp"

using namespace meme;

Menu::Menu ( std::string tex_path, sf::Vector2i size )
{
    if(!background_texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load menu texture!"};
    }

    background_sprite.setTexture(background_texture,true);
    this->background_size = size;
}

