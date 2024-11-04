#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Residential.h"

/**
 * @class ResidentialFactory
 * @brief Factory class for creating Residential tiles.
 * 
 * The ResidentialFactory class follows the factory pattern, providing methods to
 * instantiate Residential tiles with specified textures and animations.
 */
class ResidentialFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new Residential tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a Residential tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the residential tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Residential tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new Residential tile.
     * 
     * This method serves as the main interface for creating Residential tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Residential tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */