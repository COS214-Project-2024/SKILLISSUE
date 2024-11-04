#ifndef GETPOWERCOMMAND_H
#define GETPOWERCOMMAND_H

/**
 * @class GetPowerCommand
 * @brief Command class for handling power distribution requests.
 * 
 * The GetPowerCommand class encapsulates the action of distributing power to a target,
 * typically used within a command pattern to execute power-related operations.
 */
class GetPowerCommand{
    
     /**
     * @brief Executes the power distribution command.
     * 
     * This method performs the action of supplying power as defined by the command,
     * typically interacting with a receiver to fulfill the request.
     */
    void execute();
};

#endif
