#include "options.hpp"
#include "../exceptions.hpp"
#include<iostream>

using namespace meme;

Sound_options::Sound_options(std::string tex_path, sf::Vector2i size, Audio_manager& audio_manager): Scene{tex_path,size}, assigned_audio_manager{&audio_manager}
{

}

void Sound_options::Update()
{
    assigned_audio_manager->Change_volume(jumpscare_volume,clues_volume,efect_volume,dialog_volume,music_volume);
}

void Sound_options::Render()
{
    if(assigned_window == nullptr)
    {
        throw Exeption{"Options render error: None window assigned!\n"};
    }

    assigned_window->draw(*background_sprite);

    for(auto &manipulator : volume_manipulators)
    {
         manipulator.Render(assigned_window);
    }
}

void Sound_options::Event()
{
    while (const std::optional event = assigned_window->pollEvent())
    {
        if(event->is<sf::Event::MouseButtonPressed>())
        {
            sf::Vector2i mouse_possition = sf::Mouse::getPosition(*assigned_window);

            for(auto &manipulator : volume_manipulators)
            {
                if(manipulator.Click(static_cast<sf::Vector2f>(mouse_possition))) break;

            }
            Update();
        }
        else if (event->is<sf::Event::Closed>())
        {
            assigned_window->close();
            return;
        }
    }
}

void Sound_options::Setup_buttons_textures ( std::string texture_path, sf::Vector2i button_size, int buttons_amount )
{
    buttons_tex_rectangles.clear();

    if(!buttons_textures.loadFromFile(texture_path))
    {
        throw meme::Exeption{"Failed to load option buttons texure!"};
    }

    sf::IntRect tmp_rect{};
    tmp_rect.size = button_size;

    for(int i=0;i<buttons_amount;i++)
    {
        buttons_tex_rectangles.push_back(tmp_rect);

        tmp_rect.position.x += button_size.x;
    }
}

void Sound_options::Setup_buttons_textures ( std::string texture_path, std::vector<sf::Vector2i>& button_sizes )
{
    buttons_tex_rectangles.clear();

    if(!buttons_textures.loadFromFile(texture_path))
    {
        throw meme::Exeption{"Failed to load option buttons texure!"};
    }

    sf::IntRect tmp_rect{};

    for(int i=0;i<button_sizes.size();i++)
    {
        tmp_rect.size = button_sizes[i];

        buttons_tex_rectangles.push_back(tmp_rect);

        tmp_rect.position.x += button_sizes[i].x;
    }
}

void Sound_options::Setup_icons_textures ( std::string texture_path, sf::Vector2i icon_size, int icons_amount )
{
    icons_tex_rectangles.clear();

    if(!icon_textures.loadFromFile(texture_path))
    {
        throw meme::Exeption{"Failed to load option icons texure!"};
    }

    sf::IntRect tmp_rect{};
    tmp_rect.size = icon_size;

    for(int i=0;i<icons_amount;i++)
    {
        icons_tex_rectangles.push_back(tmp_rect);

        tmp_rect.position.x += icon_size.x;
    }
}

void Sound_options::Setup_icons_textures ( std::string texture_path, std::vector<sf::Vector2i>& icon_sizes )
{
    icons_tex_rectangles.clear();

    if(!icon_textures.loadFromFile(texture_path))
    {
        throw meme::Exeption{"Failed to load icons buttons texure!"};
    }

    sf::IntRect tmp_rect{};

    for(int i=0;i<icon_sizes.size();i++)
    {
        tmp_rect.size = icon_sizes[i];

        icons_tex_rectangles.push_back(tmp_rect);

        tmp_rect.position.x += icon_sizes[i].x;
    }
}
