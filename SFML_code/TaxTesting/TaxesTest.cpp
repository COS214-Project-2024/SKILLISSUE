#include "../HighTax.h"
#include "../LowTax.h"
#include "../MidTax.h"
#include "gtest/gtest.h"

const double TOLERANCE = 1e-4; // used to account for floating point errors

// Tests for low tax
/**
 * @brief Test to verify that low tax taxes the correct amount (5%)
 */
TEST(LowTaxTest, CalculateTax)
{
    LowTax taxPolicy;
    double revenue = 1000.0;
    double expected = 1000.0 * 0.05;
    EXPECT_NEAR(taxPolicy.calculateTax(revenue), expected, TOLERANCE);
}

/**
 * @brief Test to verify the getter of tax rate for low tax
 */
TEST(LowTaxTest, GetTaxRate)
{
    LowTax taxPolicy;
    EXPECT_NEAR(taxPolicy.getTaxRate(), 0.05, TOLERANCE);
}

/**
 * @brief Test to verify the getter of tax policy for low tax
 */
TEST(LowTaxTest, GetTaxPolicy)
{
    LowTax taxPolicy;
    EXPECT_EQ(taxPolicy.getTaxPolicy(), "low");
}

// Tests for mid tax
TEST(MidTaxTest, CalculateTax)
{
    MidTax taxPolicy;
    double revenue = 1000.0;
    double expectedTax = 1000.0 * 0.10; // 10% tax
    EXPECT_NEAR(taxPolicy.calculateTax(revenue), expectedTax, TOLERANCE);
}

TEST(MidTaxTest, GetTaxRate)
{
    MidTax taxPolicy;
    EXPECT_NEAR(taxPolicy.getTaxRate(), 0.10, TOLERANCE);
}

TEST(MidTaxTest, GetTaxPolicy)
{
    MidTax taxPolicy;
    EXPECT_EQ(taxPolicy.getTaxPolicy(), "mid");
}

// Tests for high tax
TEST(HighTaxTest, CalculateTax)
{
    HighTax taxPolicy;
    double revenue = 1000.0;
    double expectedTax = 1000.0 * 0.25; // 25% tax
    EXPECT_NEAR(taxPolicy.calculateTax(revenue), expectedTax, TOLERANCE);
}

TEST(HighTaxTest, GetTaxRate)
{
    HighTax taxPolicy;
    EXPECT_NEAR(taxPolicy.getTaxRate(), 0.25, TOLERANCE);
}

TEST(HighTaxTest, GetTaxPolicy)
{
    HighTax taxPolicy;
    EXPECT_EQ(taxPolicy.getTaxPolicy(), "high");
}