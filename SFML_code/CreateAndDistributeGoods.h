#ifndef CREATEANDDISTRIBUTEGOODS_H
#define CREATEANDDISTRIBUTEGOODS_H

#include "Command.h"

class CreateAndDistributeGoods : public Command {
    protected:
    
    public:
    CreateAndDistributeGoods(){};
    void execute() override;

};

#endif