#ifndef MEME_MENU_H
#define MEME_MENU_H

#include"menu_button.h"

namespace meme
{

/**
 * Class wich represent menu open on start of the game.
 */
class Menu
{
    Menu(std::string tex_path, std::string button_tex_path, int button_amount, sf::Vector2f button_size);
    Menu(std::string tex_path, std::string button_tex_path, int button_amount, std::vector<sf::Vector2f> button_sizes);

    void New_game();
    void Continue();
    void Custom_night();
    void Options();
    void Exit();

    std::vector<Menu_button> option_buttons{};
    sf::RenderWindow *assigned_window;
    int window_id;
};

}

#endif // MEME_MENU_H
