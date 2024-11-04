#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Gui.h"
#include <map>
#include <string>

/**
 * @class GameStateStart
 * @brief Represents the initial state of the game when it starts.
 *
 * GameStateStart is a derived class of GameState that provides functionality
 * for displaying the start screen, including GUI elements such as menus,
 * and handles the transition to other game states when starting the game.
 */
class GameStateStart : public GameState
{
private:

    /** @brief The view used for displaying the start screen. */
    sf::View view;

    /** @brief GUI elements for the start screen. */
    std::map<std::string, Gui> guiSystem;

    /**
     * @brief Loads the game resources or settings for the start screen.
     *
     * This method initializes any resources or settings needed when the game
     * is starting, such as loading configurations or preparing the GUI.
     */
    void loadgame();

public:

    /**
     * @brief Draws the start screen to the display.
     *
     * Renders the GUI elements and any visuals associated with the start state.
     * @param dt Delta time since the last frame, used for smooth rendering.
     */
    virtual void draw(const float dt);

    /**
     * @brief Updates the start state.
     *
     * Updates animations, GUI interactions, or other elements on the start screen.
     * @param dt Delta time since the last frame, used for smooth updating.
     */
    virtual void update(const float dt);

    /**
     * @brief Handles user input for the start state.
     *
     * Processes input events specific to the start screen, allowing the player to
     * interact with the menu or begin the game.
     */
    virtual void handleInput();

    /**
     * @brief Retrieves information about the start state.
     *
     * Provides details or an identifier of the current start state.
     */
    void getState();

    /**
     * @brief Constructs a new GameStateStart instance.
     *
     * @param game Pointer to the main Game instance.
     */
    GameStateStart(Game *game);
};

#endif /* GAME_STATE_START_HPP */
