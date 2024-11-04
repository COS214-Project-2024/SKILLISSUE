#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Residential
 * @brief Represents a residential tile in the simulation.
 * 
 * The Residential class inherits from Tile and defines properties and behaviors
 * specific to residential zones, where citizens reside within the simulation.
 */
class Residential : public Tile
{
public:

    /**
     * @brief Constructs a Residential tile with a given texture and animations.
     * 
     * Initializes the Residential tile with the specified texture and animation sequence,
     * setting it up for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the residential tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Residential(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */