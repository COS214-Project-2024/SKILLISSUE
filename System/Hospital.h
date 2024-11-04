#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Hospital
 * @brief Represents a hospital tile in the simulation.
 * 
 * The Hospital class inherits from Tile and is used to define properties
 * and behaviors specific to hospital tiles, which are responsible for 
 * health-related services within the simulation.
 */
class Hospital : public Tile
{
public:

    /**
     * @brief Constructs a Hospital tile with a given texture and animations.
     * 
     * Initializes the Hospital tile with the specified texture and animation sequence,
     * setting it up for rendering and functionality within the simulation.
     * 
     * @param texture Reference to the texture applied to the hospital tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Hospital(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */