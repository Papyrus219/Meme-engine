#ifndef OFFICE
#define OFFICE

#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>
#include"button.hpp"
#include"door.hpp"
#include"../window system/scene.hpp"
#include"../data handlers/parameters.hpp"

namespace meme
{

struct Office final : public Scene
{
    Office(std::string tex_path, sf::Vector2i size);
    Office(const Office &orginal);
    Office(Office &&orginal);

    std::vector<Button> buttons;
    std::vector<Door> doors;

    std::vector<sf::Texture> button_textures;
    std::vector<sf::Texture> door_textures;

    std::shared_ptr<Parameters> parameters_ptr;

    sf::Vector2i window_size;
    sf::View view{};
    bool power_off{};

    void Load_button_textures(std::string path, int amount);
    void Load_door_textures(std::string path, int amount);

    void Render() override final;
    void Event() override final;
    void Power_off();
    void Start_night();
};

}
#endif
