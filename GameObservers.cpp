/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Impementation of Observer and Observable 
//A3 part 2
#pragma once

#include "GameObservers.h"
#include <iostream>
using namespace std;


//Base observer implementation-------------------------------------------------------------------------------
Observer::Observer() {
};
Observer::~Observer() {
};


//Base observable implementation-------------------------------------------------------------------------------
//Default constructor
Observable::Observable() {
	_observers = new list<Observer*>;
}
//Destructor
Observable::~Observable() {
	delete _observers;
}

//Attach
void Observable::Attach(Observer* o) {
	_observers->push_back(o);
};

//Detach
void Observable::Detach(Observer* o) {
	_observers->remove(o);
};

//Alerts our observers
void Observable::Notify() {
	//cout << "In notify method" << endl;
	list<Observer*>::iterator i = _observers->begin();
	for (; i != _observers->end(); ++i){
		(*i)->Update();
		//cout << "CalledUpdate" << endl;
	}
		
};
/*




*/


