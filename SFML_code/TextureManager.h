#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

/**
 * @class TextureManager
 * @brief Manages loading and retrieving textures for use in the simulation.
 * 
 * The TextureManager class maintains a collection of textures, allowing textures
 * to be loaded from files and retrieved by name for efficient texture management.
 */
class TextureManager
{
private:
    /** @brief Map storing textures by name for easy access. */
    std::map<std::string, sf::Texture> textures;

public:
    
    /**
     * @brief Loads a texture from a file and stores it with a given name.
     * 
     * If the texture is successfully loaded, it is stored in the texture map 
     * with the specified name, allowing it to be retrieved later.
     * 
     * @param name The name used to identify the texture.
     * @param filename The path to the texture file to be loaded.
     */
    void loadTexture(const std::string &name, const std::string &filename);

    /**
     * @brief Retrieves a reference to a texture by its name.
     * 
     * This function provides access to a texture that was previously loaded and
     * stored with the specified name.
     * 
     * @param texture The name of the texture to retrieve.
     * @return A reference to the requested sf::Texture object.
     */
    sf::Texture &getRef(const std::string &texture);

    // /* Constructor */
    // TextureManager();

};

#endif /* TEXTURE_MANAGER_HPP */
