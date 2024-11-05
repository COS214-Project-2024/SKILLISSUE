#ifndef FIRESTATION_H
#define FIRESTATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Firestation
 * @brief Represents a fire station tile in the simulation.
 * 
 * The Firestation class inherits from Tile and defines properties and behaviors
 * specific to fire stations, such as managing emergency response coverage.
 */
class Firestation : public Tile
{
public:

    /**
     * @brief Constructs a Firestation tile with a given texture and animations.
     * 
     * Initializes the Firestation with the specified texture and animation sequence,
     * making it ready for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the fire station tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Firestation(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */