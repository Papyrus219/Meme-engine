#include "./subject.hpp"
#include "./observer.hpp"

void meme::Subject::Notify(Event event)
{
    for(auto observer : observers)
        observer->onNotify(event);
}

void meme::Subject::Add_observer(Observer* observer)
{
    for(int i=0;i<observers.size();i++)
    {
        if(observers[i] == observer)
            return;
    }
    observers.push_back(observer);
}

void meme::Subject::Remove_observer(Observer* observer)
{
    for(int i=0;i<observers.size();i++)
    {
        if(observers[i] == observer)
            observers.erase( observers.begin() + i );
    }
}

