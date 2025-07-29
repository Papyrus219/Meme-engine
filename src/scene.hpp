#ifndef MEME_SCENE_H
#define MEME_SCENE_H

#include<SFML/Graphics.hpp>

namespace meme {

/**
 * Basic abstract class, exist to can better handle window assign.
 */
struct Scene
{
public:
    virtual void Render() = 0;
    virtual void Event() = 0;

    sf::RenderWindow *assigned_window;
    int window_id;
};

}

#endif // MEME_SCENE_H
