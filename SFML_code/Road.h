#ifndef ROAD_H
#define ROAD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Road
 * @brief Represents a road tile in the simulation.
 * 
 * The Road class inherits from Tile and defines properties and behaviors
 * specific to road tiles, which facilitate transportation and connectivity within the simulation.
 */
class Road : public Tile
{
public:

    /**
     * @brief Constructs a Road tile with a given texture and animations.
     * 
     * Initializes the Road tile with the specified texture and animation sequence,
     * setting it up for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the road tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Road(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* ROAD_H */