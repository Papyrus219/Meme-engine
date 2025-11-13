#ifndef MEME_CAMERA_TEXTURE_MANAGER_HPP
#define MEME_CAMERA_TEXTURE_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "../../../../cameras/cameras.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Camera_texture_manager
{
public:
    Camera_texture_manager(std::shared_ptr<Cameras> cameras) noexcept: assigned_cameras{cameras} {};

    void Setup_textures(std::string tex_path, sf::Vector2i camera_size, std::vector<std::vector<int>> &cameras_values);
    void Set_texture_to_sprite(sf::Sprite &sprite);

private:
    sf::Texture cameras_texture{};
    std::shared_ptr<Cameras> assigned_cameras{};
    std::vector< std::map<int,sf::IntRect> > cameras_tex_rects{};

    bool is_tex_set{};
};

}

#endif // MEME_CAMERA_TEXTURE_MANAGER_HPP
