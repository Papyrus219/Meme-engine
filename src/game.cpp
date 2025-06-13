#include"game.hpp"
using namespace meme;

void meme::Game::Render_office()
{
    window->clear();

    for(auto office : offices)
    {
        window->draw(office.sprite);

        for(auto door_button : office.door_buttons)
        {
            window->draw(*door_button.Get_sprite_ptr());
        }
        for(auto light_button : office.light_buttons)
        {
            window->draw(*light_button.Get_sprite_ptr());
        }
        for(auto door : office.doors)
        {
            window->draw(*door.Get_sprite_ptr());
        }
    }
}
