#ifndef EXCEPTIONS
#define EXCEPTIONS

#include<string>

namespace meme
{

struct Exeption
{
    std::string what_happen{};

    Exeption(std::string what_happen): what_happen{what_happen}
    {};
};

}

#endif
