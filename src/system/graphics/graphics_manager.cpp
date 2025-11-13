#include "graphics_manager.hpp"

using namespace meme;

meme::Graphics_manager::Graphics_manager(sf::Vector2u window_size)
{
    Init_window_manager(window_size);
}

void meme::Graphics_manager::Init_window_manager(sf::Vector2u window_size)
{
    windower.emplace(window_size);
}

void meme::Graphics_manager::Render()
{

}
