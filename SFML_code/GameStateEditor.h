#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Map.h"
#include "City.h"
#include "Gui.h"
#include "Caretaker.h"

enum class ActionState { NONE, PANNING, SELECTING };

class GameStateEditor : public GameState
{
    private:

    ActionState actionState;

    sf::View gameView;
    sf::View guiView;
    sf::Sprite pauseSprite;

    int day = 0;

	City city;
    Caretaker* undos = new Caretaker();

	sf::Vector2i panningAnchor;
    float zoomLevel;

    sf::Vector2i selectionStart;
    sf::Vector2i selectionEnd;
 
    Tile* currentTile;

    std::map<std::string, Gui> guiSystem;
    std::map<std::string, Gui> guiPauseSystem;

    bool paused = false;
    void pauseGame();

    Map* beginMap;
    
    public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    void getState();

    GameStateEditor(Game* game);
};

#endif /* GAME_STATE_EDITOR_HPP */
