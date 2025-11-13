#ifndef MEME_ANIMATRON_HPP
#define MEME_ANIMATRON_HPP

#include <SFML/Graphics.hpp>

namespace meme {

/**
 * @todo write docs
 */
class Animatron
{
public:
    Animatron(std::string jumpscare_tex_path);

    sf::Texture Get_texture() {return jumpscare_tex;};
    int Get_value() {return value;};
private:
    int value{};

    sf::Texture jumpscare_tex{};
};

}

#endif // MEME_ANIMATRON_HPP
