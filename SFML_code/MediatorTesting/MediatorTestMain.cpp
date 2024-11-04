#include <gtest/gtest.h>
#include "../CityMediator.h"
#include "../Tile.h"
#include "../City.h"
#include "../AnimationHandler.h"
#include "../DistributePopulation.h"
#include "../SatisfactionCalculator.h"
#include "../SCReceiver.h"
#include "../CreateAndDistributeGoods.h"
#include "../CDReceiver.h"
#include "../Map.h"
#include "../LowTax.h"
#include "../Memento.h"
#include "../DReceiver.h"
#include "../TaxPolicy.h"

// Helper function to create a tile of a specific type
Tile* createTile(TileType type, int region = 0, int consumption = 10) {
    Tile* tile = new Tile();
    tile->tileType = type;
    tile->regions[0] = region;
    tile->consumption = consumption;
    tile->resources[ResourceType::ELECTRICITY] = 100;
    tile->resources[ResourceType::WATER] = 100;
    tile->resources[ResourceType::SEWAGE] = 100;
    tile->resources[ResourceType::WASTE] = 100;
    return tile;
}

class CityMediatorTest : public ::testing::Test {
protected:
    City* city;
    CityMediator* mediator;
    Tile* residentialTile;
    Tile* fireStationTile;
    Tile* powerPlantTile;
    Tile* waterPlantTile;
    Tile* sewagePlantTile;
    Tile* wasteManagementTile;

    void SetUp() override {
        city = new City();
        mediator = new CityMediator(city);

        // Create various tiles
        residentialTile = createTile(TileType::RESIDENTIAL, 1);
        fireStationTile = createTile(TileType::FIRESTATION, 1);
        powerPlantTile = createTile(TileType::POWERPLANT, 1);
        waterPlantTile = createTile(TileType::WATERPLANT, 1);
        sewagePlantTile = createTile(TileType::SEWAGEPLANT, 1);
        wasteManagementTile = createTile(TileType::WASTEMANAGEMENT, 1);

        city->map->tiles = {residentialTile, fireStationTile, powerPlantTile, waterPlantTile, sewagePlantTile, wasteManagementTile};
    }

    void TearDown() override {
        delete city;
        delete residentialTile;
        delete fireStationTile;
        delete powerPlantTile;
        delete waterPlantTile;
        delete sewagePlantTile;
        delete wasteManagementTile;
        delete mediator;
    }
};

// Test burnHouse function via notify
TEST_F(CityMediatorTest, NotifyFireStation_BurnHouseIfNoFireStation) {
    residentialTile->regions[0] = 2; // Assign different region to avoid fire station detection
    mediator->notify(residentialTile, TileType::FIRESTATION);
    EXPECT_EQ(residentialTile->tileVariant, 0);
}

// Test getPower function via notify
TEST_F(CityMediatorTest, NotifyPowerPlant_GetPowerIfConnected) {
    powerPlantTile->resources[ResourceType::ELECTRICITY] = 50; // Enough electricity for consumption
    mediator->notify(residentialTile, TileType::POWERPLANT);
    EXPECT_EQ(residentialTile->resources[ResourceType::ELECTRICITY], residentialTile->consumption);
}

// Test getWater function via notify
TEST_F(CityMediatorTest, NotifyWaterPlant_GetWaterIfConnected) {
    waterPlantTile->resources[ResourceType::WATER] = 50; // Enough water for consumption
    mediator->notify(residentialTile, TileType::WATERPLANT);
    EXPECT_EQ(residentialTile->resources[ResourceType::WATER], residentialTile->consumption);
}

// Test disposeWaste function via notify
TEST_F(CityMediatorTest, NotifyWasteManagement_DisposeWasteIfConnected) {
    wasteManagementTile->resources[ResourceType::WASTE] = 50; // Enough waste capacity for consumption
    mediator->notify(residentialTile, TileType::WASTEMANAGEMENT);
    EXPECT_EQ(residentialTile->resources[ResourceType::WASTE], residentialTile->consumption);
}

// Test treatSewage function via notify
TEST_F(CityMediatorTest, NotifySewagePlant_TreatSewageIfConnected) {
    sewagePlantTile->resources[ResourceType::SEWAGE] = 50; // Enough sewage treatment capacity
    mediator->notify(sewagePlantTile, TileType::SEWAGEPLANT);
    EXPECT_EQ(sewagePlantTile->resources[ResourceType::SEWAGE], sewagePlantTile->consumption);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}