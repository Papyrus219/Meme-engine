#ifndef GAME
#define GAME

#include<SFML/Graphics.hpp>
#include"office/office.hpp"
#include"cameras/cameras.hpp"
#include"system/scene.hpp"
#include"system/telephone.hpp"

namespace meme
{

class Game
{
public:
    Game(std::string audio_path);

    std::vector<std::pair<sf::RenderWindow*,Scene*>> windows{};
    std::vector<meme::Office> offices{};
    std::vector<meme::Cameras> cameras{};
    std::vector<sf::Texture> jumpscare_textures{};
    Telephone telephone{};

    bool Is_any_window_open();
    void Render_windows();
    void Resereve_new_window(Scene &scene,std::string window_name, sf::VideoMode window_size);
    void Free_window(int winow_id);
    void Events();

private:
    void Tic();
};

}

#endif
