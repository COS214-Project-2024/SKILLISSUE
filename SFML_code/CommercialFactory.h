#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Commercial.h"

/**
 * @class CommercialFactory
 * @brief Factory class for creating Commercial tiles.
 * 
 * The CommercialFactory class is responsible for creating instances of 
 * Commercial tiles, following the factory pattern to encapsulate the instantiation process.
 */
class CommercialFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new Commercial tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the implementation for creating
     * a Commercial tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Commercial tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:

    /**
     * @brief Creates and returns a new Commercial tile.
     * 
     * This method is publicly accessible and uses the factory pattern to create
     * a new Commercial tile with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Commercial tile.
     */ 
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */