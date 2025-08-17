#include "window_manager.hpp"

using namespace meme;

void Window_manager::Resereve_new_window ( Scene &scene, std::string window_name, sf::VideoMode window_size )
{
    scene.Assign_window_manager(*this);

    for(int i=0;i<windows.size();i++)
    {
        if(windows[i].first == nullptr)
        {
            windows[i].first = new sf::RenderWindow;
            windows[i].first->create(window_size,window_name);
            windows[i].second = &scene;
            scene.assigned_window = windows[i].first;
            scene.window_id = i;

            return;
        }
    }

    windows.push_back({new sf::RenderWindow, &scene});
    windows[windows.size()-1].first->create(window_size,window_name);
    scene.assigned_window = windows[windows.size()-1].first;
    scene.window_id = windows.size()-1;

    return;
}

void Window_manager::Free_window(int window_id)
{
    delete windows[window_id].first;
    windows[window_id].second->assigned_window = nullptr;
    windows[window_id].second->window_id = -1;
    windows[window_id] = {nullptr,nullptr};
}

bool Window_manager::Is_any_window_open()
{
    for(auto &[window,scene] : windows)
        if(window != nullptr)
            return true;

    return false;
}

void Window_manager::Render_windows()
{
    for(auto &[window,scene] : windows)
        if(window != nullptr)
        {
            window->clear();
            scene->Render();
            window->display();
        }
}

void Window_manager::Events()
{
    for(int i=0;i<windows.size();i++)
    {
        auto &[window,scene] = windows[i];

        if(window != nullptr)
        {
            scene->Event();
            if(!window->isOpen())
                Free_window(i);
        }
    }
}
