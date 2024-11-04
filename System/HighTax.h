#ifndef HIGHTAX
#define HIGHTAX

#include "TaxPolicy.h"

/**
 * @class HighTax
 * @brief A concrete tax policy representing a high tax rate.
 * 
 * The HighTax class inherits from TaxPolicy and provides an implementation
 * for calculating tax based on a high tax rate, affecting the revenue accordingly.
 */
class HighTax : public TaxPolicy
{
public:
    /**
     * @brief Default constructor for the HighTax policy.
     * 
     * Initializes a high tax policy with predefined settings for applying
     * a higher tax rate.
     */
    HighTax();

    /**
     * @brief Calculates tax on a given revenue based on the high tax rate.
     * 
     * This method implements the tax calculation logic for a high tax rate,
     * reducing the provided revenue according to this policy's rules.
     * 
     * @param Revenue The revenue amount on which tax is to be calculated.
     * @return The calculated tax amount.
     */
    virtual double calculateTax(double Revenue);


};

#endif