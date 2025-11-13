#ifndef MEME_MEME_EXCEPTION_HPP
#define MEME_MEME_EXCEPTION_HPP

#include <string>

namespace meme
{

struct Exception
{
    Exception(std::string details_): details{details_} {};
    void Info() virtual;

protected:
    std::string details{};
};

struct Texture_exception: public Exception
{
    Texture_exception(std::string details_): Exception{details} {};
    void Info() override;
};

}

#endif
