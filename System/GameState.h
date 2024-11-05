#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"
#include <iostream>

/**
 * @class GameState
 * @brief Abstract base class representing a state in the game.
 *
 * The GameState class provides a blueprint for specific game states by defining
 * common methods for drawing, updating, and handling input. Each state is associated 
 * with a `Game` instance and must implement the abstract methods defined here.
 */
class GameState
{
    public:

    /** 
     * @brief Pointer to the main Game instance.
     *
     * Provides access to the main Game object, allowing each game state to interact 
     * with the game's resources and overall state management.
     */
    Game* game;
    
    /**
     * @brief Draws the current state.
     * 
     * This pure virtual function must be implemented by each derived state class.
     * It handles all rendering tasks specific to the state.
     * 
     * @param dt Delta time since the last frame, used for smooth rendering.
     */
    virtual void draw(const float dt) = 0;

    /**
     * @brief Updates the state.
     * 
     * This pure virtual function must be implemented by each derived state class.
     * It contains the logic to update the state based on elapsed time.
     * 
     * @param dt Delta time since the last frame, used for smooth updating.
     */
    virtual void update(const float dt) = 0;

    /**
     * @brief Handles user input for the state.
     * 
     * This pure virtual function must be implemented by each derived state class.
     * It processes and responds to user inputs specific to the state.
     */
    virtual void handleInput() = 0;

    /**
     * @brief Retrieves the state type or name.
     * 
     * This pure virtual function should be implemented to provide a way to identify
     * or get information about the current state.
     */
    virtual void getState() = 0;
};

#endif /* GAME_STATE_HPP */