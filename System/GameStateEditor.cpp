#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "GameStateEditor.h"
#include "GameStatePaused.h"
#include "TaxPolicy.h"
#include "LowTax.h"
#include "MidTax.h"
#include "HighTax.h"
#include "ResourceManager.h"
#include "DistributeResources.h"
#include <bits/basic_string.h>
#include <iostream>

void GameStateEditor::getState()
{
    std::cout << "running";
}

#include "CityMediator.h"

void GameStateEditor::draw(const float dt)
{
    this->game->window.clear(sf::Color::Black);

    this->game->window.setView(this->guiView);
	
    this->game->window.draw(this->game->background);

    this->game->window.setView(this->gameView);
    this->city.map->draw(this->game->window, dt);

	this->game->window.setView(this->guiView);
	for(auto gui : this->guiSystem) this->game->window.draw(gui.second);

	if(this->paused)
	{
		pauseSprite.setTexture(game->texmgr.getRef("background"));
		pauseSprite.setColor(sf::Color(255,255,255,128));
		this->game->window.draw(pauseSprite);
		this->game->window.setView(this->guiView);
		for(auto gui : this->guiPauseSystem) this->game->window.draw(gui.second);
		this->guiPauseSystem.at("GamePaused").show();
	}
	
}

void GameStateEditor::update(const float dt)
{
	if(paused)
	{
		DistributeResources DR(this->city.map);
    	DR.execute();


		/* Update the info bar at the bottom of the screen */
		this->guiSystem.at("infoBar").setEntryText(0, "Day: " + std::to_string(this->city.day));
		this->guiSystem.at("infoBar").setEntryText(1, "$" + std::to_string(long(this->city.funds)));
		this->guiSystem.at("infoBar").setEntryText(2, std::to_string(long(this->city.population)) + " (" + std::to_string(long(this->city.getHomeless())) + ")");
		this->guiSystem.at("infoBar").setEntryText(3, std::to_string(long(this->city.employable)) + " (" + std::to_string(long(this->city.getUnemployed())) + ")");
		this->guiSystem.at("infoBar").setEntryText(4, "Tax Rate: " + this->city.getTaxPolicy());
		this->guiSystem.at("infoBar").setEntryText(5, tileTypeToStr(currentTile->tileType));

		/* Update the resource stats at the top left of the screen */
		this->guiSystem.at("resourceStats").setEntryText(0, "Satisfaction: " + std::to_string(long(this->city.satisfaction)) + "%");
		this->guiSystem.at("resourceStats").setEntryText(1, "Power Production: " + std::to_string(proxy.getPower()));
		this->guiSystem.at("resourceStats").setEntryText(2, "Power Consumption: " + std::to_string(proxy.getPowerConsumption()));
		this->guiSystem.at("resourceStats").setEntryText(3, "Power Usage: " + std::to_string(long(proxy.getPowerUsage())) + "%");
		this->guiSystem.at("resourceStats").setEntryText(4, "Water Production: " + std::to_string(proxy.getWater()));
		this->guiSystem.at("resourceStats").setEntryText(5, "Water Consumption: " + std::to_string(proxy.getWaterConsumption()));
		this->guiSystem.at("resourceStats").setEntryText(6, "Water Usage: " + std::to_string(long(proxy.getWaterUsage())) + "%");
		this->guiSystem.at("resourceStats").setEntryText(7, "Sewage Production: " + std::to_string(proxy.getSewage()));
		this->guiSystem.at("resourceStats").setEntryText(8, "Sewage Consumption: " + std::to_string(proxy.getSewageConsumption()));
		this->guiSystem.at("resourceStats").setEntryText(9, "Sewage Usage: " + std::to_string(long(proxy.getSewageUsage())) + "%");
		this->guiSystem.at("resourceStats").setEntryText(10, "Waste limit: " + std::to_string(proxy.getWaste()));
		this->guiSystem.at("resourceStats").setEntryText(11, "Waste production: " + std::to_string(proxy.getWaste()));
		this->guiSystem.at("resourceStats").setEntryText(12, "Waste recycled: " + std::to_string(long(proxy.getWasteUsage())) + "%");
	}
	else
	{
		this->city.update(dt);
		if(this->city.day != day)
		{
			undos->storeMemento(this->city.createMemento());
			day = this->city.day;
		}

		/* Update the info bar at the bottom of the screen */
		this->guiSystem.at("infoBar").setEntryText(0, "Day: " + std::to_string(this->city.day));
		this->guiSystem.at("infoBar").setEntryText(1, "$" + std::to_string(long(this->city.funds)));
		this->guiSystem.at("infoBar").setEntryText(2, std::to_string(long(this->city.population)) + " (" + std::to_string(long(this->city.getHomeless())) + ")");
		this->guiSystem.at("infoBar").setEntryText(3, std::to_string(long(this->city.employable)) + " (" + std::to_string(long(this->city.getUnemployed())) + ")");
		this->guiSystem.at("infoBar").setEntryText(4, "Tax Rate: " + this->city.getTaxPolicy());
		this->guiSystem.at("infoBar").setEntryText(5, tileTypeToStr(currentTile->tileType));

		/* Update the resource stats at the top left of the screen */
		this->guiSystem.at("resourceStats").setEntryText(0, "Satisfaction: " + std::to_string(long(this->city.satisfaction)) + "%");
		this->guiSystem.at("resourceStats").setEntryText(1, "Power Production: " + std::to_string(proxy.getPower()));
		this->guiSystem.at("resourceStats").setEntryText(2, "Power Consumption: " + std::to_string(proxy.getPowerConsumption()));
		this->guiSystem.at("resourceStats").setEntryText(3, "Power Usage: " + std::to_string(long(proxy.getPowerUsage())) + "%");
		this->guiSystem.at("resourceStats").setEntryText(4, "Water Production: " + std::to_string(proxy.getWater()));
		this->guiSystem.at("resourceStats").setEntryText(5, "Water Consumption: " + std::to_string(proxy.getWaterConsumption()));
		this->guiSystem.at("resourceStats").setEntryText(6, "Water Usage: " + std::to_string(long(proxy.getWaterUsage())) + "%");
		this->guiSystem.at("resourceStats").setEntryText(7, "Sewage Production: " + std::to_string(proxy.getSewage()));
		this->guiSystem.at("resourceStats").setEntryText(8, "Sewage Consumption: " + std::to_string(proxy.getSewageConsumption()));
		this->guiSystem.at("resourceStats").setEntryText(9, "Sewage Usage: " + std::to_string(long(proxy.getSewageUsage())) + "%");
		this->guiSystem.at("resourceStats").setEntryText(10, "Waste limit: " + std::to_string(proxy.getWaste()));
		this->guiSystem.at("resourceStats").setEntryText(11, "Waste production: " + std::to_string(proxy.getWaste()));
		this->guiSystem.at("resourceStats").setEntryText(12, "Waste recycled: " + std::to_string(long(proxy.getWasteUsage())) + "%");

		/* Highlight entries of the right click context menu */
		this->guiSystem.at("rightClickMenu").highlight(this->guiSystem.at("rightClickMenu").getEntry(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->guiView)));

		/* Highlight entries of the right click context menu */
		this->guiSystem.at("TaxMenu").highlight(this->guiSystem.at("TaxMenu")
													.getEntry(this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->guiView)));
	}
	return;
}

void GameStateEditor::handleInput()
{
		//Turn this the button logic into commands
		 //button.setCommand()
	sf::Event event;

    sf::Vector2f guiPos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->guiView);
	sf::Vector2f gamePos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->gameView);
	
	while(this->game->window.pollEvent(event))
	{
		if(paused)
		{
			switch(event.type)
			{
				/* Close the window */
				case sf::Event::Closed:
				{
				this->game->window.close();
				break;
				}
				/* Resize the window */
				case sf::Event::Resized:
				{
					gameView.setSize(event.size.width, event.size.height);
					gameView.zoom(zoomLevel);
					guiView.setSize(event.size.width, event.size.height);
					this->guiSystem.at("infoBar").setDimensions(sf::Vector2f(event.size.width / this->guiSystem.at("infoBar").entries.size(), 16));
					this->guiSystem.at("infoBar").setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, event.size.height - 16), this->guiView));
					this->guiSystem.at("infoBar").show();

					this->guiSystem.at("resourceStats").setDimensions(sf::Vector2f(225, 16));
					this->guiSystem.at("resourceStats").setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
					this->guiSystem.at("resourceStats").show();

					sf::Vector2f pos = sf::Vector2f(event.size.width, event.size.height);
                	pos *= 0.5f;
                	pos = this->game->window.mapPixelToCoords(sf::Vector2i(pos), this->guiView);
                	this->guiPauseSystem.at("GamePaused").setPosition(pos);
					this->guiPauseSystem.at("GamePaused").show();
					
					this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
					this->pauseSprite.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
					this->game->background.setScale(
						float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
						float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
					this->pauseSprite.setScale(
						float(event.size.width) / float(this->pauseSprite.getTexture()->getSize().x),
						float(event.size.height) / float(this->pauseSprite.getTexture()->getSize().y));
					break;
				}
				case sf::Event::KeyPressed:
				{
					if (event.key.code == sf::Keyboard::Escape)
					{
						this->game->window.close();
					}
					else if (event.key.code == sf::Keyboard::U)
					{
						//undo operation
						this->city.loadMemento(undos->retrieveMemento());
					}
					else if (event.key.code == sf::Keyboard::P)
					{
						// this->pauseGame();
						paused = false;
					}
					break;
				}
				default:
					break;
			}
		}
		else
		{
			switch (event.type)
			{
			case sf::Event::MouseMoved:
			{
				/* Pan the camera */
				if (this->actionState == ActionState::PANNING)
				{
					sf::Vector2f pos = sf::Vector2f(sf::Mouse::getPosition(this->game->window) - this->panningAnchor);
					gameView.move(-1.0f * pos * this->zoomLevel);
					panningAnchor = sf::Mouse::getPosition(this->game->window);
				}
				/* Select tiles */
				else if (actionState == ActionState::SELECTING)
				{
					sf::Vector2f pos = this->game->window.mapPixelToCoords(sf::Mouse::getPosition(this->game->window), this->gameView);
					selectionEnd.x = pos.y / (this->city.map->tileSize) + pos.x / (2 * this->city.map->tileSize) - this->city.map->width * 0.5 - 0.5;
					selectionEnd.y = pos.y / (this->city.map->tileSize) - pos.x / (2 * this->city.map->tileSize) + this->city.map->width * 0.5 + 0.5;

					this->city.map->clearSelected();
					if (this->currentTile->tileType == TileType::GRASS)
					{
						this->city.map->select(selectionStart, selectionEnd, {this->currentTile->tileType, TileType::WATER});
					}
					else
					{
						this->city.map->select(selectionStart, selectionEnd,
						    {
						        this->currentTile->tileType,    TileType::FOREST,
						        TileType::WATER,                TileType::ROAD,
						        TileType::RESIDENTIAL,          TileType::COMMERCIAL,
						        TileType::INDUSTRIAL,			TileType::LANDMARK,
								TileType::FIRESTATION, 			TileType::HOSPITAL, 			
								TileType::POWERPLANT,			TileType::SEWAGEPLANT,			
								TileType::WATERPLANT,			TileType::WASTEMANAGEMENT

						    });
				    }
				    
				    this->guiSystem.at("selectionCostText").setEntryText(0, "$" + std::to_string(this->currentTile->cost * this->city.map->numSelected));
					if(this->city.funds <= this->city.map->numSelected * this->currentTile->cost)
						this->guiSystem.at("selectionCostText").highlight(0);
					else
						this->guiSystem.at("selectionCostText").highlight(-1);
					this->guiSystem.at("selectionCostText").setPosition(guiPos + sf::Vector2f(16, -16));
					this->guiSystem.at("selectionCostText").show();
				}
				/* Highlight entries of the right click context menu */
				this->guiSystem.at("rightClickMenu").highlight(this->guiSystem.at("rightClickMenu").getEntry(guiPos));
				/* Highlight entries of the tax menu */
				this->guiSystem.at("TaxMenu").highlight(this->guiSystem.at("TaxMenu").getEntry(guiPos));
				break;
			}
			case sf::Event::MouseButtonPressed:
			{
				/* Start panning */
				if (event.mouseButton.button == sf::Mouse::Middle)
				{
					this->guiSystem.at("rightClickMenu").hide();
					this->guiSystem.at("TaxMenu").hide();
					this->guiSystem.at("selectionCostText").hide();

					if (this->actionState != ActionState::PANNING)
					{
						this->actionState = ActionState::PANNING;
						this->panningAnchor = sf::Mouse::getPosition(this->game->window);
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					/* Select a context menu entry */
					if (this->guiSystem.at("rightClickMenu").visible == true)
					{
						std::string msg = this->guiSystem.at("rightClickMenu").activate(guiPos);
						if (msg != "flatten" && msg != "null")
						{
							this->currentTile = this->game->tileAtlas.at(msg);
						}
						this->guiSystem.at("rightClickMenu").hide();
					}
					/* Select a tax menu entry */
					else if (this->guiSystem.at("TaxMenu").visible == true)
					{
						std::string msg = this->guiSystem.at("TaxMenu").activate(guiPos);
						if (msg == "lowtax")
						{
							this->city.setTaxPolicy(new LowTax());
						}
						else if (msg == "midtax")
						{
							this->city.setTaxPolicy(new MidTax());
						}
						else if (msg == "hightax")
						{
							this->city.setTaxPolicy(new HighTax());
						}
						this->guiSystem.at("TaxMenu").hide();
					}
					/* Select map tile */
					else
					{
						/* Select map tile */
						if (this->actionState != ActionState::SELECTING)
						{
							this->actionState = ActionState::SELECTING;
							selectionStart.x = gamePos.y / (this->city.map->tileSize) + gamePos.x / (2 * this->city.map->tileSize) - this->city.map->width * 0.5 - 0.5;
							selectionStart.y = gamePos.y / (this->city.map->tileSize) - gamePos.x / (2 * this->city.map->tileSize) + this->city.map->width * 0.5 + 0.5;
						}
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Right)
				{
					/* Stop selecting */
					if (this->actionState == ActionState::SELECTING)
					{
						this->actionState = ActionState::NONE;
						this->guiSystem.at("selectionCostText").hide();
						this->city.map->clearSelected();
					}
					else
					{
						/* Open the tile select menu */
						sf::Vector2f pos = guiPos;

						if (pos.x > this->game->window.getSize().x - this->guiSystem.at("rightClickMenu").getSize().x)
						{
							pos -= sf::Vector2f(this->guiSystem.at("rightClickMenu").getSize().x, 0);
						}
						if (pos.y > this->game->window.getSize().y - this->guiSystem.at("rightClickMenu").getSize().y)
						{
							pos -= sf::Vector2f(0, this->guiSystem.at("rightClickMenu").getSize().y);
						}
						this->guiSystem.at("rightClickMenu").setPosition(pos);
						this->guiSystem.at("rightClickMenu").show();
					}
				}
				break;
			}
			case sf::Event::MouseButtonReleased:
			{
				/* Stop panning */
				if (event.mouseButton.button == sf::Mouse::Middle)
				{
					this->actionState = ActionState::NONE;
				}
				/* Stop selecting */
				else if (event.mouseButton.button == sf::Mouse::Left)
				{
					if (this->actionState == ActionState::SELECTING)
					{
						/* Replace tiles if enough funds and a tile is selected */
						if (this->currentTile != nullptr)
						{
							unsigned int cost = this->currentTile->cost * this->city.map->numSelected;
							if (this->city.funds >= cost)
							{
								this->city.bulldoze(*this->currentTile);
								this->city.funds -= this->currentTile->cost * this->city.map->numSelected;
								this->city.tileChanged();
							}
						}
						this->guiSystem.at("selectionCostText").hide();
						this->actionState = ActionState::NONE;
						this->city.map->clearSelected();
					}
				}
				break;
			}
			/* Zoom the view */
			case sf::Event::MouseWheelMoved:
			{
				if (event.mouseWheel.delta < 0)
				{
					gameView.zoom(2.0f);
					zoomLevel *= 2.0f;
				}
				else
				{
					gameView.zoom(0.5f);
					zoomLevel *= 0.5f;
				}
				break;
			}
			/* Close the window */
			case sf::Event::Closed:
			{
				this->game->window.close();
				break;
			}
			/* Resize the window */
			case sf::Event::Resized:
			{
				gameView.setSize(event.size.width, event.size.height);
				gameView.zoom(zoomLevel);
				guiView.setSize(event.size.width, event.size.height);

				this->guiSystem.at("infoBar").setDimensions(sf::Vector2f(event.size.width / this->guiSystem.at("infoBar").entries.size(), 16));
				this->guiSystem.at("infoBar").setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, event.size.height - 16), this->guiView));
				this->guiSystem.at("infoBar").show();

				this->guiSystem.at("resourceStats").setDimensions(sf::Vector2f(196, 16));
				this->guiSystem.at("resourceStats").setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
				this->guiSystem.at("resourceStats").show();

				this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0), this->guiView));
				this->game->background.setScale(
					float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
					float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
				break;
			}
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->game->window.close();
				}
				else if (event.key.code == sf::Keyboard::T)
				{
					/* Stop selecting */
					if (this->actionState == ActionState::SELECTING)
					{
						this->actionState = ActionState::NONE;
						this->guiSystem.at("selectionCostText").hide();
						this->city.map->clearSelected();
					}
					else
					{
						/* Open the tax menu */
						sf::Vector2f pos = guiPos;

						if (pos.x > this->game->window.getSize().x - this->guiSystem.at("TaxMenu").getSize().x)
						{
							pos -= sf::Vector2f(this->guiSystem.at("TaxMenu").getSize().x, 0);
						}
						if (pos.y > this->game->window.getSize().y - this->guiSystem.at("TaxMenu").getSize().y)
						{
							pos -= sf::Vector2f(0, this->guiSystem.at("TaxMenu").getSize().y);
						}
						this->guiSystem.at("TaxMenu").setPosition(pos);
						this->guiSystem.at("TaxMenu").show();
					}
				}
				else if (event.key.code == sf::Keyboard::P)
				{
					// this->pauseGame();
					paused = true;
				}
				else if (event.key.code == sf::Keyboard::M)
				{
					this->pauseGame();
				}
				break;
			}
			default:
				break;
			}
		}
	}

	return;
}

void GameStateEditor::pauseGame()
{
    this->game->pushState(new GameStatePaused(this->game, this));

    return;
}


GameStateEditor::GameStateEditor(Game* game)
{
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->guiView.setSize(pos);
	this->gameView.setSize(pos);
	pos *= 0.5f;
	this->guiView.setCenter(pos);
	this->gameView.setCenter(pos);

    this->city = City("city", this->game->tileSize, this->game->tileAtlas);
	// this->beginMap = this->city.map->clone();
	this->city.setCaretaker(this->undos);
	this->beginMap = this->city.map->clone();

	
	CityMediator* md = new CityMediator(&city);
	this->city.setMediator(md);

	this->city.shuffleTiles();

    /* Create gui elements */
	this->guiSystem.emplace("rightClickMenu", Gui(sf::Vector2f(196, 16), 2, false, this->game->stylesheets.at("button"),
		{
			std::make_pair("Flatten $" 			+ this->game->tileAtlas["grass"]->getCost(), "grass"),
			std::make_pair("Forest $" 			+ this->game->tileAtlas["forest"]->getCost(), "forest" ),
			std::make_pair("Residential Zone $" + this->game->tileAtlas["residential"]->getCost(), "residential"),
			std::make_pair("Commercial Zone $" 	+ this->game->tileAtlas["commercial"]->getCost(), "commercial"),
			std::make_pair("Industrial Zone $" 	+ this->game->tileAtlas["industrial"]->getCost(), "industrial"),
			std::make_pair("landmark Zone $" 	+ this->game->tileAtlas["landmark"]->getCost(), "landmark"),
			std::make_pair("Fire Station $" 	+ this->game->tileAtlas["firestation"]->getCost(), "firestation"),
			std::make_pair("Hospital $" 	+ this->game->tileAtlas["hospital"]->getCost(), "hospital"),
			std::make_pair("Power Plant $" 	+ this->game->tileAtlas["powerplant"]->getCost(), "powerplant"),
			std::make_pair("Sewage Plant $" 	+ this->game->tileAtlas["sewageplant"]->getCost(), "sewageplant"),
			std::make_pair("Water Plant $" 	+ this->game->tileAtlas["waterplant"]->getCost(), "waterplant"),
			std::make_pair("Waste Disposal $" 	+ this->game->tileAtlas["wastemanagement"]->getCost(), "wastemanagement"),
			std::make_pair("Road $" 			+ this->game->tileAtlas["road"]->getCost(), "road")
		}));

	this->guiSystem.emplace("TaxMenu", Gui(sf::Vector2f(196, 16), 2, false, this->game->stylesheets.at("button"),
		{
			std::make_pair("Set tax rate low", "lowtax"),
			std::make_pair("Set tax rate mid", "midtax"),
			std::make_pair("Set tax rate high", "hightax")
		}));

	this->guiSystem.emplace("selectionCostText", Gui(sf::Vector2f(196, 16), 0, false, this->game->stylesheets.at("text"),
		{ std::make_pair("", "") }));
	
	this->guiPauseSystem.emplace("GamePaused", Gui(sf::Vector2f(196, 16), -10, false, this->game->stylesheets.at("text"),
		{ std::make_pair("Game Paused", "Game_Paused") }));

	this->guiSystem.emplace("infoBar", Gui(sf::Vector2f(this->game->window.getSize().x / 6 , 16), 2, true, this->game->stylesheets.at("button"),
		{ 
			std::make_pair("time", "time"),
			std::make_pair("funds", "funds"),
			std::make_pair("population", "population"),
			std::make_pair("employment", "employment"),
			std::make_pair("Tax Policy:", "tax"),
			std::make_pair("current tile", "tile") 
		}));
	this->guiSystem.at("infoBar").setPosition(sf::Vector2f(0, this->game->window.getSize().y - 16));
	this->guiSystem.at("infoBar").show();

	this->guiSystem.emplace("resourceStats", Gui(sf::Vector2f(196 , 16), 2, false, this->game->stylesheets.at("button"),
		{ 
			std::make_pair("satisfaction", "satisfaction"),
			std::make_pair("power", "power"),
			std::make_pair("powerconsumed", "powerconsumed"),
			std::make_pair("powerUsed", "powerUsed"),
			std::make_pair("water", "water"),
			std::make_pair("waterConsumed", "waterConsumed"),
			std::make_pair("waterUsed", "waterUsed"),
			std::make_pair("sewage", "sewage"),
			std::make_pair("sewageConsumed", "sewageConsumed"),
			std::make_pair("sewageUsed", "sewageUsed"),
			std::make_pair("waste", "waste"),
			std::make_pair("wasteConsumed", "wasteConsumed"),
			std::make_pair("wasteUsed", "wasteUsed")
		}));
	this->guiSystem.at("resourceStats").setPosition(sf::Vector2f(0, 0));
	this->guiSystem.at("resourceStats").show();

	this->guiPauseSystem.at("GamePaused").setPosition(pos);
	this->guiPauseSystem.at("GamePaused").setOrigin(96, 32*1/2);
	
	this->zoomLevel = 1.0f;
	
	/* Centre the camera on the city.map */
	sf::Vector2f centre(this->city.map->width, this->city.map->height*0.5);
	centre *= float(this->city.map->tileSize);
	gameView.setCenter(centre);

    this->selectionStart = sf::Vector2i(0, 0);
    this->selectionEnd = sf::Vector2i(0, 0);
    
    this->currentTile = this->game->tileAtlas.at("grass");
	this->actionState = ActionState::NONE;
}
