#ifndef GAME
#define GAME

#include<SFML/Graphics.hpp>
#include"office/office.hpp"

namespace meme
{

class Game
{
public:
    std::vector<sf::RenderWindow*> windows;
    std::vector<meme::office> offices;

    void Game_loop();

private:
    void Tic();
};

}

#endif
