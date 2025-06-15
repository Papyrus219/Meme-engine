#include"game.hpp"
using namespace meme;

std::pair<sf::RenderWindow *, int> Game::Resereve_new_window ( std::string window_name, sf::VideoMode window_size )
{
    sf::RenderWindow *tmp_window;
    tmp_window = new sf::RenderWindow;
    tmp_window->create(window_size,window_name);

    windows.push_back(tmp_window);

    return {tmp_window, windows.size()-1};
}

void Game::Free_memory(int &window_id)
{
    delete windows[window_id];
    windows[window_id] = nullptr;
    windows.erase(windows.begin() + window_id);
    window_id = 0;
}
