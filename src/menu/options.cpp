#include "options.hpp"
#include "../exceptions.hpp"
#include<iostream>

using namespace meme;

Options::Options(std::string tex_path, sf::Vector2i size, Audio_manager& audio_manager): size{size}, assigned_audio_manager{&audio_manager}
{
    if(!background_texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load option texture!\n"};
    }

    background_sprite.setTexture(background_texture,true);
}

void Options::Update()
{
    assigned_audio_manager->Change_volume(jumpscare_volume,clues_volume,efect_volume,dialog_volume,music_volume);
}

void Options::Setup_sound_manipulators ( std::string icon_tex_path, std::string buttons_tex_path, std::vector<std::pair<sf::IntRect, int>> buttons_rects, std::vector<std::pair<sf::IntRect, int>> icons_rects )
{
    if(!icon_textures.loadFromFile(icon_tex_path))
    {
        throw Exeption{"Failed to load icons texture!\n"};
    }
    if(!buttons_textures.loadFromFile(buttons_tex_path))
    {
        throw Exeption{"Failed to load buttons texture!\n"};
    }

    std::vector<int*> setup_vector{&jumpscare_volume,&clues_volume,&efect_volume,&dialog_volume,&music_volume};
    int button_it{},button_counter{},icon_it{},icon_counter{};

    for(int* parameter : setup_vector)
    {
        volume_manipulators.push_back({parameter,buttons_textures,icon_textures,buttons_rects[button_it].first,icons_rects[icon_it].first,{0,0}});

        button_counter++;
        icon_counter++;

        if(button_counter == buttons_rects[button_it].second) button_it++;
        if(icon_counter == icons_rects[icon_it].second) icon_it++;
    }
}

void Options::Render()
{
    assigned_window->draw(background_sprite);

    std::cerr << "AAAAAAAAAAAAA";

    for(auto &manipulator : volume_manipulators)
    {
         manipulator.Render(assigned_window);
    }
}

void Options::Event()
{
    while (const std::optional event = assigned_window->pollEvent())
    {
        if(event->is<sf::Event::MouseButtonPressed>())
        {
            sf::Vector2i mouse_possition = sf::Mouse::getPosition();

            for(auto manipulator : volume_manipulators)
            {
                manipulator.Click(static_cast<sf::Vector2f>(mouse_possition));

                Update();
            }
        }
        else if (event->is<sf::Event::Closed>())
        {
            assigned_window->close();
            return;
        }
    }
}
