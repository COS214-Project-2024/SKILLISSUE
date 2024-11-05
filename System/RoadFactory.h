#ifndef ROADFACTORY_H
#define ROADFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Road.h"

/**
 * @class RoadFactory
 * @brief Factory class for creating Road tiles.
 * 
 * The RoadFactory class follows the factory pattern, providing methods to
 * instantiate Road tiles with specified textures and animations.
 */
class RoadFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new Road tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a Road tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the road tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Road tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new Road tile.
     * 
     * This method serves as the main interface for creating Road tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Road tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */