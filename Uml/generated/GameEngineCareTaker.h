#ifndef GAMEENGINECARETAKER_H
#define GAMEENGINECARETAKER_H

class GameEngineCareTaker {

private:
	GameEngine* game;
	GameMemento Saves[];

public:
	GameMemento* loadMostRecentSave();

	GameMemento* getSave(int index);
};

#endif
