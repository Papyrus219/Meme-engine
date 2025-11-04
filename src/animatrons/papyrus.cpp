#include"papyrus.hpp"
#include<iostream>
using namespace meme;

void Papyrus::Move()
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

    auto camera_in = assign_camera_system->Get_camera_ptr( move_path[current_possition] );
    camera_in->Move_in(*this);
}

void Papyrus::Under_door ()
{
    if(left_door_open)
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

            auto start_camera = assign_camera_system->Get_camera_ptr( move_path[current_possition] );
            start_camera->Move_in(*this);
        }
    }
}

void Papyrus::On_notify ( const Event event, const Direction direction )
{
    switch(event)
    {
        case Event::DOOR_OPEN:
            left_door_open = true;
            break;
        case Event::DOOR_CLOSED:
            left_door_open = false;
            break;
    }
}
