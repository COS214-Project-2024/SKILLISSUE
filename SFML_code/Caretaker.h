#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <stack>

class Caretaker {

private:
	// gonna use a stack to store the mementos that way we keep popping off the prev day when undoing
	std::stack<Memento*> mementos;

public:
	// will just push the new memnto to the stack
	void storeMemento(Memento* memento);

	// will pop the stack and get the memento 
	Memento* retrieveMemento();
};

#endif
