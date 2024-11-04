#ifndef TILEFACTORY_H
#define TILEFACTORY_H

#include <SFML/Graphics.hpp>
#include "Tile.h"

/**
 * @class TileFactory
 * @brief Abstract base factory class for creating Tile objects.
 * 
 * The TileFactory class defines the framework for tile creation, following the
 * factory pattern, allowing derived factories to create various types of tiles.
 */
class TileFactory
{
protected:
    /**
     * @brief Pure virtual function to create a specific type of Tile.
     * 
     * This method must be implemented by derived classes to instantiate tiles
     * of a particular type with a specified texture and animations.
     * 
     * @param texture Reference to the texture to apply to the tile.
     * @param animations Vector containing animations associated with the tile.
     * @return A pointer to the created Tile object.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations) = 0;
public:
    /**
     * @brief Creates and returns a new Tile by delegating to CreateTile.
     * 
     * This method provides the main interface for tile creation, using the
     * factory pattern to instantiate tiles with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Tile object.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */