#ifndef EVENTS_H
#define EVENTS_H

namespace meme
{
    enum class Event
    {
        DOOR_CLOSED,
        DOOR_OPEN,
        DOOR_LIGHT_UP,
        DOOR_LIGHT_DOWN,
        ENTER,
        LEAVE,
        CAMERA_OPEN,
        CAMERA_CLOSED,
    };

    enum class Direction
    {
        LEFT,
        RIGHT,
        BACK,
        FRONT,
    };
}

#endif
