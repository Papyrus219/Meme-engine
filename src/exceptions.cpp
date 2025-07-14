#include"exceptions.hpp"
using namespace meme;

void Exeption::What_happen()
{
    std::print("{}/n",what_happen);
}

void Camera_Exeption::What_happen()
{
    std::print("{} Camera id:{}. Camera variant:{}.\n",what_happen,wich_camera,camera_variant);
}
