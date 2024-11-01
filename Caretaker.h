#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <stack>

class Caretaker {
private:
    std::stack<Memento*> mementos;  // Stack to store Mementos for undo functionality

public:
    ~Caretaker();                   // Destructor to clean up Mementos

    void storeMemento(Memento* memento); // Store Memento in stack
    Memento* retrieveMemento();          // Retrieve last Memento for undoing

    bool hasMementos() const;       // Check if there are any Mementos available
};

#endif // CARETAKER_H
