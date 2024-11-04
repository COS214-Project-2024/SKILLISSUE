#include "../Tile.h"
#include <gtest/gtest.h>

// Test Fixture for Tile
class TileTest : public ::testing::Test {
protected:
    void SetUp() override
    {
        // Initialize a Tile object for testing
        texture.loadFromFile("grass.png");
        std::vector<Animation> animations; // Empty animations for now
        tile = new Tile(32, 2, texture, animations, TileType::RESIDENTIAL, 100, 50, 5, 50.0, 10, 100);
    }

    void TearDown() override { delete tile; }

    sf::Texture texture;
    Tile* tile;
};

// Test: Satisfaction Methods
TEST_F(TileTest, SatisfactionManagement)
{
    tile->addSatisfaction(10.0);
    EXPECT_EQ(tile->getSatisfaction(), 60.0);

    tile->removeSatisfaction(20.0);
    EXPECT_EQ(tile->getSatisfaction(), 40.0);
}

// Test: Producing Resources
TEST_F(TileTest, ProduceResource)
{
    tile->produceResource(ResourceType::ELECTRICITY, 50);
    EXPECT_EQ(tile->resources[ResourceType::ELECTRICITY], 50);

    // Try producing more than the max
    tile->produceResource(ResourceType::ELECTRICITY, 100);
    EXPECT_EQ(tile->resources[ResourceType::ELECTRICITY], 100); // Should cap at max
}

// Test: Setting Max Resources
TEST_F(TileTest, SetMaxResource)
{
    tile->setMaxResource(ResourceType::ELECTRICITY, 80);
    EXPECT_EQ(tile->maxResources[ResourceType::ELECTRICITY], 80);

    // Ensure resources do not exceed the new max
    tile->resources[ResourceType::ELECTRICITY] = 90;
    tile->setMaxResource(ResourceType::ELECTRICITY, 70);
    EXPECT_EQ(tile->resources[ResourceType::ELECTRICITY], 90); // Should not lower current resources
}

// Test: Cost Display
TEST_F(TileTest, GetCost) { EXPECT_EQ(tile->getCost(), "100"); }

// Test: Cloning
TEST_F(TileTest, Clone)
{
    Tile* clone = tile->clone();
    EXPECT_EQ(clone->getSatisfaction(), tile->getSatisfaction());
    EXPECT_EQ(clone->resources[ResourceType::ELECTRICITY], tile->resources[ResourceType::ELECTRICITY]);
    EXPECT_EQ(clone->cost, tile->cost);
    EXPECT_EQ(clone->tileType, tile->tileType);
    delete clone;
}
