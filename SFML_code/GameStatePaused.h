#ifndef GAMESTATEPAUSED_H
#define GAMESTATEPAUSED_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Gui.h"
#include <map>
#include <string>


class GameStatePaused : public GameState
{
private:
    sf::View view;
    std::map<std::string, Gui> guiSystem;
    GameState* state;
    void resumeGame();

public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    void getState();

    GameStatePaused(Game *game, GameState* state);
};

#endif /* GAMESTATEPAUSED_H */