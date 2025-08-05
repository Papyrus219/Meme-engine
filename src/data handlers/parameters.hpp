#ifndef MEME_PARAMETERS_H
#define MEME_PARAMETERS_H

#include<SFML/System.hpp>
#include<vector>
#include"../event system/observer.hpp"

namespace meme {

/**
 * @todo write docs
 */
struct Parameters: public Observer
{
    Parameters(int max_energy);
    Parameters(const Parameters &orginal);

    void Tic();
    void Start_night();
    void End_night();

    void On_notify ( const Event event, const Direction direction ) override;

    const int max_energy;
    int energy{max_energy};
    int energy_ussage{};
};

}

#endif // MEME_PARAMETERS_H
