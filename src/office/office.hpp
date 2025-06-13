#ifndef OFFICE
#define OFFICE

#include<SFML/Graphics.hpp>
#include<vector>
#include"button.hpp"
#include"door.hpp"

namespace meme
{

struct office
{
    office(std::string tex_path, sf::Vector2i size);
    office(office &orginal);

    std::vector<Button> door_buttons;
    std::vector<Button> light_buttons;
    std::vector<Door> doors;
    sf::Texture texture{};
    sf::Sprite sprite{texture};
    sf::Vector2i size;

    void Power_off();
};

}
#endif
