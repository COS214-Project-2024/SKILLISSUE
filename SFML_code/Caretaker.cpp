#include "Caretaker.h"

Caretaker::~Caretaker() 
{
    while(!this->mementos.empty()) popState();
}

void Caretaker::storeMemento(Memento* memento) {
    mementos.push(memento);
}

Memento* Caretaker::retrieveMemento() {
    if (!mementos.empty()) {
        Memento* lastMemento = mementos.top();
        mementos.pop();
        return lastMemento;
    }
    return nullptr;
}

bool Caretaker::hasMementos() const {
    return !mementos.empty();
}

void Caretaker::popState()
{
    delete this->mementos.top();
    this->mementos.pop();

    return;
}
