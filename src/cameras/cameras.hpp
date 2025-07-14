#ifndef MEME_CAMERAS_H
#define MEME_CAMERAS_H

#include"../system/scene.hpp"
#include"camera.hpp"

namespace meme {

/**
 * Class to handle cameras window.
 */
class Cameras final: public Scene
{
public:
    Cameras(std::string tex_path, sf::Vector2i size, std::vector<std::vector<int>> cam_val = {{}});
    Cameras(const Cameras &orginal);
    Cameras(Cameras &&orginal);

    void Cameras_setup(std::vector<std::vector<int>> &&cam_val);
    void Cameras_setup(std::vector<std::vector<int>> &&cam_val, std::vector<sf::Vector2i> &&cam_sizes);
    void Render() override;
    void Event() override;
    sf::Vector2i standart_size{};
private:
    int actual_possition{};
    std::vector<Camera> cameras_vector{};

    sf::Texture texture{};
    sf::Sprite sprite{texture};
};

}

#endif // MEME_CAMERAS_H
