#ifndef MEME_WINDOW_MANAGER_H
#define MEME_WINDOW_MANAGER_H

#include<SFML/Graphics.hpp>
#include"scene.hpp"

namespace meme
{

/**
 * @todo write docs
 */
struct Window_manager
{
    bool Is_any_window_open();
    void Resereve_new_window(Scene &scene,std::string window_name, sf::VideoMode window_size);
    void Free_window(int window_id);

    void Render_windows();
    void Events();

    std::vector<std::pair<sf::RenderWindow*,Scene*>> windows{};
};

}

#endif // MEME_WINDOW_MANAGER_H
