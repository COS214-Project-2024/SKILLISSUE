#ifndef WATERPLANT_H
#define WATERPLANT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class WaterPlant
 * @brief Represents a water treatment plant tile in the simulation.
 * 
 * The WaterPlant class inherits from Tile and defines properties and behaviors specific to water
 * treatment plants, which are responsible for managing and supplying water resources within the simulation.
 */
class WaterPlant : public Tile
{
public:

    /**
     * @brief Constructs a WaterPlant tile with a given texture and animations.
     * 
     * Initializes the WaterPlant tile with the specified texture and animation sequence,
     * setting it up for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the water treatment plant tile.
     * @param animations Vector containing animations associated with this tile.
     */
    WaterPlant(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* WATERPLANT_H  */