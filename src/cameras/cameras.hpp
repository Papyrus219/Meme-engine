#ifndef MEME_CAMERAS_H
#define MEME_CAMERAS_H

#include"../scene.hpp"
#include"camera.hpp"
#include"camera_panel.hpp"

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
    void Camera_panel_setup(std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, sf::Vector2f hit_box_size);
    void Camera_panel_setup(std::string tex_path, sf::Vector2i size, sf::Vector2f possition, std::vector<sf::Vector2i> hit_box_possitions, std::vector<sf::Vector2f> hit_box_sizes);
    void Render() override;
    void Event() override;

    Camera* Get_camera_ptr(int index);

    sf::Vector2i standart_size{};
    Camera_panel camera_panel{};
private:
    int actual_possition{};
    std::vector<Camera> cameras_vector{};

    sf::Texture texture{};
    sf::Sprite sprite{texture};

    sf::Font font{};
    sf::Text actual_camera{font};
};

}

#endif // MEME_CAMERAS_H
