#ifndef MEME_OPTIONS_H
#define MEME_OPTIONS_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"volume_manipulator.hpp"
#include"../data handlers/audio_manager.hpp"
#include"../window system/scene.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Sound_options final: public Scene
{
public:

    Sound_options(std::string tex_path, sf::Vector2i size, Audio_manager &telephone);

    void Update();
    void Render() override;
    void Event() override;

    void Setup_buttons_textures(std::string texture_path,sf::Vector2i button_size, int buttons_amount);
    void Setup_buttons_textures(std::string texture_path, std::vector<sf::Vector2i> &button_sizes);
    void Setup_icons_textures(std::string texture_path,sf::Vector2i icon_size, int icons_amount);
    void Setup_icons_textures(std::string texture_path, std::vector<sf::Vector2i> &icon_sizes);

    const sf::Texture* Get_buttons_texture_ptr() {return &buttons_textures;};
    const sf::Texture* Get_icons_texture_ptr() {return &icon_textures;};

    int jumpscare_volume{100};
    int clues_volume{100};
    int efect_volume{100};
    int dialog_volume{100};
    int music_volume{100};

    std::vector<Volume_manipulator> volume_manipulators{};

    std::vector<sf::IntRect> buttons_tex_rectangles{};
    std::vector<sf::IntRect> icons_tex_rectangles{};

private:

    sf::Texture icon_textures{};
    sf::Texture buttons_textures{};

    Audio_manager *assigned_audio_manager{};
};

}

#endif // MEME_OPTIONS_H
