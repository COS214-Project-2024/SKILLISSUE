#ifndef FIRESTATIONFACTORY_H
#define FIRESTATIONFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Firestation.h"


/**
 * @class FirestationFactory
 * @brief Factory class for creating Firestation tiles.
 * 
 * The FirestationFactory class implements the factory pattern, providing a method to
 * instantiate Firestation tiles with specified textures and animations.
 */
class FirestationFactory : public TileFactory
{
protected:
    /**
     * @brief Creates a new Firestation tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a Firestation tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the fire station tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Firestation tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    /**
     * @brief Public method for creating and returning a new Firestation tile.
     * 
     * This method serves as the main interface for creating Firestation tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Firestation tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */