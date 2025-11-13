#include "window_manager.hpp"

using namespace meme;

sf::RenderWindow * meme::Window_manager::Get_window_for_scene(Scene wanted_scene)
{
    for(auto &[window,scene] : windows)
    {
        if(scene == wanted_scene)
        {
            return window;
        }
    }

    return nullptr;
}

void meme::Window_manager::Assigned_window_to_scene(Scene new_scene)
{
    for(auto &[window,scene] : windows)
    {
        if(scene == new_scene) return;
        if(scene == Scene::none)
        {
            windows.push_back( {nullptr,new_scene} );
            windows.back().first = new sf::RenderWindow{};

            windows.back().first->setSize( {windows_size.x,windows_size.y} );
            windows.back().first->setTitle(Get_string_for_scene(new_scene));

            return;
        }
    }

    windows.push_back( {nullptr,new_scene} );
    windows.back().first = new sf::RenderWindow{};

    windows.back().first->setSize( {windows_size.x,windows_size.y} );
    windows.back().first->setTitle(Get_string_for_scene(new_scene));
}

void meme::Window_manager::Remove_window_from_scene(Scene old_scene)
{
    for(auto it = windows.begin();it != windows.end(); it++)
    {
        auto &[window,scene] = *it;
        if(scene == old_scene)
        {
            delete window;
            window = nullptr;
            scene = Scene::none;
            windows.erase(it);

            return;
        }
    }
}
