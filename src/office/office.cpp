#include"office.hpp"
#include"../exceptions.hpp"
using namespace meme;

Office::Office(std::string tex_path, sf::Vector2i size): size{size}
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load office texture!\n"};
    }

    this->sprite.setTexture(texture,true);

    view = sf::View{{size.x*0.5f, size.y*0.5f} ,{size.x*0.5f, size.y*1.0f}};
}

Office::Office(const Office &orginal)
{
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
    this->size = orginal.size;

    for(auto door : orginal.doors)
        this->doors.push_back(door);
    for(auto button : orginal.buttons)
        this->buttons.push_back(button);
}

Office::Office(Office &&orginal)
{
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
    this->size = orginal.size;

    for(auto door : orginal.doors)
        this->doors.push_back(door);
    for(auto button : orginal.buttons)
        this->buttons.push_back(button);
}

void Office::Render()
{
    if(assigned_window == nullptr)
    {
        throw Exeption{"Office render error: None window assigned!\n"};
    }

    //assigned_window->setView(view);


    assigned_window->draw(sprite);
    for(auto &door : doors)
    {
        assigned_window->draw(*door.Get_sprite_ptr());
    }
    for(auto &button : buttons)
    {
        assigned_window->draw(*button.Get_sprite_ptr());
    }

    assigned_window->setView(assigned_window->getDefaultView());
}

void Office::Event()
{
    while (const std::optional event = assigned_window->pollEvent())
    {
        if(event->is<sf::Event::MouseButtonPressed>())
        {
            sf::Vector2f MousePos{sf::Mouse::getPosition(*assigned_window)};
            for(auto &button : buttons)
            {
                button.Clicked(MousePos);
            }
        }
        else if (event->is<sf::Event::Closed>())
        {
            assigned_window->close();
            return;
        }
    }
}
