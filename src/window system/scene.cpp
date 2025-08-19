#include"scene.hpp"
#include"window_manager.hpp"
#include"../exceptions.hpp"

using namespace meme;

void Scene::Assign_window_manager ( Window_manager& window_manager )
{
    assign_windows_manager = &window_manager;
}

void Scene::Close()
{
    if(assigned_window != nullptr)
    {
        assign_windows_manager->Free_window(window_id);
    }

    assign_windows_manager = nullptr;
}

Scene::Scene ( std::string back_tex_path, sf::Vector2i size ): window_size{size}
{
    if(!background_texture.loadFromFile(back_tex_path))
    {
        throw Exeption{"Failed to load background texture!\n"};
    }

    background_sprite.emplace(background_texture);
    background_sprite->setTexture(background_texture,true);
}

Scene::Scene ( const Scene& orginal )
{
    this->background_texture = orginal.background_texture;
    this->background_sprite->setTexture(this->background_texture,true);
    this->window_size = orginal.window_size;
}

Scene::Scene ( Scene && orginal )
{
    this->background_texture = orginal.background_texture;
    this->background_sprite->setTexture(this->background_texture,true);
    this->window_size = orginal.window_size;
}
