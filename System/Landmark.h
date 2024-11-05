#ifndef LANDMARK_H
#define LANDMARK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Landmark
 * @brief Represents a landmark tile in the simulation.
 * 
 * The Landmark class inherits from Tile and is used to define properties and behaviors
 * specific to landmark tiles, which may contribute to aesthetics, tourism, or city appeal.
 */
class Landmark : public Tile
{
public:
    /**
     * @brief Constructs a Landmark tile with a given texture and animations.
     * 
     * Initializes the Landmark tile with the specified texture and animation sequence,
     * setting it up for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the landmark tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Landmark(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* LANDMARK_H */