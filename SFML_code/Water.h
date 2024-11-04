#ifndef WATER_H
#define WATER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Water
 * @brief Represents a water tile in the simulation.
 * 
 * The Water class inherits from Tile and defines properties and behaviors specific to water tiles,
 * which may be used to represent natural water bodies or resources within the simulation.
 */
class Water : public Tile
{
public:

    /**
     * @brief Constructs a Water tile with a given texture and animations.
     * 
     * Initializes the Water tile with the specified texture and animation sequence,
     * setting it up for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the water tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Water(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */