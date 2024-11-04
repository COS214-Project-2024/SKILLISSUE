#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Tile.h"
#include "Grass.h"
#include "Gui.h"

#include "TileFactory.h"
#include "GrassFactory.h"
#include "ForestFactory.h"
#include "WaterFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"
#include "RoadFactory.h"
#include "HospitalFactory.h"
#include "PowerPlantFactory.h"
#include "SewagePlantFactory.h"
#include "WasteManagementFactory.h"
#include "WaterPlantFactory.h"
#include "FirestationFactory.h"

class GameState;

/**
 * @class Game
 * @brief Manages the main game loop, state stack, and resources.
 *
 * The Game class initializes and manages the game window, resources like textures
 * and tiles, game states, and factories for tile creation. It provides methods
 * to control game states, load assets, and run the main game loop.
 */

class Game
{
private:
 
    /**
     * @brief Loads textures into the texture manager.
     *
     * This method is responsible for loading all required textures into the
     * `texmgr` so that they can be accessed throughout the game.
     */
    void loadTextures();

    /**
     * @brief Initializes tile objects in the game.
     *
     * Loads and sets up tile objects and adds them to the `tileAtlas` for use in the game.
     */
    void loadTiles();

    /**
     * @brief Loads stylesheets for GUI elements.
     *
     * This method sets up GUI styles by loading stylesheets into the `stylesheets` map.
     */
    void loadStylesheets();

    /**
     * @brief Loads font resources.
     *
     * This method loads fonts used in GUI elements and stores them in the `fonts` map.
     */
    void loadFonts();

    /**
     * @brief Initializes factory instances for various tile types.
     *
     * Creates and stores instances of different tile factories in the `Factory` map.
     */
    void loadFactories();

public:

    /** @brief Tile size used in the game, set to 8 pixels. */
    const static int tileSize = 8;

    /** @brief Stack that holds the game states. */
    std::stack<GameState*> states;

    /** @brief SFML RenderWindow object for displaying the game. */
    sf::RenderWindow window;

    /** @brief Texture manager responsible for managing game textures. */
    TextureManager texmgr;

    /** @brief Background sprite displayed in the game window. */
    sf::Sprite background;

    /** @brief Map containing tile prototypes accessible by name. */
    std::map<std::string, Tile*> tileAtlas;

    /** @brief Stylesheets for different GUI styles used in the game. */
    std::map<std::string, GuiStyle> stylesheets;

    /** @brief Map of fonts accessible by name for GUI text. */
    std::map<std::string, sf::Font> fonts;

    /** @brief Map of tile factories, each responsible for creating a specific tile type. */
    std::map<std::string, TileFactory*> Factory;

    /**
     * @brief Adds a new game state to the stack.
     * 
     * @param state Pointer to the GameState object to be pushed.
     */
    void pushState(GameState* state);

    /**
     * @brief Removes the current game state from the stack.
     */
    void popState();

    /**
     * @brief Replaces the current game state with a new one.
     * 
     * @param state Pointer to the GameState object to be set as the new state.
     */
    void changeState(GameState* state);

    /**
     * @brief Returns the current game state without removing it.
     * 
     * @return Pointer to the current GameState object.
     */
    GameState* peekState();

    /**
     * @brief The main game loop.
     *
     * Runs the game loop, managing updates and rendering, as well as handling game state transitions.
     */
    void gameLoop();

    /**
     * @brief Constructs the Game object.
     *
     * Initializes the game by setting up the window and loading necessary resources.
     */
    Game();

    /**
     * @brief Destructor for the Game object.
     *
     * Cleans up resources and handles any necessary cleanup upon game shutdown.
     */
    ~Game();
};

#endif
