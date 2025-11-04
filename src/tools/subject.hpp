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
        void Notify(Event event);
        void Add_observer(Observer *observer);
        void Remove_observer(Observer *observer);
private:
    std::vector<Observer*> observers;
};

}

#endif
