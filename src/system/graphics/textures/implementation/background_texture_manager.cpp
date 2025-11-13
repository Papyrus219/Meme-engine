#include "background_texture_manager.hpp"

using namespace meme;

void meme::Background_texture_manager::Setup_textures(std::string tex_path, int backgrounds_amount_, sf::Vector2i background_size, std::vector<Scene> scenes)
{
    if( !background_textures.loadFromFile(tex_path) )
    {
        throw meme::Texture_exception{"Invalid background texture path."};
    }
    backgrounds_amount = backgrounds_amount_;

    sf::Vector2i possition{};
    for(int i=0;i<backgrounds_amount;i++)
    {
        background_tex_rects.push_back( { {possition,background_size} ,scenes[i]} );

        possition.x += background_size.x;
    }

    is_tex_set = true;
}

void meme::Background_texture_manager::Set_texture_to_sprite(sf::Sprite& sprite, Scene scene_to_set)
{
    if(!is_tex_set)
    {
        throw meme::Texture_exception{"Background textures not set."};
    }

    for(int i=0;i<backgrounds_amount;i++)
    {
        auto [rect,scene] = background_tex_rects[i];
        if(scene == scene_to_set)
        {
            sprite.setTexture(background_textures);
            sprite.setTextureRect(rect);

            return;
        }
    }

    throw meme::Texture_exception{"Missing background texutre for: " + Get_string_for_scene(scene_to_set) + "." };
}
