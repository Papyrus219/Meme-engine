#ifndef MEME_TEXTURES_MANAGER_HPP
#define MEME_TEXTURES_MANAGER_HPP

#include <optional>
#include "./implementation/background_texture_manager.hpp"
#include "./implementation/camera_texture_manager.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Textures_manager
{
public:
    void Init_background_manager();
    void Init_cameras_manager(std::shared_ptr<Cameras> cameras);

    void Setup_background_textures(std::string tex_path, int backgrounds_amount, sf::Vector2i background_size, std::vector<Scene> scenes);
    void Setup_cameras_textures(std::string tex_path, sf::Vector2i camera_size, std::vector<std::vector<int>> &cameras_values);

    void Set_background_texture_to_sprite(sf::Sprite &sprite, Scene scene_to_set);
    void Set_camera_texture_to_sprite(sf::Sprite &sprite);

private:

    std::optional<Background_texture_manager> background_manager{};
    std::optional<Camera_texture_manager> cameras_manager{};
};

}

#endif // MEME_TEXTURES_MANAGER_HPP
