#ifndef SLRECEIVER_H
#define SLRECEIVER_H

// #include "Command.h"
// #include "SLReceiver.h"
#include "City.h"

class SLReceiver
{
private:
    City* cty;

public:
    inline SLReceiver(City* city) { this->cty = city; }

    void update(double satisfaction);
};

#endif