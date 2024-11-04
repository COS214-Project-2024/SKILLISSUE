#ifndef MIDTAX
#define MIDTAX

#include "TaxPolicy.h"

/**
 * @class MidTax
 * @brief A concrete tax policy representing a medium tax rate.
 * 
 * The MidTax class inherits from TaxPolicy and provides an implementation
 * for calculating tax based on a medium tax rate, applying an intermediate level of tax to revenue.
 */
class MidTax : public TaxPolicy
{
public:
    /**
     * @brief Default constructor for the MidTax policy.
     * 
     * Initializes a mid-level tax policy with predefined settings for applying
     * a medium tax rate.
     */
    MidTax();
    /**
     * @brief Calculates tax on a given revenue based on the medium tax rate.
     * 
     * This method implements the tax calculation logic for a medium tax rate,
     * adjusting the provided revenue according to this policy's rules.
     * 
     * @param Revenue The revenue amount on which tax is to be calculated.
     * @return The calculated tax amount.
     */
    virtual double calculateTax(double Revenue);


};

#endif