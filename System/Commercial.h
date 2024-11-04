#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class Commercial
 * @brief Represents a commercial tile in the simulation.
 * 
 * The Commercial class inherits from Tile and is used to define properties and
 * behaviors specific to commercial zones within the simulation.
 */
class Commercial : public Tile
{
public:

    /**
     * @brief Constructs a Commercial tile with a given texture and animations.
     * 
     * @param texture Reference to the texture applied to the commercial tile.
     * @param animations Vector containing animations associated with this tile.
     */
    Commercial(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* COMMERCIAL_H */