#include "SatisfactionCalculator.h"

SatisfactionCalculator::SatisfactionCalculator(Map* map, std::string taxtype, double population, double& satisfaction)
    :map(map),  taxtype(taxtype), population(population), satisfaction(satisfaction)
{}

void SatisfactionCalculator::execute()
{
    receiver.Calculate(map, taxtype, population, satisfaction);
}