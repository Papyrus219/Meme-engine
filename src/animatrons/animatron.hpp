#ifndef MEME_ANIMATRON_H
#define MEME_ANIMATRON_H

#include<vector>
#include<SFML/Graphics.hpp>
#include"../office/office.hpp"
#include"../cameras/cameras.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Animatron
{
public:
    Animatron(int value, std::vector<int> move_path, Cameras &camera_system);
    void Setup_jumpscare(sf::Texture &jump_tex, sf::Vector2i size, sf::IntRect assigned_tex_part, int frames_amount, int rows_amount=1);
    const int value{-1};
    const std::vector<int> move_path{};
    int dificulty{};
    int current_possition{};

    virtual void Under_door(Office *office) = 0;
    bool Move(Office *office);
    void Jumpscare(Scene *office);
private:
    int frames_amount;
    sf::Texture *texture{};
    sf::Sprite sprite{*texture};
    sf::Vector2i size{};
    sf::IntRect assigned_tex_part{};
    std::vector<sf::IntRect> frames{};

    Cameras *assign_camera_system{};
};

}

#endif // MEME_ANIMATRON_H
