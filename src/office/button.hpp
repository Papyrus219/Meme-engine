#ifndef BUTTON_H
#define BUTTON_H

#include<SFML/Graphics.hpp>
#include<vector>
#include<functional>

namespace meme
{

/**
* Class that reprezente all sort off buttons.
*/
class Button
{
public:
    Button(std::string tex_path, sf::Vector2f possition, sf::Vector2i size, std::vector<std::function<void()>> states_functions);
    Button(Button &orginal);

    std::vector<sf::IntRect> sprite_variants;

    const sf::Sprite* Get_sprite_ptr(){return &sprite;};
    bool Clicked(sf::Vector2f Mouse_pos);
private:
    sf::Vector2f possition;
    sf::Vector2f size;
    sf::Texture texture{};
    sf::Sprite sprite{texture};
    std::vector<std::function<void()>> states_functions;
    int state{};
};

}

#endif // BUTTON_H
