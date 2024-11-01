#include "ResourceManager.h"
#include <gtest/gtest.h>

/**
 * @brief Unit test for the getWater() and setWater() methods.
 */
TEST(ResourceManagerTest, WaterResourceTest) {
  ResourceManager &rm = ResourceManager::getResourceManagerInstance();
  rm.setWater(100);
  EXPECT_EQ(rm.getWater(), 100) << "Water resource should be 100";

  rm.setWater(200);
  EXPECT_EQ(rm.getWater(), 200) << "Water resource should be 200";
}

/**
 * @brief Unit test for the getPower() and setPower() methods.
 */
TEST(ResourceManagerTest, PowerResourceTest) {
  ResourceManager &rm = ResourceManager::getResourceManagerInstance();
  rm.setPower(50);
  EXPECT_EQ(rm.getPower(), 50) << "Power resource should be 50";

  rm.setPower(150);
  EXPECT_EQ(rm.getPower(), 150) << "Power resource should be 150";
}

/**
 * @brief Unit test for the getSewage() and setSewage() methods.
 */
TEST(ResourceManagerTest, SewageResourceTest) {
  ResourceManager &rm = ResourceManager::getResourceManagerInstance();
  rm.setSewage(30);
  EXPECT_EQ(rm.getSewage(), 30) << "Sewage resource should be 30";

  rm.setSewage(70);
  EXPECT_EQ(rm.getSewage(), 70) << "Sewage resource should be 70";
}

/**
 * @brief Unit test for the getMaterial() and setMaterial() methods.
 */
TEST(ResourceManagerTest, MaterialResourceTest) {
  ResourceManager &rm = ResourceManager::getResourceManagerInstance();
  rm.setMaterial(500);
  EXPECT_EQ(rm.getMaterial(), 500) << "Material resource should be 500";

  rm.setMaterial(1000);
  EXPECT_EQ(rm.getMaterial(), 1000) << "Material resource should be 1000";
}

/**
 * @brief Main function to run all tests.
 */
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
