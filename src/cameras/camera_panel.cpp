#include"camera_panel.hpp"
#include"../exceptions.hpp"
#include"cameras.hpp"
using namespace meme;

Camera_panel::Camera_panel ( std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, sf::Vector2f hit_box_size ): size{size}, possition{possition}
{
    if(!this->texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load texture of camera_panel."};
    }
    this->sprite.setTexture(texture,true);
    this->sprite.setPosition(possition);
    this->sprite.setTextureRect({{0,0},{size}});

    for(int i=0;i<hit_box_possitions.size();i++)
    {
        hitboxes.push_back(sf::RectangleShape{hit_box_size});
        hitboxes[i].setFillColor(sf::Color::Transparent);
        hitboxes[i].setPosition({possition.x+hit_box_possitions[i].x , possition.y+hit_box_possitions[i].y});
    }
}

Camera_panel::Camera_panel ( std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, std::vector<sf::Vector2f> hit_box_sizes ): size{size}, possition{possition}
{
    if(hit_box_possitions.size() != hit_box_sizes.size())
    {
        throw Exeption{"Size of camera panel hit boxes possition and sizes don't match."};
    }

    if(!this->texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load texture of camera_panel."};
    }
    this->sprite.setTexture(texture,true);
    this->sprite.setPosition(possition);
    this->sprite.setTextureRect({{0,0},{size}});

    for(int i=0;i<hit_box_possitions.size();i++)
    {
        hitboxes.push_back(sf::RectangleShape{hit_box_sizes[i]});
        hitboxes[i].setFillColor(sf::Color::Transparent);
        hitboxes[i].setPosition({possition.x+hit_box_possitions[i].x , possition.y+hit_box_possitions[i].y});
    }
}
