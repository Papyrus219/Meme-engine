#ifndef GAME
#define GAME


#include<optional>
#include<memory>
#include"office/office.hpp"
#include"office/telephone.hpp"
#include"cameras/cameras.hpp"
#include"menu/menu.hpp"
#include"menu/sound_options.hpp"
#include"data handlers/audio_manager.hpp"
#include"data handlers/time_maneger.hpp"
#include"animatrons/animatron.hpp"
#include"window system/window_manager.hpp"
#include"data handlers/saver.hpp"

namespace meme
{

class Game
{
public:
    Game(std::string audio_path);

    std::vector<meme::Office> offices{};
    std::vector<meme::Cameras> cameras{};
    std::vector<std::shared_ptr<meme::Animatron>> animatrons{};
    std::vector<sf::Texture> jumpscare_textures{};
    Audio_manager audio_manager{};
    Window_manager window_manager;
    std::optional<Time_manager> time_manager;
    std::optional<meme::Menu> menu{};
    std::optional<meme::Sound_options> sound_options{};
    std::optional<meme::Telephone> telephone{};
    std::optional<meme::Saver> saver{};
    bool game_loop{true};

    void Start_night();
    void End_night();

    void Save_save();
    void Load_save();

    void Animatron_update();
    void Tic();

private:
    std::vector<bool> stars{false,false,false};
    sf::Time night_dutration{};
};

}

#endif
