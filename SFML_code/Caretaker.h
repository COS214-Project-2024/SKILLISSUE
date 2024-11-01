#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <stack>

class Caretaker {

private:
	std::stack<Memento*> mementos;

public:
	void storeMemento(Memento* memento);

	Memento* retrieveMemento();
};

#endif
