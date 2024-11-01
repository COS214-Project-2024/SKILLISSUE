#ifndef DISTRIBUTERESOURCES_H
#define DISTRIBUTERESOURCES_H

#include "Command.h"

class DistributeResources : public Command {
    protected:
    
    public:
    DistributeResources(){};
    void execute() override;

};

#endif