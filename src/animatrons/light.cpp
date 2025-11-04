#include "light.hpp"

using namespace meme;

void meme::Light::Move()
{
        if(is_under_door)
        {
            Under_door();
            return;
        }

        auto camera_out = assign_camera_system->Get_camera_ptr( move_path[current_possition - 1] );
        camera_out->Move_out(*this);

        if(current_possition == move_path.size())
        {
            subject.Notify(Event::ENTER,Direction::LEFT);
            is_under_door = true;
            Under_door();

            return;
        }

        if(current_possition == 4)
        {
            std::srand(std::time(NULL));
            if(std::rand() % 2) current_possition = 2;
        }

        auto camera_in = assign_camera_system->Get_camera_ptr( move_path[current_possition] );
        camera_in->Move_in(*this);
}

void Light::Under_door()
{
    if(right_door_open)
    {
        rage++;
        if(rage >= 3)
        {
            Jumpscare();
        }
    }
    else
    {
        chill++;
        if(chill >= 3)
        {
            subject.Notify(Event::LEAVE,Direction::LEFT);
            current_possition = 1;
            chill = 0;
            rage = 0;
        }
    }
}

void Light::On_notify ( const Event event, const Direction direction )
{
    switch(event)
    {
        case Event::DOOR_OPEN:
            right_door_open = true;
            break;
        case Event::DOOR_CLOSED:
            right_door_open = false;
            break;
    }
}
