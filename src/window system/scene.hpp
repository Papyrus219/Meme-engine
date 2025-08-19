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
    Scene() = default;
    Scene(std::string back_tex_path, sf::Vector2i size);
    Scene(const Scene& orginal);
    Scene(Scene&& orginal);

    void Assign_window_manager(Window_manager &window_manager);

    virtual void Render() = 0;
    virtual void Event() = 0;
    virtual void Close();

    sf::Vector2i window_size;

    sf::RenderWindow *assigned_window{};
    int window_id{};

protected:
    Window_manager *assign_windows_manager{};

    std::optional<sf::Sprite> background_sprite{};
    sf::Texture background_texture{};
};

}

#endif // MEME_SCENE_H
