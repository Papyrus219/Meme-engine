#include "parameters.hpp"

using namespace meme;

Parameters::Parameters ( int max_energy): max_energy{max_energy}
{}

Parameters::Parameters ( const Parameters &orginal ): max_energy{orginal.max_energy}
{
    this->energy = max_energy;
}

void Parameters::Start_night()
{
    energy = max_energy;
}

void Parameters::End_night()
{

}

void meme::Parameters::On_notify ( const Event event, const Direction direction )
{
    switch(event)
    {
        case Event::DOOR_CLOSED:
            energy_ussage += 3;
            break;
        case Event::DOOR_OPEN:
            energy_ussage -= 3;
            break;
        case Event::DOOR_LIGHT_UP:
            energy_ussage += 1;
            break;
        case Event::DOOR_LIGHT_DOWN:
            energy_ussage -= 1;
            break;
        case Event::CAMERA_OPEN:
            energy_ussage += 2;
            break;
        case Event::CAMERA_CLOSED:
            energy_ussage -= 2;
            break;
    }
}
