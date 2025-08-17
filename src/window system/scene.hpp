#ifndef MEME_SCENE_H
#define MEME_SCENE_H

#include<SFML/Graphics.hpp>

namespace meme {

/**
 * Basic abstract class, exist to can better handle window assign.
 */

struct Window_manager;

struct Scene
{
public:
    void Assign_window_manager(Window_manager &window_manager);

    virtual void Render() = 0;
    virtual void Event() = 0;
    virtual void Close();

    sf::RenderWindow *assigned_window;
    int window_id;

protected:
    Window_manager *assign_windows_manager{};
};

}

#endif // MEME_SCENE_H
