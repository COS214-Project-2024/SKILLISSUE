#include <gtest/gtest.h>
#include "../Memento.h"
#include "../Map.h"
#include "../DRReceiver.h"
#include "../ResourceManager.h"
#include "../DistributePopulation.h"
#include "../SatisfactionCalculator.h"
#include "../CreateAndDistributeGoods.h"
#include "../Resources.h"
#include "../SCReceiver.h"

/**
 * @brief Test to verify Memento class member initialization and getters.
 */
TEST(MementoTest, MementoInitialization) {
    // Create a Map object (optional)
    Map cityMap;

    // Create a Memento object with test values
    Memento memento(100.0, 50.0, 80.0, 40.0, 75.0, 5000.0, 1000.0, 1, &cityMap);

    // Verify each field using getters
    EXPECT_EQ(memento.getPopulationPool(), 100.0);
    EXPECT_EQ(memento.getEmploymentPool(), 50.0);
    EXPECT_EQ(memento.getPopulation(), 80.0);
    EXPECT_EQ(memento.getEmployable(), 40.0);
    EXPECT_EQ(memento.getSatisfaction(), 75.0);
    EXPECT_EQ(memento.getEarnings(), 5000.0);
    EXPECT_EQ(memento.getFunds(), 1000.0);
    EXPECT_EQ(memento.getDay(), 1);
    EXPECT_EQ(memento.getMap(), &cityMap);  // Check if map pointer is set correctly
}

/**
 * @brief Test for Memento when the map is set to nullptr (optional case).
 */
TEST(MementoTest, MementoInitializationWithNullMap) {
    // Create a Memento object without providing a map (nullptr case)
    Memento memento(150.0, 70.0, 90.0, 45.0, 85.0, 6000.0, 1500.0, 2, nullptr);

    // Verify each field using getters
    EXPECT_EQ(memento.getPopulationPool(), 150.0);
    EXPECT_EQ(memento.getEmploymentPool(), 70.0);
    EXPECT_EQ(memento.getPopulation(), 90.0);
    EXPECT_EQ(memento.getEmployable(), 45.0);
    EXPECT_EQ(memento.getSatisfaction(), 85.0);
    EXPECT_EQ(memento.getEarnings(), 6000.0);
    EXPECT_EQ(memento.getFunds(), 1500.0);
    EXPECT_EQ(memento.getDay(), 2);
    EXPECT_EQ(memento.getMap(), nullptr);  // Should be nullptr
}

/**
 * @brief Main function to run all tests.
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
