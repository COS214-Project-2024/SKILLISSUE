#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

/**
 * @class SewagePlant
 * @brief Represents a sewage treatment plant tile in the simulation.
 * 
 * The SewagePlant class inherits from Tile and defines properties and behaviors
 * specific to sewage plants, responsible for waste treatment within the simulation.
 */
class SewagePlant : public Tile
{
public:

     /**
     * @brief Constructs a SewagePlant tile with a given texture and animations.
     * 
     * Initializes the SewagePlant tile with the specified texture and animation sequence,
     * setting it up for rendering and functionality within the simulation.
     * 
     * @param texture Reference to the texture applied to the sewage plant tile.
     * @param animations Vector containing animations associated with this tile.
     */
    SewagePlant(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* SEWAGEPLANT_H */