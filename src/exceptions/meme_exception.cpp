#include "./meme_exception.hpp"
#include <iostream>

void meme::Exception::Info()
{
    std::cerr << "Exeption happen: " << details << "\n";
}

void meme::Texture_exception::Info()
{
    std::cerr << "Texture exeption happen: " << details << "\n";
}
