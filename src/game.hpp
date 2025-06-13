#ifndef GAME
#define GAME

#include<SFML/Graphics.hpp>
#include"office/office.hpp"

namespace meme
{

struct Game
{
    sf::RenderWindow *window;
    std::vector<office> offices;

    void Render_office();
};

}

#endif
