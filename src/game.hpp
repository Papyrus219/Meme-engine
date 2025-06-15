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
    std::pair<sf::RenderWindow*,int> Resereve_new_window(std::string window_name, sf::VideoMode window_size);
    void Free_memory(int &winow_id);

private:
    void Tic();
};

}

#endif
