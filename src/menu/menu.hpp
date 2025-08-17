#ifndef MEME_MENU_H
#define MEME_MENU_H

#include"../window system/scene.hpp"

namespace meme
{

/**
 * Class wich represent menu open on start of the game.
 */
class Menu: public Scene
{
public:
    Menu(std::string tex_path, sf::Vector2i size);

    void Make_buttons ( std::string button_tex_path, int button_amount, sf::Vector2i button_size, sf::Vector2f possition );
    void Make_buttons ( std::string button_tex_path, int button_amount, std::vector<sf::Vector2i> button_sizes, std::vector<sf::Vector2f> possitions );

    void New_game();
    void Continue();
    void Custom_night();
    void Options();
    void Exit();

protected:
    sf::Texture background_texture{};
    sf::Sprite background_sprite{background_texture};
    sf::Vector2i background_size{};

    sf::Texture button_texture;
    std::vector<sf::Sprite> buttons_sprites;
};

}

#endif // MEME_MENU_H
