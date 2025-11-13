#ifndef MEME_WINDOW_MANAGER_HPP
#define MEME_WINDOW_MANAGER_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "./scenes.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Window_manager
{
public:
    Window_manager(sf::Vector2u window_size): windows_size{window_size} {};

    void Assigned_window_to_scene(Scene new_scene);
    void Remove_window_from_scene(Scene old_scene);

    sf::RenderWindow* Get_window_for_scene(Scene wanted_scene);
private:
    std::vector< std::pair<sf::RenderWindow*, Scene> > windows{};
    sf::Vector2u windows_size{};

};

}

#endif // MEME_WINDOW_MANAGER_HPP
