#include "Caretaker.h"

Caretaker::~Caretaker() {
    while (!mementos.empty()) {
        delete mementos.top();
        mementos.pop();
    }
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
