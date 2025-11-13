#ifndef MEME_GRAPHICS_MANAGER_HPP
#define MEME_GRAPHICS_MANAGER_HPP

#include <optional>
#include "./window_manager.hpp"

namespace meme {

/**
 * @todo write docs
 */
class Graphics_manager
{
public:
    Graphics_manager() = default;
    Graphics_manager(sf::Vector2u window_size);
    void Init_window_manager(sf::Vector2u window_size);

    void Render();

private:
    std::optional<Window_manager> windower{};
};

}

#endif // MEME_GRAPHICS_MANAGER_HPP
