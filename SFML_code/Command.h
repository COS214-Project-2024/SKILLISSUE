#ifndef COMMAND_H
#define COMMAND_H

#include "Tile.h"
#include "City.h"

class Command {
    protected:
    
    public:
    Command(){};
    virtual void execute() = 0;

};

#endif