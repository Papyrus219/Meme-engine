#include "cameras.hpp"
#include "../exceptions.hpp"
#include<iostream>

using namespace meme;

Cameras::Cameras(std::string tex_path, sf::Vector2i size, std::vector<std::vector<int>> cam_val)
{
    if(!texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load cameras textures!"};
    }

    sprite.setTexture(texture,true);
    standart_size = size;

    actual_possition = 0;

    if(cam_val.size() > 1)
    {
        Cameras_setup(std::move(cam_val));
        sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
    }

    if(!font.openFromFile("../../fonts/ARIAL.TTF"))
    {
        throw Exeption{"Failed to load camera font."};
    }
    actual_camera.setFont(font);
    actual_camera.setFillColor(sf::Color::Green);
    actual_camera.setPosition({900,10});
    actual_camera.setCharacterSize(24);

}

Cameras::Cameras ( const Cameras& orginal )
{
    this->standart_size = orginal.standart_size;
    this->actual_possition = orginal.actual_possition;
    for(auto camera : orginal.cameras_vector)
        this->cameras_vector.push_back(camera);
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
}

Cameras::Cameras ( Cameras && orginal )
{
    this->standart_size = orginal.standart_size;
    this->actual_possition = orginal.actual_possition;
    for(auto camera : orginal.cameras_vector)
        this->cameras_vector.push_back(camera);
    this->texture = orginal.texture;
    this->sprite.setTexture(this->texture,true);
}

void Cameras::Render()
{
    sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
    assigned_window->draw(sprite);
    assigned_window->draw(camera_panel.sprite);
    for(auto hitbox : camera_panel.hitboxes)
    {
        assigned_window->draw(hitbox);
    }

    actual_camera.setString("Cam " + std::to_string(actual_possition+1));
    assigned_window->draw(actual_camera);
}

void Cameras::Event()
{
    while (const std::optional event = assigned_window->pollEvent())
    {
        if(event->is<sf::Event::MouseButtonPressed>())
        {

            sf::Vector2f mose_pos{sf::Mouse::getPosition(*assigned_window)};
            for(int i=0;i<camera_panel.hitboxes.size();i++)
            {
                if(camera_panel.hitboxes[i].getGlobalBounds().contains(mose_pos))
                {
                    actual_possition = i;
                    break;
                }
            }
        }
        else if(event->is<sf::Event::Closed>())
        {
            assigned_window->close();
            return;
        }
    }
}

Camera* Cameras::Get_camera_ptr ( int index )
{
    if(index < 0) return nullptr;
    if(index >= cameras_vector.size()) return nullptr;

    return &(cameras_vector[index]);
}

void Cameras::Cameras_setup(std::vector<std::vector<int>> &&cam_val)
{
    for(int cam_set = 0;cam_set < cam_val.size(); cam_set++)
    {
        cameras_vector.push_back(Camera{texture, {{0,standart_size.y*cam_set},{standart_size.x*static_cast<int>(cam_val[cam_set].size()),standart_size.y}}, standart_size, cam_val[cam_set]});
    }

    sprite.setTextureRect(cameras_vector[actual_possition].Get_camera());
}

void Cameras::Cameras_setup(std::vector<std::vector<int>> &&cam_val, std::vector<sf::Vector2i> &&cam_sizes)
{
    if(cam_val.size() != cam_sizes.size()) throw Exeption{"Cam_values size don't match cam_sizes size."};

    sf::Vector2i current_possition{};

    for(int cam_set = 0;cam_set < cam_val.size(); cam_set++)
    {
        cameras_vector.push_back(Camera{texture, {{0,current_possition.y},{cam_sizes[cam_set].x*static_cast<int>(cam_val[cam_set].size()),cam_sizes[cam_set].y}}, cam_sizes[cam_set], cam_val[cam_set]});

        current_possition += cam_sizes[cam_set];
    }
}

void Cameras::Camera_panel_setup ( std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, sf::Vector2f hit_box_size )
{
    if(!camera_panel.texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load texture of camera_panel."};
    }
    camera_panel.sprite.setTexture(camera_panel.texture,true);
    camera_panel.sprite.setPosition(possition);
    camera_panel.sprite.setTextureRect({{0,0},{size}});

    for(int i=0;i<hit_box_possitions.size();i++)
    {
        camera_panel.hitboxes.push_back(sf::RectangleShape{hit_box_size});
        camera_panel.hitboxes[i].setFillColor(sf::Color::Transparent);
        camera_panel.hitboxes[i].setPosition({possition.x+hit_box_possitions[i].x , possition.y+hit_box_possitions[i].y});
    }
}

void Cameras::Camera_panel_setup (std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, std::vector<sf::Vector2f> hit_box_sizes)
{
    if(!camera_panel.texture.loadFromFile(tex_path))
    {
        throw Exeption{"Failed to load texture of camera_panel."};
    }
    camera_panel.sprite.setTexture(camera_panel.texture,true);
    camera_panel.sprite.setPosition(possition);
    camera_panel.sprite.setTextureRect({{0,0},{size}});

    for(int i=0;i<hit_box_possitions.size();i++)
    {
        camera_panel.hitboxes.push_back(sf::RectangleShape{hit_box_sizes[i]});
        camera_panel.hitboxes[i].setFillColor(sf::Color::Transparent);
        camera_panel.hitboxes[i].setPosition({possition.x+hit_box_possitions[i].x , possition.y+hit_box_possitions[i].y});
    }
}
