#include "menu.hpp"
#include"../exceptions.hpp"

using namespace meme;

Menu::Menu ( std::string tex_path, sf::Vector2i size ): Scene{tex_path,size}
{

}

void meme::Menu::Make_buttons ( std::string button_tex_path, sf::Vector2i button_size, sf::Vector2f possition )
{
    buttons_sprites.clear();
    buttons_functions.clear();

    if(!buttons_textures.loadFromFile(button_tex_path))
    {
        throw Exeption{"Failed to load menu buttons texture!"};
    }

    sf::Vector2i texture_possition{};

    for(int i=0;i<5;i++)
    {
        buttons_sprites.emplace_back(buttons_textures);
        buttons_sprites[i].setTexture(buttons_textures,true);
        buttons_sprites[i].setTextureRect({texture_possition,button_size});
        texture_possition.y += button_size.y;

        buttons_sprites[i].setPosition(possition);
        possition.y += button_size.y + 10;
    }

    buttons_functions.push_back(&Menu::New_game);
    buttons_functions.push_back(&Menu::Continue);
    buttons_functions.push_back(&Menu::Custom_night);
    buttons_functions.push_back(&Menu::Options);
    buttons_functions.push_back(&Menu::Exit);
}

void Menu::Event()
{
    while (const std::optional event = assigned_window->pollEvent())
    {
        if(event->is<sf::Event::MouseButtonPressed>())
        {
            sf::Vector2i Mouse_possition = sf::Mouse::getPosition(*assigned_window);

            for(int i=0;i<5;i++)
            {
                if(buttons_sprites[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(Mouse_possition)))
                {
                    (this->*buttons_functions[i])();
                    break;
                }
            }
        }
        else if (event->is<sf::Event::Closed>())
        {
            assigned_window->close();
            return;
        }
    }
}
