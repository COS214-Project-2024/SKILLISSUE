#ifndef GAMEMEMENTO_H
#define GAMEMEMENTO_H

class GameMemento {

private:
	Save safeFile;

public:
	GameMemento(GameEngine* engine);

	Save getSave();
};

#endif
