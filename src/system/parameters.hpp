#ifndef MEME_PARAMETERS_H
#define MEME_PARAMETERS_H

#include<SFML/System.hpp>
#include<vector>

namespace meme {

/**
 * @todo write docs
 */
class Parameters
{

    void Tic();

    int Get_actual_night() {return actual_night;};
    int Get_actual_energy() {return energy;};
    bool If_hour_passed();
    bool If_night_passed();

    sf::Clock night_clock;

private:
    int energy;
    int energy_ussage;

    int actual_night;
    sf::Time night_dutration;
    sf::Time tic_durration;
    std::vector<bool> stars;
};

}

#endif // MEME_PARAMETERS_H
