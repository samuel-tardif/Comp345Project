#pragma once

#include "GameObservers.h" 
#include "Map.h"

//Territory observer implementation----------------------------------------------------------------------------
class TerritoryObserver : public Observer {
public:
	TerritoryObserver(Map::Territory* s);
	~TerritoryObserver();
	void Update();
	void display();
private:
	Map::Territory* _subject;
};