#include <cstdlib>
#include "animatron.hpp"
#include "../exceptions.hpp"

using namespace meme;

Animatron::Animatron ( int value, std::vector<int> move_path, Cameras &camera_system): value{value}, move_path{move_path}, assign_camera_system{&camera_system}
{}

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

    this->sprite.setTexture(*texture);
    this->sprite.setTextureRect(frames[0]);
}


bool Animatron::Move(Office *office)
{
    std::srand(std::time(NULL));
    int rand_num = std::rand();

    if(rand_num > dificulty) return false;

    if(current_possition >= move_path.size())
    {
        this->Under_door(office);

        return true;
    }

    current_possition++;

    if(current_possition >= 0 && move_path[current_possition] != move_path[current_possition-1])
    {
        auto camera = assign_camera_system->Get_camera_ptr(current_possition-1);
        camera->Move_out(*this);
    }
    auto camera = assign_camera_system->Get_camera_ptr((current_possition));
    camera->Move_in(*this);

    return true;
}

void Animatron::Jumpscare ( Scene* office )
{
    sf::Clock jumpscare_clock;

    while(jumpscare_clock.getElapsedTime().asMilliseconds() < 2200)
    {
        int frame_id = jumpscare_clock.getElapsedTime().asMilliseconds()/100;
        sprite.setTextureRect(frames[frame_id]);

        office->assigned_window->clear();
        office->Render();
        office->assigned_window->draw(sprite);
        office->assigned_window->display();

        if(const std::optional event = office->assigned_window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                office->assigned_window->close();
                return;
            }
        }
    }

}
