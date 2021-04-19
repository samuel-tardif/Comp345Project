/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Header file for an observer to link to territory object
#pragma once

#include "GameObservers.h" 
#include "Map.h"

//Disclaimer : COde heavily based on COMP 345 class notes

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