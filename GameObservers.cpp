#include "GameObservers.h"
#include <iostream>
using namespace std;


//Base observer implementation-------------------------------------------------------------------------------
Observer::Observer() {
};
Observer::~Observer() {
};


//Base observable implementation-------------------------------------------------------------------------------
Observable::Observable() {
	_observers = new list<Observer*>;
}
Observable::~Observable() {
	delete _observers;
}
void Observable::Attach(Observer* o) {
	_observers->push_back(o);
};
void Observable::Detach(Observer* o) {
	_observers->remove(o);
};
void Observable::Notify() {
	list<Observer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i)
		(*i)->Update();
};

//Territory observer implementation----------------------------------------------------------------------------

TerritoryObserver::TerritoryObserver(Map::Territory* s)
{
}

TerritoryObserver::~TerritoryObserver()
{
}

void TerritoryObserver::Update()
{
}

void TerritoryObserver::display()
{
}

//Player observer implementation----------------------------------------------------------------------------

PlayerObserver::PlayerObserver(Player* s)
{
}

PlayerObserver::~PlayerObserver()
{
}

void PlayerObserver::Update()
{
}

void PlayerObserver::display()
{
}


//Game state observer implementation----------------------------------------------------------------------------
GameStateObserver::GameStateObserver(GameState* s)
{
}

GameStateObserver::~GameStateObserver()
{
}

void GameStateObserver::Update()
{
}

void GameStateObserver::display()
{
}
