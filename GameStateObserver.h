
/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Header file for an observer to link to Game State object
#pragma once

#include "GameState.h"

//Disclaimer : Code heavily based on COMP 345 class notes

//Game state observer implementation----------------------------------------------------------------------------
class GameStateObserver : public Observer {
public:
	GameStateObserver(GameState* s);
	~GameStateObserver();
	void Update();
	void display();
private:
	GameState* _subject;
};