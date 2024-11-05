#ifndef POWERPLANT_H
#define POWERPLANT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class PowerPlant
 * @brief Represents a power plant tile in the simulation.
 * 
 * The PowerPlant class inherits from Tile and defines properties and behaviors
 * specific to power plants, which are responsible for generating energy within the simulation.
 */
class PowerPlant : public Tile
{
public:

     /**
     * @brief Constructs a PowerPlant tile with a given texture and animations.
     * 
     * Initializes the PowerPlant tile with the specified texture and animation sequence,
     * setting it up for rendering and functionality within the simulation.
     * 
     * @param texture Reference to the texture applied to the power plant tile.
     * @param animations Vector containing animations associated with this tile.
     */
    PowerPlant(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* POWERPLANT_H */