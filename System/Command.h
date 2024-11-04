#ifndef COMMAND_H
#define COMMAND_H

#include "Tile.h"

/**
 * @class Command
 * @brief Abstract base class for implementing commands in a command pattern.
 * 
 * The Command class provides a framework for executing commands on various elements
 * in the system, enabling encapsulation of actions and deferred execution.
 */
class Command {

public:
    /**
     * @brief Pure virtual function for executing a command.
     * 
     * This function must be overridden by derived classes to define
     * the specific actions of the command.
     */
    virtual void execute() = 0;

};

#endif