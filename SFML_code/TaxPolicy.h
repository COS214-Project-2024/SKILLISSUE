#ifndef TAXPOLICY
#define TAXPOLICY

#include <string>

/**
 * @class TaxPolicy
 * @brief Abstract base class for tax policy implementations.
 * 
 * The TaxPolicy class provides a framework for different types of tax policies,
 * defining methods for calculating tax and retrieving policy details.
 */
class TaxPolicy
{
protected:
    /** @brief The tax rate applied by this policy. */
    float taxRate;
    /** @brief The type or name of the tax policy. */
    std::string type;

public:
    /**
     * @brief Calculates the tax based on the provided revenue.
     * 
     * This pure virtual function must be implemented by derived classes to apply
     * the specific tax calculation logic based on their policy.
     * 
     * @param Revenue The revenue amount on which tax is to be calculated.
     * @return The calculated tax amount.
     */
    virtual double calculateTax(double Revenue) = 0;

    /**
     * @brief Retrieves the name or type of the tax policy.
     * 
     * @return A string representing the tax policy type.
     */
    virtual std::string getTaxPolicy();

    /**
     * @brief Retrieves the tax rate applied by this policy.
     * 
     * @return The tax rate as a floating-point number.
     */
    virtual double getTaxRate();

};

#endif