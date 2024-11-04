#include "Caretaker.h"

Caretaker::Caretaker() 
{
    mementos.resize(300);
}

Caretaker::~Caretaker() 
{
    while(!this->mementos.empty()) popState();
}

void Caretaker::storeMemento(Memento* memento) {
    if(mementos.size() > 400)
    {
        popState();
        mementos.push_back(memento);
    }
    else
    {
        mementos.push_back(memento);
    }
}

Memento* Caretaker::retrieveMemento() {
    if (!mementos.empty()) {
        Memento* lastMemento = mementos.back();
        mementos.pop_back();
        return lastMemento;
    }
    return nullptr;
}

bool Caretaker::hasMementos() const {
    return !mementos.empty();
}

void Caretaker::popState()
{
    delete this->mementos.front();
    this->mementos.pop_front();

    return;
}
