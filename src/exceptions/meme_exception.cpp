#include "./meme_exception.hpp"
#include <iostream>

void meme::Exception::Info()
{
    std::cerr << "Execption happen: " << details << "\n";
}

void meme::Texture_exception::Info()
{
    std::cerr << "Texture exception happen: " << details << "\n";
}

void meme::Camera_exception::Info()
{
    std::cerr << "Cameras exception happen: " << details << "\n";
}
