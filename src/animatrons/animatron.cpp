#include "animatron.hpp"

using namespace meme;

meme::Animatron::Animatron(std::string jumpscare_tex_path)
{
    if(!jumpscare_tex.loadFromFile(jumpscare_tex_path))
    {
        std::exit(1);
    }
}
