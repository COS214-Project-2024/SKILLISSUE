#include <gtest/gtest.h>
#include "../ResourceManager.h"
#include "../Resources.h"

class ResourceManagerTest : public ::testing::Test {
protected:
    ResourceManager* resourceManager;
    Resources* resources;

    void SetUp() override {
    resources = Resources::getResourcesInstance();

    resourceManager = new ResourceManager();

    // Initialize resources to known values before each test
    resources->setWater(1000);
    resources->setPower(1000);
    resources->setSewage(1000);
    resources->setMaterial(1000);
    }



    void TearDown() override {
        delete resourceManager;
        // Reset resources to default values if necessary
    }
};

// Test consumeWater method for successful consumption
TEST_F(ResourceManagerTest, ConsumeWater_Success) {
    int initialWater = resources->getWater();
    int value = 100; // Less than 20% of initialWater (1000 * 0.2 = 200)
    bool result = resourceManager->consumeWater(value);

    EXPECT_TRUE(result);
    EXPECT_EQ(resources->getWater(), initialWater - value);
}

// Test consumeWater method for failed consumption due to exceeding limit
TEST_F(ResourceManagerTest, ConsumeWater_Fail) {
    int initialWater = resources->getWater();
    int value = 250; // More than 20% of initialWater
    bool result = resourceManager->consumeWater(value);

    EXPECT_FALSE(result);
    EXPECT_EQ(resources->getWater(), initialWater); // Water should remain unchanged
}

// Test consumePower method for successful consumption
TEST_F(ResourceManagerTest, ConsumePower_Success) {
    int initialPower = resources->getPower();
    int value = 300; // Less than 40% of initialPower (1000 * 0.4 = 400)
    bool result = resourceManager->consumePower(value);

    EXPECT_TRUE(result);
    EXPECT_EQ(resources->getPower(), initialPower - value);
}

// Test consumePower method for failed consumption due to exceeding limit
TEST_F(ResourceManagerTest, ConsumePower_Fail) {
    int initialPower = resources->getPower();
    int value = 500; // More than 40% of initialPower
    bool result = resourceManager->consumePower(value);

    EXPECT_FALSE(result);
    EXPECT_EQ(resources->getPower(), initialPower); // Power should remain unchanged
}

// Test consumeSewage method for successful consumption
TEST_F(ResourceManagerTest, ConsumeSewage_Success) {
    int initialSewage = resources->getSewage();
    int value = 500; // Less than 60% of initialSewage (1000 * 0.6 = 600)
    bool result = resourceManager->consumeSewage(value);

    EXPECT_TRUE(result);
    EXPECT_EQ(resources->getSewage(), initialSewage - value);
}

// Test consumeSewage method for failed consumption due to exceeding limit
TEST_F(ResourceManagerTest, ConsumeSewage_Fail) {
    int initialSewage = resources->getSewage();
    int value = 700; // More than 60% of initialSewage
    bool result = resourceManager->consumeSewage(value);

    EXPECT_FALSE(result);
    EXPECT_EQ(resources->getSewage(), initialSewage); // Sewage should remain unchanged
}

// Test consumeMaterial method for successful consumption
TEST_F(ResourceManagerTest, ConsumeMaterial_Success) {
    int initialMaterial = resources->getMaterial();
    int value = 700; // Less than 80% of initialMaterial (1000 * 0.8 = 800)
    bool result = resourceManager->consumeMaterial(value);

    EXPECT_TRUE(result);
    EXPECT_EQ(resources->getMaterial(), initialMaterial - value);
}

// Test consumeMaterial method for failed consumption due to exceeding limit
TEST_F(ResourceManagerTest, ConsumeMaterial_Fail) {
    int initialMaterial = resources->getMaterial();
    int value = 900; // More than 80% of initialMaterial
    bool result = resourceManager->consumeMaterial(value);

    EXPECT_FALSE(result);
    EXPECT_EQ(resources->getMaterial(), initialMaterial); // Material should remain unchanged
}

// Test setWater method for successful update
TEST_F(ResourceManagerTest, SetWater_Success) {
    int newWater = 1200;
    resourceManager->setWater(newWater);

    EXPECT_EQ(resources->getWater(), newWater);
}

// Test setWater method for failure due to negative value
TEST_F(ResourceManagerTest, SetWater_Fail_NegativeValue) {
    int initialWater = resources->getWater();
    int newWater = -100;
    resourceManager->setWater(newWater);

    EXPECT_EQ(resources->getWater(), initialWater); // Water should remain unchanged
}

// Test setWater method for failure due to lower value than current
TEST_F(ResourceManagerTest, SetWater_Fail_LowerValue) {
    int initialWater = resources->getWater();
    int newWater = 800; // Less than initialWater
    resourceManager->setWater(newWater);

    EXPECT_EQ(resources->getWater(), initialWater); // Water should remain unchanged
}

// Similarly, tests for setPower
TEST_F(ResourceManagerTest, SetPower_Success) {
    int newPower = 1500;
    resourceManager->setPower(newPower);

    EXPECT_EQ(resources->getPower(), newPower);
}

TEST_F(ResourceManagerTest, SetPower_Fail_NegativeValue) {
    int initialPower = resources->getPower();
    int newPower = -200;
    resourceManager->setPower(newPower);

    EXPECT_EQ(resources->getPower(), initialPower);
}

TEST_F(ResourceManagerTest, SetPower_Fail_LowerValue) {
    int initialPower = resources->getPower();
    int newPower = 900;
    resourceManager->setPower(newPower);

    EXPECT_EQ(resources->getPower(), initialPower);
}

// Tests for getWater method
TEST_F(ResourceManagerTest, GetWater) {
    EXPECT_EQ(resourceManager->getWater(), resources->getWater());
}

// Tests for getPower method
TEST_F(ResourceManagerTest, GetPower) {
    EXPECT_EQ(resourceManager->getPower(), resources->getPower());
}

// Tests for getSewage method
TEST_F(ResourceManagerTest, GetSewage) {
    EXPECT_EQ(resourceManager->getSewage(), resources->getSewage());
}

// Tests for getMaterial method
TEST_F(ResourceManagerTest, GetMaterial) {
    EXPECT_EQ(resourceManager->getMaterial(), resources->getMaterial());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}