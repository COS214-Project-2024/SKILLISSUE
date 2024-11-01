#ifndef CARETAKER_H
#define CARETAKER_H

class Caretaker {

private:
	stack<Memento*> mementos;

public:
	void storeMemento(Memento* memento);

	Memento* retrieveMemento();
};

#endif
