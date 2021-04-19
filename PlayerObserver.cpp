/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Impllementation file for an observer to link to player class

#pragma once

#include "PlayerObserver.h"

//Player observer implementation----------------------------------------------------------------------------
//Constructor
PlayerObserver::PlayerObserver(Player* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}


//Destructor
PlayerObserver::~PlayerObserver()
{
	_subject->Detach(this);
}

//Callls display
void PlayerObserver::Update()
{
	display();
}

//Print our player object when it is changed
void PlayerObserver::display()
{
	cout << "Display Player through observer" << endl;
	cout <<  "Coins : " << _subject->getCoins() << endl;
	cout << "Disks : " << _subject->getDisks() << endl;
	cout << "Cubes : " << _subject->getCubes() << endl;
}
