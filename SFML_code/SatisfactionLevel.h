#ifndef SATISFACTIONLEVEL_H
#define SATISFACTIONLEVEL_H

#include "Command.h"
#include "SLReceiver.h"

class SatisfactionLevel : public Command
{
    protected:
    double satisfaction;
    SLReceiver* rec;
    
    public:
    SatisfactionLevel(SLReceiver* receiverL) : rec(receiverL){satisfaction = 0;};
    void execute() override {
        this->rec->update(satisfaction);
    };
};

#endif