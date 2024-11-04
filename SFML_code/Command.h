#ifndef COMMAND_H
#define COMMAND_H

#include "Tile.h"

class Command {

public:
    virtual void execute() = 0;

};

#endif