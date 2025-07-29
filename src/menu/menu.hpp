#ifndef MEME_MENU_H
#define MEME_MENU_H

#include"menu_button.hpp"

namespace meme
{

/**
 * Class wich represent menu open on start of the game.
 */
class Menu
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

    std::vector<Menu_button> option_buttons{};
    sf::RenderWindow *assigned_window;
    int window_id;

protected:
    sf::Texture texture{};
    sf::Sprite sprite{texture};
    sf::Vector2i size{};

    std::vector<sf::Texture> button_textures;

};

}

#endif // MEME_MENU_H
