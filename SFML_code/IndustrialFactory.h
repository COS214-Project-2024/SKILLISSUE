#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Industrial.h"

/**
 * @class IndustrialFactory
 * @brief Factory class for creating Industrial tiles.
 * 
 * The IndustrialFactory class follows the factory pattern, providing methods to
 * instantiate Industrial tiles with specified textures and animations.
 */
class IndustrialFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new Industrial tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating an Industrial tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the industrial tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Industrial tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
 /**
     * @brief Public method for creating and returning a new Industrial tile.
     * 
     * This method serves as the main interface for creating Industrial tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Industrial tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */