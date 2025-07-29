#ifndef MEME_OPTIONS_H
#define MEME_OPTIONS_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"../data handlers/telephone.hpp"
#include"menu_button.hpp"
#include"../scene.hpp"

namespace meme {

/**
 * @todo write docs
 */
struct Options: public Scene
{
    Options(std::string tex_path, sf::Vector2i size, Telephone &telephone);

    void Up(int &x);
    void Down(int &x);
    void Update();
    //void Render() override;
    //void Event() override;

    std::vector<Menu_button> buttons;
    int jumpscare_volume{};
    int clues_volume{};
    int efect_volume{};
    int dialog_volume{};
    int music_volume{};
    bool meme_man_size{};

    sf::Texture texture{};
    sf::Sprite sprite{texture};
    sf::Vector2i size;

    Telephone *telephone_ptr{};
};

}

#endif // MEME_OPTIONS_H
