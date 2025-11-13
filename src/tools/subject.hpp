#ifndef MEME_SUBJECT_HPP
#define MEME_SUBJECT_HPP

#include <vector>
#include <memory>
#include "./event.hpp"

namespace meme
{

class Observer;

class Subject
{
public:
        void Notify(Event event) noexcept;
        void Add_observer(Observer *observer) noexcept;
        void Remove_observer(Observer *observer) noexcept;
private:
    std::vector<Observer*> observers;
};

}

#endif
