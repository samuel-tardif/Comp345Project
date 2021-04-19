/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Header file for an observer to link to player class
//Disclaimer : COde heavily based on COMP 345 class notes

#pragma once

#include "Player.h"
#include "GameObservers.h"

//Player observer implementation----------------------------------------------------------------------------
class PlayerObserver : public Observer {
public:
	PlayerObserver(Player* s);
	~PlayerObserver();
	void Update();
	void display();
private:
	Player* _subject;
};