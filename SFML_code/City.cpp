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


// /City::City() : day(0), lastMementoDay(-1), populationPool(0), employmentPool(0), population(0), employable(0), satisfaction(0), earnings(0), funds(0), map(nullptr), taxPolicy(nullptr) {}
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
    return "";
}

void City::bulldoze(Tile &tile)
{
    /* Replace the selected tiles on the map with the tile and
     * update populations etc accordingly */
    for (int pos = 0; pos < (int)(this->map->width * this->map->height); ++pos)
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
                else if (key == "residentialTax")
                    this->residentialTax = std::stod(value);
                else if (key == "commercialTax")
                    this->commercialTax = std::stod(value);
                else if (key == "industrialTax")
                    this->industrialTax = std::stod(value);
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
    outputFile << "residentialTax=" << this->residentialTax << std::endl;
    outputFile << "commercialTax=" << this->commercialTax << std::endl;
    outputFile << "industrialTax=" << this->industrialTax << std::endl;
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
    this->currentTime = 0.0;
    //  if (day != lastMementoDay) {
    //         Memento* dailyMemento = createMemento();
    //         caretaker.storeMemento(dailyMemento);  // Store the daily Memento in Caretaker
    //         lastMementoDay = day; 
       // Notify Memento to store the state in Caretaker at the start of each new day
    // //my tests    
    // std::cout << "Saved Memento for Day " << day << "\n";
    // std::cout << "  Population Pool: " << getHomeless() << "\n";
    // std::cout << "  Employment Pool: " << getUnemployed() << "\n";
    // std::cout << "  Population: " << population << "\n";
    // std::cout << "  Employable: " << employable << "\n";
    // std::cout << "  Satisfaction: " << satisfaction << "\n";
    // std::cout << "  Earnings: " << earnings << "\n";
    // std::cout << "  Funds: " << funds << "\n";
    if (day % 30 == 0)
    {
        this->funds += this->earnings;
        this->earnings = 0;
    }

    //set mediator
    CityMediator* mediator = new CityMediator(this);
    for (int pos = 0; pos < (int)(this->map->width * this->map->height); ++pos){
        Tile *tile = this->map->tiles[pos];

        if(tile->tileType == TileType::VOID || tile->tileType == TileType::GRASS || tile->tileType == TileType::WATER){
            continue;
        }

        tile->setMediator(mediator);
    }

    /* Run first pass of tile updates. Mostly handles pool distribution. */
    DReceiver dReceiver(map, shuffledTiles, populationPool, employmentPool, 
                         popTotal, birthRate, deathRate, commercialTax, 
                         industrialTax, population);

    // Create the DistributeResources command
    DistributeResources distributeResourcesCmd(&dReceiver);

    // Execute the command
    distributeResourcesCmd.execute();

    /* Run second pass. Mostly handles goods manufacture */
    CDReceiver receiver(map, shuffledTiles, industrialRevenue, commercialRevenue, commercialTax, industrialTax);
    CreateAndDistributeGoods command(&receiver);
    command.execute();  // Executes the command, calling CDReceiver's update

    earnings += industrialRevenue + commercialRevenue;

    //Other Commands needs implementing 
    


    //Random chance that a house burns down
    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> distr(1, 1000000); // Define the range
    int random_number = distr(gen); // Generate a random number

    //random_number = day;
    if(random_number == 727){
        for (int i = 0; i < (int)this->map->tiles.size(); ++i){
            
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

    //Notify Memento to store the state in Caretaker at the start of each new day
    // if (caretaker) 
    // {
    //     caretaker->storeMemento(createMemento());
    //     lastMementoDay = day;
    // }

 
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
