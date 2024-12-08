#ifndef OBSERVER_H
#define OBSERVER_H

#include "Memento.h"

class Observer 
{
public:
    virtual void update(const Memento::SystemState& state) = 0;  // Interface to update with new state
};

#endif // OBSERVER_H
