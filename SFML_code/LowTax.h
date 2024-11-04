#ifndef LOWTAX
#define LOWTAX

#include "TaxPolicy.h"
/**
 * @class LowTax
 * @brief A concrete tax policy representing a low tax rate.
 * 
 * The LowTax class inherits from TaxPolicy and provides an implementation
 * for calculating tax based on a low tax rate, affecting the revenue accordingly.
 */
class LowTax : public TaxPolicy
{
public:
     /**
     * @brief Default constructor for the LowTax policy.
     * 
     * Initializes a low tax policy with predefined settings for applying
     * a lower tax rate.
     */
    LowTax();
    /**
     * @brief Calculates tax on a given revenue based on the low tax rate.
     * 
     * This method implements the tax calculation logic for a low tax rate,
     * reducing the provided revenue according to this policy's rules.
     * 
     * @param Revenue The revenue amount on which tax is to be calculated.
     * @return The calculated tax amount.
     */
    virtual double calculateTax(double Revenue);


};

#endif