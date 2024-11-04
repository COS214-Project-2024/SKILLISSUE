#ifndef FOREST_H
#define FOREST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Forest
 * @brief Represents a Forest tile in the game.
 *
 * The Forest class inherits from Tile and represents a specific type of tile
 * with forest graphics. It uses an SFML texture and a series of animations 
 * to visually represent the forest.
 */

class Forest : public Tile
{
public:

/**
     * @brief Constructs a Forest tile with a texture and animations.
     * 
     * Initializes the Forest tile with the given SFML texture and a vector of
     * animations, which define its visual representation and behavior in the game.
     * 
     * @param texture Reference to the SFML texture to be applied to the Forest tile.
     * @param animations A vector of Animation objects to be used for the tile's animation.
     */
    Forest(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */