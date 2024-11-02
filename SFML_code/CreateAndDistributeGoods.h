#ifndef CREATE_AND_DISTRIBUTE_GOODS_H
#define CREATE_AND_DISTRIBUTE_GOODS_H

#include "CDReceiver.h"

class CreateAndDistributeGoods {
private:
    CDReceiver* receiver;

public:
    CreateAndDistributeGoods(CDReceiver* receiver) : receiver(receiver) {}

    void execute() {
        receiver->update();
    }
};

#endif // CREATE_AND_DISTRIBUTE_GOODS_H
