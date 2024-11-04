#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class WasteManagement
 * @brief Represents a waste management tile in the simulation.
 * 
 * The WasteManagement class inherits from Tile and defines properties and behaviors
 * specific to waste management facilities, which handle waste processing within the simulation.
 */
class WasteManagement : public Tile
{
public:

    /**
     * @brief Constructs a WasteManagement tile with a given texture and animations.
     * 
     * Initializes the WasteManagement tile with the specified texture and animation sequence,
     * setting it up for rendering and interaction within the simulation.
     * 
     * @param texture Reference to the texture applied to the waste management tile.
     * @param animations Vector containing animations associated with this tile.
     */
    WasteManagement(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif  /* WASTEMANAGEMENT_H */