#include <gtest/gtest.h>
#include "../ResourceManager.h"
#include "../Resources.h"
class ResourceManagerTest : public ::testing::Test {
protected:
    ResourceManager resourceManager;

    void SetUp() override {
        // Set initial conditions if necessary
    }

    void TearDown() override {
        // Clean up after each test if necessary
    }
};

TEST_F(ResourceManagerTest, SetWaterPositiveValue) {
    resourceManager.setWater(100);
    EXPECT_EQ(Resources::getResourcesInstance().getWater(), 100);
}

TEST_F(ResourceManagerTest, SetPowerPositiveValue) {
    resourceManager.setPower(150);
    EXPECT_EQ(Resources::getResourcesInstance().getPower(), 150);
}

TEST_F(ResourceManagerTest, SetSewagePositiveValue) {
    resourceManager.setSewage(200);
    EXPECT_EQ(Resources::getResourcesInstance().getSewage(), 200);
}

TEST_F(ResourceManagerTest, SetWastePositiveValue) {
    resourceManager.setWaste(50);
    EXPECT_EQ(Resources::getResourcesInstance().getWaste(), 50);
}

TEST_F(ResourceManagerTest, SetWaterConsumptionPositiveValue) {
    resourceManager.setWaterConsumption(60);
    EXPECT_EQ(Resources::getResourcesInstance().getWaterConsumption(), 60);
}

TEST_F(ResourceManagerTest, SetPowerConsumptionPositiveValue) {
    resourceManager.setPowerConsumption(70);
    EXPECT_EQ(Resources::getResourcesInstance().getPowerConsumption(), 70);
}

TEST_F(ResourceManagerTest, SetSewageConsumptionPositiveValue) {
    resourceManager.setSewageConsumption(80);
    EXPECT_EQ(Resources::getResourcesInstance().getSewageConsumption(), 80);
}

TEST_F(ResourceManagerTest, SetWasteConsumptionPositiveValue) {
    resourceManager.setWasteConsumption(90);
    EXPECT_EQ(Resources::getResourcesInstance().getWasteConsumption(), 90);
}

TEST_F(ResourceManagerTest, SetWaterUsageWithinRange) {
    resourceManager.setWaterUsage(50.0);
    EXPECT_DOUBLE_EQ(Resources::getResourcesInstance().getWaterUsage(), 50.0);
}

TEST_F(ResourceManagerTest, SetPowerUsageWithinRange) {
    resourceManager.setPowerUsage(75.0);
    EXPECT_DOUBLE_EQ(Resources::getResourcesInstance().getPowerUsage(), 75.0);
}

TEST_F(ResourceManagerTest, SetSewageUsageWithinRange) {
    resourceManager.setSewageUsage(25.0);
    EXPECT_DOUBLE_EQ(Resources::getResourcesInstance().getSewageUsage(), 25.0);
}

TEST_F(ResourceManagerTest, SetWasteUsageWithinRange) {
    resourceManager.setWasteUsage(45.0);
    EXPECT_DOUBLE_EQ(Resources::getResourcesInstance().getWasteUsage(), 45.0);
}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}