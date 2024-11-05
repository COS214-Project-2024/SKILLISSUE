#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Map.h"
#include "City.h"
#include "Gui.h"
#include "Caretaker.h"
#include "ResourceManager.h"

/**
 * @enum ActionState
 * @brief Represents the current action state in the editor.
 *
 * This enum defines possible action states for user interactions, such as
 * panning the view or selecting objects in the editor.
 */
enum class ActionState { NONE, PANNING, SELECTING };

/**
 * @class GameStateEditor
 * @brief Represents the editor state of the game.
 *
 * GameStateEditor is a derived class of GameState that provides functionalities
 * for editing the game environment, such as map editing, city management, and 
 * GUI controls. It handles user input specific to editing actions, manages the
 * editor’s camera views, and tracks game time.
 */
class GameStateEditor : public GameState
{
    private:
    
    /** @brief The current action state for user interactions (e.g., panning, selecting). */
    ActionState actionState;
    
    /** @brief The view for displaying the game world in the editor. */
    sf::View gameView;

    /** @brief The view for displaying GUI elements. */
    sf::View guiView;

    /** @brief Sprite used to display the pause overlay. */
    sf::Sprite pauseSprite;
   
    /** @brief Tracks the in-game day. */
    int day = 0;
    
    /** @brief Manages the city layout and related functionalities. */
	City city;

    /** @brief Pointer to a Caretaker object that manages undo functionality. */
    Caretaker* undos = new Caretaker();
    ResourceManager proxy;

    /** @brief Anchor point for panning the view. */
	sf::Vector2i panningAnchor;

    /** @brief Current zoom level of the editor view. */
    float zoomLevel;

    /** @brief Starting position of the selection box. */
    sf::Vector2i selectionStart;

    /** @brief Ending position of the selection box. */
    sf::Vector2i selectionEnd;
 
    /** @brief The tile currently selected in the editor. */
    Tile* currentTile;

    /** @brief GUI elements for the editor interface. */
    std::map<std::string, Gui> guiSystem;

    /** @brief GUI elements for the pause menu. */
    std::map<std::string, Gui> guiPauseSystem;

    /** @brief Indicates whether the game is paused. */
    bool paused = false;

    /**
     * @brief Pauses the game.
     *
     * This method toggles the paused state of the game, displaying the pause menu
     * and halting game updates.
     */
    void pauseGame();

    /** @brief Pointer to the initial state of the map. */
    Map* beginMap;
    
    public:

    /**
     * @brief Draws the editor state to the screen.
     * 
     * @param dt Delta time since the last frame, used for smooth rendering.
     */
    virtual void draw(const float dt);

    /**
     * @brief Updates the editor state.
     * 
     * @param dt Delta time since the last frame, used for smooth updates.
     */
    virtual void update(const float dt);

    /**
     * @brief Handles user input for the editor.
     * 
     * Processes input events specific to the editor, including camera movement,
     * tile selection, and other editing actions.
     */
    virtual void handleInput();

    /**
     * @brief Retrieves information about the editor state.
     * 
     * Provides details or identifier of the current editor state.
     */
    void getState();

    /**
     * @brief Constructs a new GameStateEditor instance.
     * 
     * @param game Pointer to the main Game instance.
     */
    GameStateEditor(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */
