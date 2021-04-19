/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//This is the header file for part 2, bseevers and observable
//Specific impklementaation for specific classes can be found in GameStateObserver, PlayerObserver, HandObserver and TerritoryObserver
//Disclaimer : COde heavily based on COMP 345 class notes

#pragma once

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

/*



*/



