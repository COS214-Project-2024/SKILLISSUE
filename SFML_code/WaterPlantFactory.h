#ifndef WATERPLANTFACTORY_H
#define WATERPLANTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "WaterPlant.h"

/**
 * @class WaterPlantFactory
 * @brief Factory class for creating WaterPlant tiles.
 * 
 * The WaterPlantFactory class follows the factory pattern, providing methods to
 * instantiate WaterPlant tiles with specified textures and animations.
 */
class WaterPlantFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new WaterPlant tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a WaterPlant tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the water plant tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created WaterPlant tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new WaterPlant tile.
     * 
     * This method serves as the main interface for creating WaterPlant tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created WaterPlant tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* WATERPLANTFACTORY_H  */
