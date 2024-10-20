#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class GameEngine {

private:
	State gameState;
	CityCommand cityCommands[];

public:
	void startGame(Player* player);

	GameMemento save();

	void load(GameMemento* saveFile);
};

#endif
