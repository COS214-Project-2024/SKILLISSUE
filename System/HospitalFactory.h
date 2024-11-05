#ifndef HOSPITALTFACTORY_H
#define HOSPITALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Hospital.h"

/**
 * @class HospitalFactory
 * @brief Factory class for creating Hospital tiles.
 * 
 * The HospitalFactory class follows the factory pattern, providing methods to
 * instantiate Hospital tiles with specified textures and animations.
 */
class HospitalFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new Hospital tile with the specified texture and animations.
     * 
     * This protected method is overridden to implement the creation of
     * a Hospital tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the hospital tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Hospital tile.
     */ 
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new Hospital tile.
     * 
     * This method serves as the main interface for creating Hospital tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Hospital tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */