#ifndef FORESTFACTORY_H
#define FORESTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Forest.h"

/**
 * @class ForestFactory
 * @brief Factory class responsible for creating Forest tiles.
 *
 * This class inherits from TileFactory and provides a specific implementation
 * for creating tiles of type Forest, using a texture and animations as input.
 */

class ForestFactory : public TileFactory
{
protected:
/**
     * @brief Creates a new Forest tile.
     * 
     * This method is responsible for creating an instance of a Forest tile
     * using the provided texture and animations. It is intended to be called
     * only within the factory, as part of the creation process.
     * 
     * @param texture Reference to the SFML texture to be applied to the tile.
     * @param animations A vector of Animation objects to be used for the tile's animation.
     * @return Pointer to the created Tile object.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:

/**
     * @brief Public method to create a new Forest tile.
     * 
     * This method is the main entry point for creating Forest tiles. It 
     * calls the protected CreateTile method and provides access to external
     * classes to create Forest tiles using this factory.
     * 
     * @param texture Reference to the SFML texture to be applied to the tile.
     * @param animations A vector of Animation objects to be used for the tile's animation.
     * @return Pointer to the created Tile object.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */