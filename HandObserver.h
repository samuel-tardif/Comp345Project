/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Header file for an observer to link to hand object
//Disclaimer : COde heavily based on COMP 345 class notes

#pragma once

#include "GameObservers.h" 
#include "Hand.h"

//Hand observer implementation----------------------------------------------------------------------------
class HandObserver : public Observer {
public:
	HandObserver(Hand* s);
	~HandObserver();
	void Update();
	void display();
private:
	Hand* _subject;
};