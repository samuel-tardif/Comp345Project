#pragma once

#include "Player.h"
#include "GameObservers.h"

//Player observer implementation----------------------------------------------------------------------------
class PlayerObserver : public Observer {
public:
	PlayerObserver(Player* s);
	~PlayerObserver();
	void Update();
	void display();
private:
	Player* _subject;
};