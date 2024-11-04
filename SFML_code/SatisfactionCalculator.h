#ifndef SASTISFACTIONCALCULATOR_H
#define SASTISFACTIONCALCULATOR_H
 
#include "Command.h"
#include "SCReceiver.h"

class SatisfactionCalculator : public Command{
private:
    SCReceiver receiver;

    Map* map;
    std::string taxtype;
    double population;
    double& satisfaction;

public:
    SatisfactionCalculator(Map* map, std::string taxtype, double population, double& satisfaction);
    void execute();
};

#endif // SASTISFACTIONCALCULATOR_H
