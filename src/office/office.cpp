#include"office.hpp"
#include"../cameras/cameras.hpp"
#include"../exceptions.hpp"
#include"../window system/window_manager.hpp"
using namespace meme;

Office::Office(std::string tex_path, sf::Vector2i size): Scene{tex_path,size}
{
    view = sf::View{{size.x*0.5f, size.y*0.5f} ,{size.x*0.5f, size.y*1.0f}};
}

Office::Office(const Office &orginal): Scene{orginal}
{
    for(auto door : orginal.doors)
        this->doors.push_back(door);
    for(auto button : orginal.buttons)
        this->buttons.push_back(button);
}

Office::Office(Office &&orginal): Scene{orginal}
{
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


    assigned_window->draw(*background_sprite);
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

void Office::Start_night()
{
    for(auto door : doors)
    {
        door.Light_down();
        door.Open();
    }
}

void Office::Event()
{
    while (const std::optional event = assigned_window->pollEvent())
    {
        if(event->is<sf::Event::MouseButtonPressed>())
        {
            if(!power_off)
            {
                sf::Vector2f MousePos{sf::Mouse::getPosition(*assigned_window)};
                for(auto &button : buttons)
                {
                    button.Clicked(MousePos);
                }
            }
        }
        else if (event->is<sf::Event::Closed>())
        {
            Close();
            return;
        }
    }
}

void meme::Office::Close()
{
    if(assigned_window != nullptr)
    {
        assign_windows_manager->Free_window(window_id);
    }

    assign_windows_manager = nullptr;

    for(auto &camera : assign_cameras)
        camera->Close();
}

void Office::Load_button_textures ( std::string path, int amount )
{
    button_textures.clear();

    for(int i=1;i<=amount;i++)
    {
        button_textures.push_back(sf::Texture{});
        if(!button_textures[i-1].loadFromFile(path + "/button" + std::to_string(i) + ".png"))
        {
            throw Exeption{"Failed to load button texture number" + std::to_string(i) + "!"};
        }
    }
}

void Office::Load_door_textures ( std::string path, int amount )
{
    door_textures.clear();

    for(int i=1;i<=amount;i++)
    {
        door_textures.push_back(sf::Texture{});
        if(!door_textures[i-1].loadFromFile(path + "/door" + std::to_string(i) + ".png"))
        {
            throw Exeption{"Failed to load door texture number" + std::to_string(i) + "!"};
        }
    }
}

void meme::Office::Assign_cameras ( Cameras &camera )
{
    assign_cameras.push_back(&camera);
}

void meme::Office::Unsign_cameras ( Cameras &camera )
{
    for(int i=0;i<assign_cameras.size();i++)
    {
        if(&camera == assign_cameras[i])
        {
            assign_cameras.erase(assign_cameras.begin() + 1);
            return;
        }

    }
}
