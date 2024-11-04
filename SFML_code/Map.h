#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>

#include <string>
#include <map>
#include <vector>

#include "Tile.h"

/**
 * @class Map
 * @brief Represents a map composed of tiles within the simulation.
 * 
 * The Map class manages the grid of tiles, supports selection, drawing, 
 * loading, and saving, and performs operations to manage connectivity 
 * and direction of various tiles.
 */
class Map
{
private:
    /**
     * @brief Depth-first search helper function for region identification.
     * 
     * This function performs a depth-first search to label connected regions
     * of tiles that match types in the whitelist, assisting in connectivity checks.
     * 
     * @param whitelist A vector of tile types that can be traversed.
     * @param pos The starting position of the search.
     * @param label The label assigned to the connected region.
     * @param type The type of region being searched.
     */
    void depthfirstsearch(std::vector<TileType> &whitelist, sf::Vector2i pos, int label, int type);

public:
    /** @brief Width of the map in tiles. */
    unsigned int width;

    /** @brief Height of the map in tiles. */
    unsigned int height;

    /** @brief Vector of pointers to all tiles on the map. */
    std::vector<Tile*> tiles;

    /** @brief Vector representing resource levels on each tile. */
    std::vector<int> resources;

    /** @brief Size of each tile in pixels. */
    unsigned int tileSize;

    /** 
     * @brief Selection status for tiles: 
     * 0 = Deselected, 1 = Selected, 2 = Invalid.
     */
    std::vector<char> selected;

    /** @brief Number of tiles currently selected. */
    unsigned int numSelected;

    /** @brief Array representing the number of regions by type. */
    void select(sf::Vector2i start, sf::Vector2i end, std::vector<TileType> blacklist);

    /**
     * @brief Selects tiles within specified bounds that are not in the blacklist.
     * 
     * @param start Starting position of the selection.
     * @param end Ending position of the selection.
     * @param blacklist Vector of tile types to exclude from selection.
     */
    void clearSelected();

    /**
     * @brief Deselects all tiles.
     */
    unsigned int numRegions[1];

    /**
     * @brief Loads the map from a file.
     * 
     * @param filename The file path from which to load the map.
     * @param width Width of the map in tiles.
     * @param height Height of the map in tiles.
     * @param tileAtlas A map of tile names to Tile objects used to populate the map.
     */
    void load(const std::string &filename, unsigned int width, unsigned int height,
              std::map<std::string, Tile*> &tileAtlas);

    /**
     * @brief Saves the current map state to a file.
     * 
     * @param filename The file path where the map will be saved.
     */
    void save(const std::string &filename);

    /**
     * @brief Draws the map onto the specified window.
     * 
     * @param window The window where the map is rendered.
     * @param dt Delta time for frame-based updates.
     */
    void draw(sf::RenderWindow &window, float dt);

    /**
     * @brief Checks if two positions in the map are connected through specified tile types.
     * 
     * Finds and labels connected regions based on traversable tile types in the whitelist.
     * 
     * @param whitelist Vector of tile types that can be traversed.
     * @param type The type of connection being checked.
     */
    void findConnectedRegions(std::vector<TileType> whitelist, int type);

    /**
     * @brief Updates the direction of directional tiles to ensure correct orientation.
     * 
     * This method is used to orient tiles such as roads, rivers, or power lines based
     * on neighboring tiles.
     * 
     * @param tileType The tile type for which to update direction.
     */
    void updateDirection(TileType tileType);

    /**
     * @brief Default constructor that initializes a blank map.
     */
    Map()
    {
        this->numSelected = 0;
        this->tileSize = 8;
        this->width = 0;
        this->height = 0;
        this->numRegions[0] = 1;
    }

    /**
     * @brief Constructor that loads a map from a specified file.
     * 
     * @param filename The file path from which to load the map.
     * @param width Width of the map in tiles.
     * @param height Height of the map in tiles.
     * @param tileAtlas A map of tile names to Tile objects used to populate the map.
     */
    Map(const std::string &filename, unsigned int width, unsigned int height,
        std::map<std::string, Tile*> &tileAtlas)
    {
        this->numSelected = 0;
        this->tileSize = 8;
        load(filename, width, height, tileAtlas);
    }

     /**
     * @brief Creates a clone of the current map object.
     * 
     * @return A pointer to the newly cloned Map object.
     */
    Map* clone();
};

#endif
