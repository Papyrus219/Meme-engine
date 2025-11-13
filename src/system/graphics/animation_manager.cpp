#include "animation_manager.hpp"

using namespace meme;

bool meme::Animation_manager::Start_animation(sf::Texture* tex, sf::Vector2i frame_size_, int frames_amount_, int colums_amount_, int rows_amount_) noexcept
{
    if(this->animation_in_progress) return false;

    this->animation_texture = tex;
    this->frame_size = frame_size_;
    this->frames_amount = frames_amount_;
    this->colums_amount = colums_amount_;
    this->rows_amount = rows_amount_;

    frame_clock.restart();
    this->animation_in_progress = true;

    return true;
}

void meme::Animation_manager::Render_frame(sf::RenderWindow *window) noexcept
{
    if(!animation_in_progress) return;

    sf::Sprite drawer{*animation_texture};
    drawer.setTextureRect( Calculate_texture_rectangle() );
    window->draw(drawer);

    if(frame_clock.getElapsedTime() == frame_duration)
    {
        current_frame++;
        frame_clock.restart();

        if(current_frame == frames_amount)
        {
            Finish_animation();
        }
    }
}

void meme::Animation_manager::Finish_animation() noexcept
{
    animation_in_progress = false;
    frame_clock.reset();
}

sf::IntRect meme::Animation_manager::Calculate_texture_rectangle()
{
    sf::Vector2i possition{};

    possition.x = (current_frame % colums_amount != 0)? (current_frame % colums_amount) - 1 : colums_amount-1 ;
    possition.y = (current_frame % rows_amount != 0)? (current_frame / rows_amount) -1 : rows_amount-1;

    return sf::IntRect{ possition,frame_size };
}
