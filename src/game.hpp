#ifndef GAME
#define GAME

#include<SFML/Graphics.hpp>
#include<optional>
#include<memory>
#include"office/office.hpp"
#include"cameras/cameras.hpp"
#include"scene.hpp"
#include"data handlers/telephone.hpp"
#include"data handlers/time_maneger.hpp"
#include"animatrons/animatron.hpp"

namespace meme
{

class Game
{
public:
    Game(std::string audio_path);

    std::vector<std::pair<sf::RenderWindow*,Scene*>> windows{};
    std::vector<meme::Office> offices{};
    std::vector<meme::Cameras> cameras{};
    std::vector<std::shared_ptr<meme::Animatron>> animatrons{};
    std::vector<sf::Texture> jumpscare_textures{};
    Telephone telephone{};
    std::optional<Time_manager> time_manager;

    void Start_night();
    void End_night();

    bool Is_any_window_open();
    void Resereve_new_window(Scene &scene,std::string window_name, sf::VideoMode window_size);
    void Free_window(int winow_id);

    void Render_windows();
    void Events();
    void Animatron_update();
    void Tic();

private:
    std::vector<bool> stars;
    sf::Time night_dutration{};
};

}

#endif
