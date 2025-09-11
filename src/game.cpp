#include"game.hpp"
#include"exceptions.hpp"
using namespace meme;

Game::Game(std::string audio_path): audio_manager{audio_path} {}

void Game::Animatron_update()
{
    sf::Time current_time = time_manager->tic_clock.getElapsedTime();

    for(auto animatron : animatrons)
    {
        animatron->Move_check(current_time);
    }

}

void Game::Tic()
{
    if(time_manager->tic_clock.getElapsedTime() < time_manager->final_tic_duration) return;

    time_manager->current_night_time += time_manager->tic_clock.getElapsedTime();

    if((time_manager->current_night_time / time_manager->night_duration) > time_manager->current_hour) time_manager->current_hour++;

    if(time_manager->current_hour >= 6) End_night();
}

void Game::Start_night()
{
    for(auto &office : offices)
    {
        office.Start_night();
        if(office.parameters_ptr)
        {
            office.parameters_ptr->Start_night();
        }
    }

    time_manager->tic_clock.start();
}

void meme::Game::End_night()
{
    for(auto &office : offices)
    {
        if(office.parameters_ptr)
        {
            office.parameters_ptr->End_night();
        }
    }

    time_manager->tic_clock.stop();
}

void meme::Game::Save_save()
{
    if(saver)
        saver->Save(time_manager->current_night,stars,telephone->skipped_nights);
    else
        throw Exeption{"Try to save, to non existing Saver!"};
}

void meme::Game::Load_save()
{
    if(saver)
        saver->Load(time_manager->current_night,stars,telephone->skipped_nights);
    else
        throw Exeption{"Try to save, to non existing Saver!"};
}
