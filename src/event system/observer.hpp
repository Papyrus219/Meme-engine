#ifndef OBSERVER_H
#define OBSERVER_H

#include "events.hpp"

namespace meme
{


class Observer
{
public:
    virtual ~Observer(){};
    virtual void On_notify(const Event event, const Direction direction) = 0;
};

}


#endif
