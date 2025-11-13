#ifndef MEME_OBSERVER_HPP
#define MEME_OBSERVER_HPP

#include "./event.hpp"
#include <memory>

namespace meme
{

class Observer
{
public:
    virtual void onNotify(Event event) noexcept = 0;
    virtual ~Observer() noexcept = default;
};

}

#endif //MEME_OBSERVER_HPP
