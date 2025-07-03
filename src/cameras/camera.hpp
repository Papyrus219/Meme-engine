#ifndef CAMERA_H
#define CAMERA_H

#include<SFML/Graphics.hpp>
#include<map>

class Animatron;

namespace meme
{

/**
 * @todo write docs
 */
class Camera
{
public:
    Camera(sf::Texture &texture_source, sf::IntRect texture_fragment, sf::Vector2i size, std::vector<int> variants_val);
    Camera(const Camera &orginal);
    Camera(Camera &&orginal);
    ~Camera();

    sf::Texture *texture_ptr;
    sf::Vector2f size;

    static int get_cameras_amount();
    sf::IntRect Get_camera();
    void Move_in(Animatron anim);
    void Move_out(Animatron anim);

private:
    int camera_id;
    int actual_variant;
    std::map<int,sf::IntRect> variants;
    static int cameras_amount;
};

}

#endif // CAMERA_H
