/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Implementation file for an observer to link to Hand  object

#pragma once

#include "HandObserver.h"
#include "Hand.h"

//Player observer implementation----------------------------------------------------------------------------

//Constructor
HandObserver::HandObserver(Hand* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}

//Destructor
HandObserver::~HandObserver()
{
	_subject->Detach(this);
}

//Update
void HandObserver::Update()
{
	display();
}

//Print hand when changed
void HandObserver::display()
{
	vector<Cards*> hand = _subject->getHand();
	cout << "Last card picked :  "<< endl << endl << "Name : " << hand.back()->getName()<< endl << "Action : "<< hand.back()->getAction() << endl << "Ability : "<< hand.back()->getAbility() << endl;

	cout << "Full hand:" << endl;
	for (int i = 0; i < hand.size(); i++) {
		cout << hand.at(i) << endl;
	}
}