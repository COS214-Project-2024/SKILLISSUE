#include "Game.h"
#include "GameState.h"

#include <SFML/System.hpp>


void Game::loadFonts()
{
    sf::Font font;
    font.loadFromFile("../Data/media/font.ttf");
    this->fonts["main_font"] = font;

    return;
}

void Game::loadStylesheets()
{
    this->stylesheets["button"] = GuiStyle(&this->fonts.at("main_font"), 1,
                                           sf::Color(0xc6, 0xc6, 0xc6), sf::Color(0x94, 0x94, 0x94), sf::Color(0x00, 0x00, 0x00),
                                           sf::Color(0x61, 0x61, 0x61), sf::Color(0x94, 0x94, 0x94), sf::Color(0x00, 0x00, 0x00));
    this->stylesheets["text"] = GuiStyle(&this->fonts.at("main_font"), 0,
                                         sf::Color(0x00, 0x00, 0x00, 0x00), sf::Color(0x00, 0x00, 0x00), sf::Color(0xff, 0xff, 0xff),
                                         sf::Color(0x00, 0x00, 0x00, 0x00), sf::Color(0x00, 0x00, 0x00), sf::Color(0xff, 0x00, 0x00));

    return;
}

void Game::loadTiles()
{
    Animation staticAnim(0, 0, 1.0f);
    this->tileAtlas["grass"] = Factory.at("grass")->Create(texmgr.getRef("grass"), {staticAnim});
    this->tileAtlas["forest"] = Factory.at("forest")->Create(texmgr.getRef("forest"), {staticAnim});
    this->tileAtlas["water"] = Factory.at("water")->Create(texmgr.getRef("water"),{Animation(0, 3, 0.5f), Animation(0, 3, 0.5f), Animation(0, 3, 0.5f)});
    this->tileAtlas["residential"] = Factory.at("residential")->Create(texmgr.getRef("residential"), {staticAnim, staticAnim, staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["commercial"] = Factory.at("commercial")->Create(texmgr.getRef("commercial"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["industrial"] = Factory.at("industrial")->Create(texmgr.getRef("industrial"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["landmark"] = Factory.at("landmark")->Create(texmgr.getRef("landmark"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["firestation"] = Factory.at("firestation")->Create(texmgr.getRef("firestation"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["hospital"] = Factory.at("hospital")->Create(texmgr.getRef("hospital"), {staticAnim, staticAnim, staticAnim});
    this->tileAtlas["powerplant"] = Factory.at("powerplant")->Create(texmgr.getRef("powerplant"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["sewageplant"] = Factory.at("sewageplant")->Create(texmgr.getRef("sewageplant"), {staticAnim, staticAnim, staticAnim});
    this->tileAtlas["waterplant"] = Factory.at("waterplant")->Create(texmgr.getRef("waterplant"), {staticAnim, staticAnim, staticAnim});
    this->tileAtlas["wastemanagement"] = Factory.at("wastemanagement")->Create(texmgr.getRef("wastemanagement"), {staticAnim, staticAnim});
    this->tileAtlas["road"] = Factory.at("road")->Create(texmgr.getRef("road"),{staticAnim, staticAnim, staticAnim, staticAnim, 
                                                                staticAnim, staticAnim, staticAnim, staticAnim, 
                                                                    staticAnim, staticAnim, staticAnim});

    return;
}

void Game::loadTextures()
{
    texmgr.loadTexture("grass",         "../Data/media/grass.png");
    texmgr.loadTexture("forest",        "../Data/media/forest.png");
    texmgr.loadTexture("water",         "../Data/media/water.png");
    texmgr.loadTexture("residential",   "../Data/media/residential.png");
    texmgr.loadTexture("commercial",    "../Data/media/commercial.png");
    texmgr.loadTexture("industrial",    "../Data/media/industrial.png");
    texmgr.loadTexture("landmark",      "../Data/media/landmarks.png");
    texmgr.loadTexture("road",          "../Data/media/road.png");
    texmgr.loadTexture("firestation",   "../Data/media/firestation.png");
    texmgr.loadTexture("hospital",      "../Data/media/hospitals.png");
    texmgr.loadTexture("powerplant",    "../Data/media/powerplants.png");    
    texmgr.loadTexture("sewageplant",   "../Data/media/sewageplants.png");
    texmgr.loadTexture("powerplant",    "../Data/media/powerplants.png");
    texmgr.loadTexture("wastemanagement","../Data/media/wastemanagement.png");
    texmgr.loadTexture("waterplant","../Data/media/waterplants.png");
 
    texmgr.loadTexture("background",    "../Data/media/background.png");
}

void Game::loadFactories()
{
    this->Factory["grass"] = new GrassFactory();
    this->Factory["forest"] = new ForestFactory();
    this->Factory["water"] = new WaterFactory();
    this->Factory["residential"] = new ResidentialFactory();
    this->Factory["commercial"] = new CommercialFactory();
    this->Factory["industrial"] = new IndustrialFactory();
    this->Factory["landmark"] = new LandmarkFactory();
    this->Factory["firestation"] = new FirestationFactory();
    this->Factory["hospital"] = new HospitalFactory();
    this->Factory["powerplant"] = new PowerPlantFactory();
    this->Factory["sewageplant"] = new SewagePlantFactory();
    this->Factory["waterplant"] = new WaterPlantFactory();
    this->Factory["wastemanagement"] = new WasteManagementFactory();
    this->Factory["road"] = new RoadFactory();
    this->Factory["firestation"] = new FirestationFactory();
}


void Game::pushState(GameState* state)
{
    this->states.push(state);

    return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if(this->states.empty()) return NULL;
    return this->states.top();
}

void Game::gameLoop()
{
    sf::Clock clock;
    float dt;

    while(this->window.isOpen())
    {
        dt = clock.restart().asSeconds();

        if(peekState() == NULL) continue;
        // peekState()->getState();
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game()
{
    this->loadTextures();
    this->loadFactories();
    this->loadTiles();
    this->loadFonts();
	this->loadStylesheets();

    this->window.create(sf::VideoMode(800, 600), "City Builder");
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->texmgr.getRef("background"));
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}
