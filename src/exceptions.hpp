#ifndef EXCEPTIONS
#define EXCEPTIONS

#include<string>
#include<print>

namespace meme
{

struct Exeption
{
    std::string what_happen{};
    void What_happen();

    Exeption(std::string what_happen): what_happen{what_happen}
    {};
};

struct Camera_Exeption: public Exeption
{
    const int wich_camera;
    const int camera_variant;
    void What_happen();

    Camera_Exeption(std::string what_happen, int wich_camera, int camera_variant): Exeption{what_happen}, wich_camera{wich_camera}, camera_variant{camera_variant}
    {};
};

}
#endif
