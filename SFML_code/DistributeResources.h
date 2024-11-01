#ifndef DISTRIBUTE_RESOURCES_H
#define DISTRIBUTE_RESOURCES_H

#include "Command.h"   // Make sure to include the Command header
#include "DReceiver.h"

class DistributeResources : public Command {
private:
    DReceiver* receiver;

public:
    DistributeResources(DReceiver* receiver) : receiver(receiver) {}

    void execute() override;  // Declaration only, implementation can be below or in .cpp
};

#endif // DISTRIBUTE_RESOURCES_H
