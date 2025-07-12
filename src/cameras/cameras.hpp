#ifndef MEME_CAMERAS_H
#define MEME_CAMERAS_H

#include"../system/scene.hpp"
#include"camera.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Cameras: public Scene
{
public:
    Cameras(std::string tex_path, sf::Vector2i size, std::vector<std::vector<int>> cam_val = {{}});

    void Cameras_setup(std::vector<std::vector<int>> cam_val);
    void Cameras_setup(std::vector<std::vector<int>> cam_val, std::vector<sf::Vector2i> cam_sizes);
    sf::Vector2i standart_size{};
private:
    int actual_possition{};
    std::vector<Camera> cameras_vector{};

    sf::Texture texture{};
    sf::Sprite sprite{texture};
};

}

#endif // MEME_CAMERAS_H
