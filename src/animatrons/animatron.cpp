#include <cstdlib>
#include "animatron.hpp"
#include "../exceptions.hpp"
#include<iostream>

using namespace meme;

Animatron::Animatron ( int value, std::vector<int> move_path_, Cameras &camera_system, Office *office, int tic_durration_milisec): value{value}, assign_camera_system{&camera_system}, assign_office{office}, tic_duration{sf::milliseconds(tic_durration_milisec)}
{
    move_path = move_path_;

    auto start_camera = assign_camera_system->Get_camera_ptr(move_path[0]);
    start_camera->Move_in(*this);
}

void Animatron::Setup_jumpscare ( sf::Texture& jump_tex, sf::Vector2i size, sf::IntRect assigned_tex_part, int frames_amount, int rows_amount )
{
    this->texture = &jump_tex;
    this->size = size;
    this->assigned_tex_part = assigned_tex_part;
    this->frames_amount = frames_amount;

    sf::Vector2i current_possition{};
    int current_index{};
    for(int i=0;i<frames_amount;i++)
    {
        frames.push_back({{assigned_tex_part.position.x + current_possition.x ,assigned_tex_part.position.y + current_possition.y},{size.x,size.y}});

        current_possition.x += size.x;
        current_index++;
        if(current_index == (frames_amount/rows_amount))
        {
            current_possition.y += size.y;
            current_possition.x = assigned_tex_part.position.x;
            current_index = 0;
        }
    }

    this->sprite = new sf::Sprite{*texture};
    this->sprite->setTexture(*texture, true);
    this->sprite->setTextureRect(frames[0]);
}


bool meme::Animatron::Move_check( sf::Time current_time )
{
    std::srand(std::time(NULL));
    int rand_num = std::rand()%20;

    if(current_time < current_tic_time) return false;
    if(rand_num > dificulty) return false;

    current_tic_time += tic_duration;
    current_possition++;

    std::cerr << "TIC: " << current_possition << " " << this->move_path[0] << "\n";

    this->Move();

    return true;
}

void Animatron::Jumpscare ()
{
    sf::Clock jumpscare_clock;

    while(jumpscare_clock.getElapsedTime().asMilliseconds() < 2200)
    {
        int frame_id = jumpscare_clock.getElapsedTime().asMilliseconds()/100;
        sprite->setTextureRect(frames[frame_id]);

        assign_office->assigned_window->clear();
        assign_office->Render();
        assign_office->assigned_window->draw(*sprite);
        assign_office->assigned_window->display();

        if(const std::optional event = assign_office->assigned_window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                assign_office->assigned_window->close();
                return;
            }
        }
    }

}
