#pragma once

#include "GameState.h"


//Game state observer implementation----------------------------------------------------------------------------
class GameStateObserver : public Observer {
public:
	GameStateObserver(GameState* s);
	~GameStateObserver();
	void Update();
	void display();
private:
	GameState* _subject;
};