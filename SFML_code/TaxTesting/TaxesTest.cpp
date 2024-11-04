#include "../LowTax.h"
#include "gtest/gtest.h"

const double TOLERANCE = 1e-4; // used to account for floating point errors

// Tests for low tax
TEST(LowTaxTest, CalculateTax)
{
    LowTax taxPolicy;
    double revenue = 1000.0;
    double expected = 1000.0 * 0.05;
    EXPECT_NEAR(taxPolicy.calculateTax(revenue), expected, TOLERANCE);
}

TEST(LowTaxTest, GetTaxRate)
{
    LowTax taxPolicy;
    EXPECT_NEAR(taxPolicy.getTaxRate(), 0.05, TOLERANCE);
}

TEST(LowTaxTest, GetTaxPolicy)
{
    LowTax taxPolicy;
    EXPECT_EQ(taxPolicy.getTaxPolicy(), "low");
}