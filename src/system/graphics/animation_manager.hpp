#ifndef MEME_ANIMATION_MANAGER_HPP
#define MEME_ANIMATION_MANAGER_HPP

#include <SFML/Graphics.hpp>

namespace meme
{

/**
 * @todo write docs
 */
class Animation_manager
{
public:
    bool Start_animation(sf::Texture *tex, sf::Vector2i frame_size_, int frames_amount_, int colums_amount_, int rows_amount_) noexcept;
    void Render_frame(sf::RenderWindow *window) noexcept;

    bool Is_animation_in_progres() noexcept {return animation_in_progress;};

private:
    void Finish_animation() noexcept;
    sf::IntRect Calculate_texture_rectangle();

    bool animation_in_progress{};
    int frames_amount{};
    int current_frame{};

    int rows_amount{};
    int colums_amount{};

    sf::Vector2i frame_size{};
    sf::Texture* animation_texture{};

    sf::Time frame_duration {sf::microseconds(83'333)};
    sf::Clock frame_clock{};
};

}

#endif // MEME_ANIMATION_MANAGER_HPP
