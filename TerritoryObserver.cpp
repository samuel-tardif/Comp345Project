/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Header file for an observer to link to player class
//Disclaimer : Code heavily based on comp 345 class notes
#pragma once
#include "TerritoryObserver.h"

//Territory observer implementation----------------------------------------------------------------------------
//Constructor
TerritoryObserver::TerritoryObserver(Map::Territory* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}
//Destructor
TerritoryObserver::~TerritoryObserver()
{
	_subject->Detach(this);
}
//Update
void TerritoryObserver::Update()
{
	display();
}
//Prints on change
void TerritoryObserver::display()
{
	cout << "The territory has been updated as follows :" << endl;
	cout << *_subject << endl;
}