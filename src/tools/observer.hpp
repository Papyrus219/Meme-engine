#ifndef MEME_OBSERVER_HPP
#define MEME_OBSERVER_HPP

#include "./event.hpp"
#include <memory>

namespace meme
{

class Observer
{
public:
    virtual void onNotify(Event event) = 0;
    virtual ~Observer() = default;
};

}

#endif //MEME_OBSERVER_HPP
