#pragma once

#include "map.h"
#include <list>

using namespace std;

//Base observer implementation-------------------------------------------------------------------------------
class Observer {
public:
	~Observer();
	virtual void Update() = 0;
protected:
	Observer();
};


//Base observable implementation-------------------------------------------------------------------------------
class Observable {
public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Observable();
	~Observable();
private:
	list<Observer*>* _observers;
};

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


//Player observer implementation----------------------------------------------------------------------------




//Game state observer implementation----------------------------------------------------------------------------