#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Industrial
 * @brief Represents an industrial tile in the simulation.
 * 
 * The Industrial class inherits from Tile and defines properties and behaviors
 * specific to industrial zones, typically contributing to production or resource generation.
 */
class Industrial : public Tile
{
public:

   /**
     * @brief Constructs an Industrial tile with a given texture and animations.
     * 
     * Initializes the Industrial tile with the specified texture and animation sequence,
     * setting it up for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the industrial tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Industrial(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */