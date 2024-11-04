#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Landmark.h"

/**
 * @class LandmarkFactory
 * @brief Factory class for creating Landmark tiles.
 * 
 * The LandmarkFactory class follows the factory pattern, providing methods to
 * instantiate Landmark tiles with specified textures and animations.
 */
class LandmarkFactory : public TileFactory
{
protected:
 /**
     * @brief Creates a new Landmark tile with the specified texture and animations.
     * 
     * This protected method is overridden to provide the specific implementation
     * for creating a Landmark tile with the given texture and animations.
     * 
     * @param texture Reference to the texture to apply to the landmark tile.
     * @param animations Vector containing animations for the tile.
     * @return A pointer to the created Landmark tile.
     */
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
/**
     * @brief Public method for creating and returning a new Landmark tile.
     * 
     * This method serves as the main interface for creating Landmark tiles, using
     * the factory pattern to instantiate them with the provided texture and animations.
     * 
     * @param texture Reference to the texture for the tile.
     * @param animations Vector of animations associated with the tile.
     * @return A pointer to the newly created Landmark tile.
     */
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */