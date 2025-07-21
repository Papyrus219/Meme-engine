#ifndef CAMERA_PANEL
#define CAMERA_PANEL

#include<SFML/Graphics.hpp>

namespace meme
{

struct Camera_panel
{
    Camera_panel(std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, sf::Vector2f hit_box_size);
    Camera_panel(std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, std::vector<sf::Vector2f> hit_box_sizes);
    Camera_panel() = default;

    sf::Vector2i size{};
    sf::Vector2i possition{};
    sf::Texture texture{};
    sf::Sprite sprite{texture};

    std::vector<sf::RectangleShape> hitboxes{};
};

}

#endif //CAMERA_PANEL
