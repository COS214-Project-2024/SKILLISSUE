#ifndef GRASSFACTORY_H
#define GRASSFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Grass.h"

/**
 * @class GrassFactory
 * @brief Factory class for creating Grass tiles.
 * 
 * The GrassFactory class follows the factory pattern, providing methods to
 * instantiate Grass tiles with specified textures and animations.
 */
class GrassFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new Grass tile with the specified texture and animations.
     * 
     * This protected method is overridden to implement the creation of
     * a Grass tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the grass tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Grass tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new Grass tile.
     * 
     * This method serves as the main interface for creating Grass tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Grass tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GRASSFACTORY_H */