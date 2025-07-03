#include "button.hpp"
#include"../exceptions.hpp"

using namespace meme;

Button::Button(sf::Texture &texture, sf::Vector2f possition, sf::Vector2i size, std::vector<std::function<void()>> states_functions): possition{possition}, states_functions{states_functions}
{
    this->texture_ptr = &texture;

    this->sprite.setTexture(texture,true);
    this->sprite.setPosition(possition);

    for(int i=0;i<states_functions.size();i++)
    {
        this->sprite_variants.push_back({{size.x*i,0}, {size.x,size.y}});
    }
    this->sprite.setTextureRect(sprite_variants[0]);
}

Button::Button(const Button &orginal)
{
    this->sprite_variants = orginal.sprite_variants;
    this->states_functions = orginal.states_functions;

    this->size = orginal.size;
    this->state = orginal.state;

    this->texture_ptr = orginal.texture_ptr;
    this->sprite.setTexture(*this->texture_ptr,true);
    this->sprite.setTextureRect(this->sprite_variants[0]);
}

Button::Button(Button &&orginal)
{
    this->sprite_variants = orginal.sprite_variants;
    this->states_functions = orginal.states_functions;

    this->size = orginal.size;
    this->state = orginal.state;

    this->texture_ptr = orginal.texture_ptr;
    this->sprite.setTexture(*this->texture_ptr,true);
    this->sprite.setTextureRect(this->sprite_variants[0]);
}

bool Button::Clicked(sf::Vector2f Mouse_pos)
{
    if(sprite.getGlobalBounds().contains(Mouse_pos))
    {
        state++;
        if(state >= states_functions.size())
            state = 0;

        states_functions[state]();
        sprite.setTextureRect(sprite_variants[state]);

        return true;
    }

    return false;
}
