#ifndef WASTEMANAGEMENTFACTORY_H
#define WASTEMANAGEMENTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "WasteManagement.h"

/**
 * @class WasteManagementFactory
 * @brief Factory class for creating WasteManagement tiles.
 * 
 * The WasteManagementFactory class follows the factory pattern, providing methods to
 * instantiate WasteManagement tiles with specified textures and animations.
 */
class WasteManagementFactory : public TileFactory
{
protected:
   /**
     * @brief Creates a new WasteManagement tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a WasteManagement tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the waste management tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created WasteManagement tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new WasteManagement tile.
     * 
     * This method serves as the main interface for creating WasteManagement tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created WasteManagement tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* WASTEMANAGEMENTFACTORY_H */