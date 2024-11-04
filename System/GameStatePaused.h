#ifndef GAMESTATEPAUSED_H
#define GAMESTATEPAUSED_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Gui.h"
#include <map>
#include <string>

/**
 * @class GameStatePaused
 * @brief Represents the paused state of the game.
 *
 * GameStatePaused is a derived class of GameState that provides functionality
 * for managing the game's pause state. It displays a paused screen, manages the
 * GUI elements for the pause menu, and allows the user to resume the game.
 */
class GameStatePaused : public GameState
{
private:
    
    /** @brief The view used for displaying the paused screen. */
    sf::View view;

    /** @brief GUI elements for the pause menu system. */
    std::map<std::string, Gui> guiSystem;

    /** @brief The previous game state that was active before pausing. */
    GameState* state;

    /**
     * @brief Resumes the game from the paused state.
     *
     * This method restores the game to its previous state by resuming
     * gameplay and removing the pause overlay.
     */
    void resumeGame();

public:

    /**
     * @brief Draws the paused state to the screen.
     *
     * Renders the pause menu and any GUI elements associated with the paused state.
     * @param dt Delta time since the last frame, used for smooth rendering.
     */
    virtual void draw(const float dt);

    /**
     * @brief Updates the paused state.
     *
     * Updates any animations or GUI elements displayed while the game is paused.
     * @param dt Delta time since the last frame, used for smooth updating.
     */
    virtual void update(const float dt);

    /**
     * @brief Handles user input for the paused state.
     *
     * Processes input events specific to the pause menu, allowing the player to
     * resume the game or interact with pause options.
     */
    virtual void handleInput();

     /**
     * @brief Retrieves information about the paused state.
     *
     * Provides details or an identifier of the current paused state.
     */
    void getState();

    /**
     * @brief Constructs a new GameStatePaused instance.
     *
     * @param game Pointer to the main Game instance.
     * @param state Pointer to the previous game state to be resumed.
     */
    GameStatePaused(Game *game, GameState* state);
};

#endif /* GAMESTATEPAUSED_H */