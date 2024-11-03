#ifndef CARETAKER_H
#define CARETAKER_H

#include "Memento.h"
#include <stack>

/**
 * @brief The Caretaker class is responsible for managing Memento objects,
 * allowing state saving and restoration through the Memento design pattern.
 */
class Caretaker {
private:
    std::stack<Memento*> mementos;  ///< Stack to store Memento objects for undo functionality

public:
    /**
     * @brief Destructor to clean up Mementos.
     * Releases all stored Mementos to prevent memory leaks.
     */
    ~Caretaker();

    /**
     * @brief Stores a Memento in the stack.
     * @param memento A pointer to the Memento object representing a saved state.
     */
    void storeMemento(Memento* memento);

    /**
     * @brief Retrieves the last Memento stored.
     * Removes and returns the most recent Memento from the stack, allowing undo functionality.
     * @return A pointer to the last Memento stored, or nullptr if no Mementos are available.
     */
    Memento* retrieveMemento();

    /**
     * @brief Checks if there are any Mementos available.
     * @return True if there is at least one Memento in the stack; otherwise, false.
     */
    bool hasMementos() const;

    /**
     * @brief Pops and discards the last stored Memento.
     * Removes the most recent Memento from the stack without returning it.
     */
    void popState();
};

#endif // CARETAKER_H
