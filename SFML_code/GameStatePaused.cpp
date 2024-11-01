#include <utility>
#include "GameStatePaused.h"
#include "GameStateEditor.h"
#include "GameState.h"

#include <SFML/Graphics.hpp>

void GameStatePaused::getState()
{
    std::cout << "Paused";
}

void GameStatePaused::draw(const float dt)
{
    this->game->window.setView(this->view);

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);

    for(auto gui : this->guiSystem) this->game->window.draw(gui.second);

}

void GameStatePaused::update(const float dt)
{
}


void GameStatePaused::handleInput()
{
    bool resumeGame = false;
    sf::Event event;

    sf::Vector2f mousePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->view);

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
            {
                game->window.close();
                break;
            }
            /* Resize the window */
            case sf::Event::Resized:
            {
                this->view.setSize(event.size.width, event.size.height);
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->view));
                sf::Vector2f pos = sf::Vector2f(event.size.width, event.size.height);
                pos *= 0.5f;
                pos = this->game->window.mapPixelToCoords(sf::Vector2i(pos), this->view);
                this->guiSystem.at("menu").setPosition(pos);
                this->game->background.setScale(
                    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            /* Highlight menu items */
            case sf::Event::MouseMoved:
            {
                this->guiSystem.at("menu").highlight(this->guiSystem.at("menu").getEntry(mousePos));
                break;
            }
            /* Click on menu items */
            // case sf::Event::MouseButtonPressed:
            // {
            //     if(event.mouseButton.button == sf::Mouse::Left)
            //     {
            //         std::string msg = this->guiSystem.at("menu").activate(mousePos);

            //         if(msg == "load_game")
            //         {
            //             this->loadgame();
            //         }
            //     }
            //     break;
            // }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape)
                {
                    this->game->window.close();
                }
                else if(event.key.code == sf::Keyboard::P)
                {
                    resumeGame = true;
                }
                break;
            }
            default: break;
        }
    }
    if(resumeGame)
    {
        this->resumeGame();
    }
}

void GameStatePaused::resumeGame()
{
    this->game->popState();
}

GameStatePaused::GameStatePaused(Game* game, GameState* s)
{
    this->state = s;
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);

	this->guiSystem.emplace("menu", Gui(sf::Vector2f(355, 32), 4, false, game->stylesheets.at("button"),
		{ std::make_pair("Press P to Resume Game", "resume_game") }));

	this->guiSystem.at("menu").setPosition(pos);
	this->guiSystem.at("menu").setOrigin(155, 32*1/2);
	this->guiSystem.at("menu").show();
}
