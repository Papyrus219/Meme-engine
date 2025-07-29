#ifndef TIME_MANAGER_H
#define TIME_MANAGER_H

#include<SFML/System.hpp>

namespace meme
{

struct Time_manager
{
    Time_manager(int night_duration_min, int final_tic_duration_minisec)
    {
        night_duration = sf::seconds(night_duration_min*60);
        final_tic_duration = sf::milliseconds(final_tic_duration_minisec);
    }

    sf::Clock tic_clock;
    sf::Time night_duration{};
    sf::Time final_tic_duration{};
    sf::Time current_night_time{};

    int current_hour{};
    int actual_night{};
    bool custom_night{};
};

}

#endif
