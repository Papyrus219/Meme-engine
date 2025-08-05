#ifndef SUBJCET_H
#define SUBJCET_H

#include<vector>
#include<memory>
#include "observer.hpp"

namespace meme
{

class Subject
{
public:

    void Notify(const Event event, const Direction direction);
    void Add_observer(Observer *observer_to_add);
    void Remove_observer(Observer * observer_to_remove);

private:
    std::vector<Observer *> observers{};
};

}



#endif
