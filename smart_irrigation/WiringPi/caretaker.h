#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <vector>
#include <stdexcept>

class Caretaker
{
private:
    std::vector<Memento> history;

public:
    void save(const Memento& memento)
    {
        history.push_back(memento);
    }

    Memento undo()
    {
        if (history.empty())
        {
            throw std::out_of_range("No states to undo.");
        }
        Memento lastState = history.back();
        history.pop_back();
        return lastState;
    }

    Memento peek() const
    {
        if (history.empty())
        {
            throw std::out_of_range("No states available.");
        }
        return history.back();
    }
};

#endif // CARETAKER_H
