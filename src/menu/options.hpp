#ifndef MEME_OPTIONS_H
#define MEME_OPTIONS_H
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include"volume_manipulator.hpp"
#include"../data handlers/audio_manager.hpp"
#include"menu_button.hpp"
#include"../window system/scene.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Options: public Scene
{
public:

    Options(std::string tex_path, sf::Vector2i size, Audio_manager &telephone);
    void Setup_sound_manipulators(std::string icon_tex_path, std::string buttons_tex_path, std::vector< std::pair<sf::IntRect,int> > buttons_rect, std::vector< std::pair<sf::IntRect,int> > icon_rects);

    void Update();
    void Render() override;
    void Event() override;

private:

    std::vector<Volume_manipulator> volume_manipulators{};

    int jumpscare_volume{100};
    int clues_volume{100};
    int efect_volume{100};
    int dialog_volume{100};
    int music_volume{100};

    sf::Texture icon_textures{};
    sf::Texture buttons_textures{};

    sf::Texture background_texture{};
    sf::Sprite background_sprite{background_texture};
    sf::Vector2i size;

    Audio_manager *assigned_audio_manager{};
};

}

#endif // MEME_OPTIONS_H
