#ifndef MEME_MENU_H
#define MEME_MENU_H

#include<functional>
#include"../window system/scene.hpp"

namespace meme
{
    class Game;

/**
 * @brief Class wich represent menu open on start of the game.
 */
class Menu final: public  Scene
{
public:
    Menu(std::string tex_path, sf::Vector2i size, Game &game);

    void Make_buttons ( std::string button_tex_path, sf::Vector2i button_size, sf::Vector2f possition );
    void Make_buttons ( std::string button_tex_path, std::vector<sf::Vector2i> button_sizes, std::vector<sf::Vector2f> possitions );

    void Render() override;
    void Event() override;

    void New_game();
    void Continue(){};
    void Custom_night(){};
    void Options();
    void Exit();

protected:
    sf::Vector2i window_size{};

    sf::Texture buttons_textures;
    std::vector<sf::Sprite> buttons_sprites;
    std::vector<void(Menu::*)()> buttons_functions{};

    Game *assigned_game{};
};

}

#endif // MEME_MENU_H
