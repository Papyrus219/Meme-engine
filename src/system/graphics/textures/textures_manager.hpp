#ifndef MEME_TEXTURES_MANAGER_HPP
#define MEME_TEXTURES_MANAGER_HPP

#include <SFML/Graphics.hpp>
#include "../scenes.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Textures_manager
{
public:
    void Setup_backgrounds_textures(std::string tex_path, int backgrounds_amount, sf::Vector2i background_size, std::vector<Scene> scenes);
    void Set_background_texture_to_sprite(sf::Sprite &sprite, Scene scene_to_set);

private:

    int backgrounds_amount{};
    std::vector< std::pair<sf::IntRect, Scene> > background_tex_rects{};
    bool is_background_tex_set{};

    sf::Texture background_textures{};
};

}

#endif // MEME_TEXTURES_MANAGER_HPP
