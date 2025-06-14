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
    office(const office &orginal);
    office(office &&orginal);

    std::vector<Button> buttons;
    std::vector<Door> doors;

    sf::Texture texture{};
    sf::Sprite sprite{texture};
    sf::Vector2i size;
    int assigned_window_number;

    void Power_off();
};

}
#endif
