#include"papyrus.hpp"
using namespace meme;

void Papyrus::Move()
{

}

void Papyrus::Under_door ()
{
    if(chill == 0 && rage == 0)
    {
        subject.Notify(Event::ENTER,Direction::LEFT);

        auto camera = assign_camera_system->Get_camera_ptr(move_path[move_path.size()-1]);
        camera->Move_out(*this);
    }

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
