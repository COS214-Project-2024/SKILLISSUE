#ifndef SATISFACTIONLEVEL_H
#define SATISFACTIONLEVEL_H

#include "Command.h"

class SatisfactionLevel : public Command {
    protected:
    
    public:
    SatisfactionLevel(){};
    void execute() override;

};

#endif