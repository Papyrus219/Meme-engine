#ifndef MEME_MEME_EXCEPTION_HPP
#define MEME_MEME_EXCEPTION_HPP

#include <string>

namespace meme
{

struct Exception
{
    Exception(std::string details_): details{details_} {};
    virtual void Info();

protected:
    std::string details{};
};

struct Texture_exception: public Exception
{
    Texture_exception(std::string details_): Exception{details_} {};
    void Info() override;
};

struct Camera_exception: public Exception
{
    Camera_exception(std::string details_): Exception{details_} {};
    void Info() override;
};

}

#endif
