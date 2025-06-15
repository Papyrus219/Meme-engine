#include "menu.hpp"
#include"../exceptions.hpp"

using namespace meme;

Menu::Menu ( std::string tex_path, sf::Vector2i size )
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load menu texture!"};
    }

    sprite.setTexture(texture,true);
    this->size = size;
}

void Menu::Make_buttons ( std::string button_tex_path, int button_amount, sf::Vector2i button_size, sf::Vector2f possition )
{
    sf::Texture tmp_texture;
    if(!tmp_texture.loadFromFile(button_tex_path))
    {
        throw Exeption{"Failed to load buttons texture!"};
    }
    button_textures.push_back(tmp_texture);

    for(int i=0;i<button_amount;i++)
    {
        sf::IntRect tmp_rect{{0,button_size.y*i},{button_size.x,button_size.y}};
        option_buttons.emplace_back(Menu_button{ button_textures[button_textures.size()-1], tmp_rect, sf::Vector2f{possition.x,possition.y*(i+1)}, nullptr });
    }
}

void Menu::Make_buttons ( std::string button_tex_path, int button_amount, std::vector<sf::Vector2i> button_sizes, std::vector<sf::Vector2f> possitions )
{
    sf::Texture tmp_texture;
    if(!tmp_texture.loadFromFile(button_tex_path))
    {
        throw Exeption{"Failed to load buttons texture!"};
    }
    button_textures.push_back(tmp_texture);

    int whole_height{};
    for(int i=0;i<button_amount;i++)
    {
        sf::IntRect tmp_rect{{0,whole_height},{button_sizes[i].x,button_sizes[i].y}};
        option_buttons.emplace_back(Menu_button{ button_textures[button_textures.size()-1], tmp_rect, possitions[i], nullptr});
        whole_height += button_sizes[i].y;
    }
}
