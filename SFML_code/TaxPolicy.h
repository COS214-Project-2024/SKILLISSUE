#ifndef TAXPOLICY
#define TAXPOLICY

#include <string>

class TaxPolicy
{
protected:
    int taxRate;
    std::string type;

public:
    virtual double calculateTax(double Revenue) = 0;
    virtual std::string getTaxPolicy();

};

#endif