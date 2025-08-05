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

    virtual bool Move(sf::Time current_time);
    void Setup_jumpscare(sf::Texture &jump_tex, sf::Vector2i size, sf::IntRect assigned_tex_part, int frames_amount, int rows_amount=1);

    const int value{};
    int dificulty{};

protected:

    Animatron(int value, std::vector<int> move_path_, Cameras &camera_system, Office *office, int tic_duration_milisec);
    virtual void Under_door() = 0;
    void Jumpscare();

    int *move_path{};
    int move_path_size{};
    int current_possition{};
    int frames_amount;

    sf::Texture *texture{};
    sf::Sprite *sprite{};
    sf::Vector2i size{};
    sf::IntRect assigned_tex_part{};
    std::vector<sf::IntRect> frames{};

    Cameras *assign_camera_system{};
    Office *assign_office;
    sf::Time tic_duration{};
    sf::Time current_tic_time{};
};

}

#endif // MEME_ANIMATRON_H
