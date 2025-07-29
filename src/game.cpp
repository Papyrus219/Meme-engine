#include"game.hpp"
using namespace meme;

Game::Game(std::string audio_path): telephone{audio_path}
{
}

void Game::Render_windows()
{
    for(auto &[window,scene] : windows)
        if(window != nullptr)
        {
            window->clear();
            scene->Render();
            window->display();
        }
}

void Game::Events()
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

void Game::Animatron_update()
{
    sf::Time current_time = time_manager->tic_clock.getElapsedTime();

    for(auto animatron : animatrons)
    {
        animatron->Move(current_time);
    }

}

void Game::Tic()
{
    if(time_manager->tic_clock.getElapsedTime() < time_manager->final_tic_duration) return;

    time_manager->current_night_time += time_manager->tic_clock.getElapsedTime();

    if((time_manager->current_night_time / time_manager->night_duration) > time_manager->current_hour) time_manager->current_hour++;

    if(time_manager->current_hour >= 6) End_night();
}


void Game::Start_night()
{
    for(auto &office : offices)
    {
        office.Start_night();
        if(office.parameters_ptr)
        {
            office.parameters_ptr->Start_night();
        }
    }

    time_manager->tic_clock.start();
}

void meme::Game::End_night()
{
    for(auto &office : offices)
    {
        if(office.parameters_ptr)
        {
            office.parameters_ptr->End_night();
        }
    }

    time_manager->tic_clock.stop();
}

void Game::Resereve_new_window ( Scene &scene, std::string window_name, sf::VideoMode window_size )
{
    sf::RenderWindow *tmp_window;
    tmp_window = new sf::RenderWindow;
    tmp_window->create(window_size,window_name);

    for(int i=0;i<windows.size();i++)
    {
        if(windows[i].first == nullptr)
        {
            windows[i].first = tmp_window;
            windows[i].second = &scene;
            scene.assigned_window = tmp_window;
            scene.window_id = i;

            return;
        }
    }

    windows.push_back({tmp_window, &scene});
    scene.assigned_window = tmp_window;
    scene.window_id = windows.size()-1;

    return;
}

void Game::Free_window(int window_id)
{
    delete windows[window_id].first;
    windows[window_id].second->assigned_window = nullptr;
    windows[window_id].second->window_id = -1;
    windows[window_id] = {nullptr,nullptr};
}

bool Game::Is_any_window_open()
{
    for(auto &[window,scene] : windows)
        if(window != nullptr)
            return true;

    return false;
}
