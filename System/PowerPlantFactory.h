#ifndef POWERLANTFACTORY_H
#define POWERPLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "PowerPlant.h"

/**
 * @class PowerPlantFactory
 * @brief Factory class for creating PowerPlant tiles.
 * 
 * The PowerPlantFactory class follows the factory pattern, providing methods to
 * instantiate PowerPlant tiles with specified textures and animations.
 */
class PowerPlantFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new PowerPlant tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a PowerPlant tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the power plant tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created PowerPlant tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
    
public:
    /**
     * @brief Public method for creating and returning a new PowerPlant tile.
     * 
     * This method serves as the main interface for creating PowerPlant tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created PowerPlant tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */