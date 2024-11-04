#ifndef GRASS_H
#define GRASS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Grass
 * @brief Represents a grass tile in the simulation.
 * 
 * The Grass class inherits from Tile and is used to define properties
 * specific to grass tiles, typically representing natural terrain.
 */
class Grass : public Tile
{
public:

    /**
     * @brief Constructs a Grass tile with a given texture and animations.
     * 
     * Initializes the Grass tile with the specified texture and animations,
     * setting it up for rendering within the simulation.
     * 
     * @param texture Reference to the texture applied to the grass tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Grass(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* GRASS_H */