#include <gtest/gtest.h>
#include "../ResourceManager.h"
#include "../Resources.h"

class TestResources : public Resources {
public:
    // Expose the protected getResourcesInstance() as public
    static Resources& getInstance() {
        return getResourcesInstance();
    }
};

class ResourceManagerTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        // Initialize resources to known values before each test
        TestResources::getInstance().setWater(100);
        TestResources::getInstance().setPower(100);
        TestResources::getInstance().setSewage(100);
        TestResources::getInstance().setMaterial(100);
    }

    ResourceManager resourceManager;
};

// Test useWater method when the request is less than 20% of available water
TEST_F(ResourceManagerTest, UseWater_Succeeds_WhenUnder20Percent) {
    int initialWater = resourceManager.getWater();
    int requestAmount = static_cast<int>(initialWater * 0.1); // 10% of water

    bool result = resourceManager.useWater(requestAmount);

    EXPECT_TRUE(result);
    EXPECT_EQ(resourceManager.getWater(), initialWater - requestAmount);
}

// Test useWater method when the request exceeds 20% of available water
TEST_F(ResourceManagerTest, UseWater_Fails_WhenOver20Percent) {
    int initialWater = resourceManager.getWater();
    int requestAmount = static_cast<int>(initialWater * 0.3); // 30% of water

    bool result = resourceManager.useWater(requestAmount);

    EXPECT_FALSE(result);
    EXPECT_EQ(resourceManager.getWater(), initialWater); // No change expected
}

// Test usePower method when the request is less than 40% of available power
TEST_F(ResourceManagerTest, UsePower_Succeeds_WhenUnder40Percent) {
    int initialPower = resourceManager.getPower();
    int requestAmount = static_cast<int>(initialPower * 0.3); // 30% of power

    bool result = resourceManager.usePower(requestAmount);

    EXPECT_TRUE(result);
    EXPECT_EQ(resourceManager.getPower(), initialPower - requestAmount);
}

// Test usePower method when the request exceeds 40% of available power
TEST_F(ResourceManagerTest, UsePower_Fails_WhenOver40Percent) {
    int initialPower = resourceManager.getPower();
    int requestAmount = static_cast<int>(initialPower * 0.5); // 50% of power

    bool result = resourceManager.usePower(requestAmount);

    EXPECT_FALSE(result);
    EXPECT_EQ(resourceManager.getPower(), initialPower); // No change expected
}

// Test setWater method with a value greater than current water
TEST_F(ResourceManagerTest, SetWater_Succeeds_WhenValueIsGreater) {
    int initialWater = resourceManager.getWater();
    int newValue = initialWater + 50;

    resourceManager.setWater(newValue);

    EXPECT_EQ(resourceManager.getWater(), newValue);
}

// Test setWater method with a value less than current water
TEST_F(ResourceManagerTest, SetWater_Fails_WhenValueIsLess) {
    int initialWater = resourceManager.getWater();
    int newValue = initialWater - 50;

    resourceManager.setWater(newValue);

    EXPECT_EQ(resourceManager.getWater(), initialWater); // No change expected
}

// Test getMaterial method
TEST_F(ResourceManagerTest, GetMaterial_ReturnsCorrectValue) {
    int expectedMaterial = 100;

    int actualMaterial = resourceManager.getMaterial();

    EXPECT_EQ(actualMaterial, expectedMaterial);
}

// Test useSewage method when the request is less than 60% of available sewage
TEST_F(ResourceManagerTest, UseSewage_Succeeds_WhenUnder60Percent) {
    int initialSewage = resourceManager.getSewage();
    int requestAmount = static_cast<int>(initialSewage * 0.5); // 50% of sewage

    bool result = resourceManager.useSewage(requestAmount);

    EXPECT_TRUE(result);
    EXPECT_EQ(resourceManager.getSewage(), initialSewage - requestAmount);
}

// Test useSewage method when the request exceeds 60% of available sewage
TEST_F(ResourceManagerTest, UseSewage_Fails_WhenOver60Percent) {
    int initialSewage = resourceManager.getSewage();
    int requestAmount = static_cast<int>(initialSewage * 0.7); // 70% of sewage

    bool result = resourceManager.useSewage(requestAmount);

    EXPECT_FALSE(result);
    EXPECT_EQ(resourceManager.getSewage(), initialSewage); // No change expected
}

// Test useMaterial method when the request is less than 80% of available material
TEST_F(ResourceManagerTest, UseMaterial_Succeeds_WhenUnder80Percent) {
    int initialMaterial = resourceManager.getMaterial();
    int requestAmount = static_cast<int>(initialMaterial * 0.7); // 70% of material

    bool result = resourceManager.useMaterial(requestAmount);

    EXPECT_TRUE(result);
    EXPECT_EQ(resourceManager.getMaterial(), initialMaterial - requestAmount);
}

// Test useMaterial method when the request exceeds 80% of available material
TEST_F(ResourceManagerTest, UseMaterial_Fails_WhenOver80Percent) {
    int initialMaterial = resourceManager.getMaterial();
    int requestAmount = static_cast<int>(initialMaterial * 0.9); // 90% of material

    bool result = resourceManager.useMaterial(requestAmount);

    EXPECT_FALSE(result);
    EXPECT_EQ(resourceManager.getMaterial(), initialMaterial); // No change expected
}

// Test setPower method with a value greater than current power
TEST_F(ResourceManagerTest, SetPower_Succeeds_WhenValueIsGreater) {
    int initialPower = resourceManager.getPower();
    int newValue = initialPower + 50;

    resourceManager.setPower(newValue);

    EXPECT_EQ(resourceManager.getPower(), newValue);
}

// Test setPower method with a value less than current power
TEST_F(ResourceManagerTest, SetPower_Fails_WhenValueIsLess) {
    int initialPower = resourceManager.getPower();
    int newValue = initialPower - 50;

    resourceManager.setPower(newValue);

    EXPECT_EQ(resourceManager.getPower(), initialPower); // No change expected
}

// You can add similar tests for setSewage and setMaterial methods

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}