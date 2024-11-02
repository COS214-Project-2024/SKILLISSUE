#include "Game.h"
#include "GameStateStart.h"
#include "City.h"
#include "Caretaker.h"
#include <iostream>

int main()
{
    // Initialize Game
    Game game;
    game.pushState(new GameStateStart(&game));
    game.gameLoop();

   

    return 0;
}
