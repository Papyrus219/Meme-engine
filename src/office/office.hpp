#ifndef OFFICE
#define OFFICE

#include<SFML/Graphics.hpp>
#include<vector>
#include"button.hpp"
#include"door.hpp"
#include"../system/scene.hpp"

namespace meme
{

struct Office final : public Scene
{
    Office(std::string tex_path, sf::Vector2i size);
    Office(const Office &orginal);
    Office(Office &&orginal);

    std::vector<Button> buttons;
    std::vector<Door> doors;

    sf::Texture texture{};
    sf::Sprite sprite{texture};
    sf::Vector2i size;
    sf::View view{};

    void Render() override final;
    void Event() override final;
    void Power_off();
};

}
#endif
