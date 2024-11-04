#ifndef SEWAGEPLANTFACTORY_H
#define SEWAGEPLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "SewagePlant.h"

/**
 * @class SewagePlantFactory
 * @brief Factory class for creating SewagePlant tiles.
 * 
 * The SewagePlantFactory class follows the factory pattern, providing methods to
 * instantiate SewagePlant tiles with specified textures and animations.
 */
class SewagePlantFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new SewagePlant tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a SewagePlant tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the sewage plant tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created SewagePlant tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new SewagePlant tile.
     * 
     * This method serves as the main interface for creating SewagePlant tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created SewagePlant tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */