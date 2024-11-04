#ifndef WATERFACTORY_H
#define WATERFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Water.h"

/**
 * @class WaterFactory
 * @brief Factory class for creating Water tiles.
 * 
 * The WaterFactory class follows the factory pattern, providing methods to
 * instantiate Water tiles with specified textures and animations.
 */
class WaterFactory : public TileFactory
{
protected:
/**
     * @brief Creates a new Water tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a Water tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the water tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Water tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new Water tile.
     * 
     * This method serves as the main interface for creating Water tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Water tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* WATERFACTORY_H */