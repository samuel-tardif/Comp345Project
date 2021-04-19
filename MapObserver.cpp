#pragma once
#include "MapObserver.h"
//map observer implementation

MapObserver::MapObserver(Map* m) {
	map = m;
	map->Attach(this);
}

MapObserver::~MapObserver() {
	map->Detach(this);
}

void MapObserver::Update() {
	display();
}
void MapObserver::display() {
	cout << "Display Map through observer" << endl;
	vector<vector<Map::Territory*>>* v = map->getTerritoriesVector();
	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i).at(0) << " " << v->at(i).at(0)->getOwner() << endl;
	}
	cout << "Player has built a city" << endl;
}