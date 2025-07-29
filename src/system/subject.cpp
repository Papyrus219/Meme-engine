#include"subject.hpp"
#include <algorithm>
using namespace meme;

void Subject::Add_observer ( Observer * observer_to_add )
{
    observers.push_back(observer_to_add);
}

void Subject::Remove_observer ( Observer* observer_to_remove )
{
    for(int i=0;i<observers.size();i++)
    {
        if(observers[i] == observer_to_remove)
        {
            observers.erase(observers.begin()+i);
            return;
        }
    }
}

void Subject::Notify ( const Event event, const Direction direction )
{
    for(auto &observer : observers)
    {
        observer->On_notify(event,direction);
    }

}

