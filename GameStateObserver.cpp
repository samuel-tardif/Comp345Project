/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/

//Implementation file for an observer to link to GameState class
//Disclaimer : COde heavily based on COMP 345 class notes

#pragma once

#include "GameStateObserver.h"

//Game state observer implementation----------------------------------------------------------------------------
//Constructor
GameStateObserver::GameStateObserver(GameState* s)
{
	//Upon instantiation, attaches itself
	_subject = s;
	_subject->Attach(this);
}

//Destructor
GameStateObserver::~GameStateObserver()
{
	_subject->Detach(this);
}

//Update
void GameStateObserver::Update()
{
	display();
}

//Print object
void GameStateObserver::display()
{
	cout << "display GameState with observer" << endl;
	cout << "********************************************************************************************" << endl;
	cout << "Player turn : " << *_subject << endl;
	cout << "********************************************************************************************" << endl;
}