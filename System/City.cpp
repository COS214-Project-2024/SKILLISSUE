#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>
#include <random>
#include <random>

#include "City.h"
#include "Tile.h"
#include "CityMediator.h"


void City::setTaxPolicy(TaxPolicy* policy)
{
    if(taxPolicy != NULL)
    {
        delete taxPolicy;
    }
    taxPolicy = policy;
}

std::string City::getTaxPolicy()
{
    if(taxPolicy != NULL)
    {
        return taxPolicy->getTaxPolicy();
    }
    else return "null";
}

void City::bulldoze(Tile &tile)
{
    /* Replace the selected tiles on the map with the tile and
     * update populations etc accordingly */
    for (int pos = 0; pos < this->map->width * this->map->height; ++pos)
    {
        if (this->map->selected[pos] == 1)
        {
            if (this->map->tiles[pos]->tileType == TileType::RESIDENTIAL)
            {
                this->populationPool += this->map->tiles[pos]->population;
            }
            else if (this->map->tiles[pos]->tileType == TileType::COMMERCIAL)
            {
                this->employmentPool += this->map->tiles[pos]->population;
            }
            else if (this->map->tiles[pos]->tileType == TileType::FIRESTATION)
            {
                this->employmentPool += this->map->tiles[pos]->population;
            }
            else if (this->map->tiles[pos]->tileType == TileType::INDUSTRIAL)
            {
                this->employmentPool += this->map->tiles[pos]->population;
            }
            else if (this->map->tiles[pos]->tileType == TileType::LANDMARK)
            {
                this->employmentPool += this->map->tiles[pos]->population;
            }
            delete this->map->tiles[pos];
            this->map->tiles[pos] = tile.clone();
        }
    }

    return;
}

void City::shuffleTiles()
{
    while (this->shuffledTiles.size() < this->map->tiles.size())
    {
        this->shuffledTiles.push_back(0);
    }
    std::iota(shuffledTiles.begin(), shuffledTiles.end(), 1);
    std::random_shuffle(shuffledTiles.begin(), shuffledTiles.end());

    return;
}

void City::tileChanged()
{
    this->map->updateDirection(TileType::ROAD);
    this->map->findConnectedRegions(
        {   TileType::ROAD, TileType::RESIDENTIAL, TileType::COMMERCIAL, TileType::LANDMARK, 
            TileType::INDUSTRIAL, TileType::FIRESTATION, TileType::HOSPITAL,
            TileType::POWERPLANT, TileType::SEWAGEPLANT,TileType::WATERPLANT,
            TileType::WASTEMANAGEMENT},
        0);

    return;
}

void City::load(std::string cityName, std::map<std::string, Tile*> &tileAtlas)
{
    int width = 0;
    int height = 0;

    std::ifstream inputFile(cityName + "_cfg.dat", std::ios::in);

    std::string line;

    while (std::getline(inputFile, line))
    {
        std::istringstream lineStream(line);
        std::string key;
        if (std::getline(lineStream, key, '='))
        {
            std::string value;
            if (std::getline(lineStream, value))
            {
                if (key == "width")
                    width = std::stoi(value);
                else if (key == "height")
                    height = std::stoi(value);
                else if (key == "day")
                    this->day = std::stoi(value);
                else if (key == "populationPool")
                    this->populationPool = std::stod(value);
                else if (key == "employmentPool")
                    this->employmentPool = std::stod(value);
                else if (key == "population")
                    this->population = std::stod(value);
                else if (key == "employable")
                    this->employable = std::stod(value);
                else if (key == "birthRate")
                    this->birthRate = std::stod(value);
                else if (key == "deathRate")
                    this->deathRate = std::stod(value);
                else if (key == "funds")
                    this->funds = std::stod(value);
                else if (key == "earnings")
                    this->earnings = std::stod(value);
            }
            else
            {
                std::cerr << "Error, no value for key " << key << std::endl;
            }
        }
    }

    inputFile.close();

    this->map->load(cityName + "_map.dat", width, height, tileAtlas);
    tileChanged();

    return;
}

void City::save(std::string cityName)
{
    std::ofstream outputFile(cityName + "_cfg.dat", std::ios::out);

    outputFile << "width=" << this->map->width << std::endl;
    outputFile << "height=" << this->map->height << std::endl;
    outputFile << "day=" << this->day << std::endl;
    outputFile << "populationPool=" << this->populationPool << std::endl;
    outputFile << "employmentPool=" << this->employmentPool << std::endl;
    outputFile << "population=" << this->population << std::endl;
    outputFile << "employable=" << this->employable << std::endl;
    outputFile << "birthRate=" << this->birthRate << std::endl;
    outputFile << "deathRate=" << this->deathRate << std::endl;
    outputFile << "funds=" << this->funds << std::endl;
    outputFile << "earnings=" << this->earnings << std::endl;

    outputFile.close();

    this->map->save(cityName + "_map.dat");

    return;
}

void City::update(float dt)
{
    double popTotal = 0;
    double commercialRevenue = 0;
    double industrialRevenue = 0;

    /* Update the game time */
    this->currentTime += dt;
    if (this->currentTime < this->timePerDay)
        return;
    ++day;
    satisfaction = 0;
    this->currentTime = 0.0;

    if (day % 30 == 0)
    {
        this->funds += this->earnings;
        this->earnings = 0;
    }

    //set mediator
    mediator = new CityMediator(this);

    for (int i = 0; i < map->tiles.size(); ++i) {
        Tile* tile = map->tiles[i];
        tile->setMediator(mediator);
    }

    // Create the Distribute Population command
    DistributePopulation distributePopCmd(map, shuffledTiles, populationPool, employmentPool, 
                         popTotal, birthRate, deathRate, population, taxPolicy->getTaxRate());

    // Execute the command
    distributePopCmd.execute();

    // Create the Distribute Goods command
    CreateAndDistributeGoods command(map, shuffledTiles, industrialRevenue, commercialRevenue, taxPolicy->getTaxRate());
    // Executes the command, calling CDReceiver's update
    command.execute(); 

    SatisfactionCalculator sCalc(map,  getTaxPolicy(), population, satisfaction);
    sCalc.execute();

    DistributeResources DR(map);
    DR.execute();


    //Random chance that a house burns down
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(1, 1000000); // Define the range
    int random_number = distr(gen); // Generate a random number

    //random_number = day;
    if(random_number == 727){
        for (int i = 0; i < this->map->tiles.size(); ++i){
            
            Tile *tile = this->map->tiles[this->shuffledTiles[i]];

            if(tile != NULL && tile->tileType == TileType::RESIDENTIAL){
                tile->notify(TileType::FIRESTATION);
            }
        }
    }
    
    /* Adjust population pool for births and deaths. */
    this->populationPool += this->populationPool * (this->birthRate - this->deathRate);
    popTotal += this->populationPool;
 
    /* Adjust the employment pool for the changing population. */
    float newWorkers = (popTotal - this->population) * this->propCanWork;
    newWorkers *= newWorkers < 0 ? -1 : 1;
    this->employmentPool += newWorkers;
    this->employable += newWorkers;
    if(this->employmentPool < 0) this->employmentPool = 0;
    if(this->employable < 0) this->employable = 0;
 
    /* Update the city population. */
    this->population = popTotal;
 
    /* Calculate city income from tax. */
    this->earnings = this->taxPolicy->calculateTax((this->population - this->populationPool) * 15);
    this->earnings += this->taxPolicy->calculateTax(commercialRevenue);
    this->earnings += this->taxPolicy->calculateTax(industrialRevenue);
 
    return;
}


Memento* City::createMemento() {
    return new Memento(populationPool, employmentPool, population, employable, satisfaction, earnings, funds, day, map->clone());
}

void City::loadMemento(Memento* memento) {
    if (memento) {
        populationPool = memento->populationPool;
        employmentPool = memento->employmentPool;
        population = memento->population;
        employable = memento->employable;
        satisfaction = memento->satisfaction;
        earnings = memento->earnings;
        funds = memento->funds;
        day = memento->day;
        delete map;
        map = memento->map;  // Assuming `Map` has a deep copy constructor
    }
}
void City::setCaretaker(Caretaker* caretaker) {
    this->caretaker = caretaker;  // Set the caretaker pointer
}

void City::setMediator(CityMediator* md){
    this->mediator = md;
}
