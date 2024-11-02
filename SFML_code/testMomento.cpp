// #include "City.h"
// #include "Caretaker.h"
// #include <iostream>

// int main() {
//     City city;
//     Caretaker caretaker;

//     // Save initial state
//     Memento* initialState = city.createMemento();
//     caretaker.storeMemento(initialState);

//     // Modify City state (simulate an update)
//     city.update(1.0f);

//     // Undo the last change by retrieving the last saved Memento
//     Memento* lastState = caretaker.retrieveMemento();
//     if (lastState) {
//         city.loadMemento(lastState);
//         delete lastState;  // Clean up after restoring
//     }

//     return 0;
// }
