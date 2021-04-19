#pragma once
#include "Map.h"
#include "GameObservers.h"

//Map Observer
class MapObserver : public Observer {
public:
	MapObserver(Map* m);
	~MapObserver();
	void Update();
	void display();
private:
	Map* map;
};