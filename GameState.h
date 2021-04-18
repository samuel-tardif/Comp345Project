/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/
//Header file of Game state, an observable that keeps track of current player

#pragma once

#include "Player.h"
#include "GameObservers.h"

class GameState : public Observable {


public:
	
	//= operator overload
	GameState& operator= (const GameState& gs);

	//Stream insertion overload
	friend std::ostream& operator<< (std::ostream& output, const GameState& gs);

	//Getter
	Player* getCurrentPlayer() const;

	//Setter
	void setCurrentPlayer(Player*);
	

	//Constructors
	//Default constructor
	GameState();

	//Copy constructor (as required)
	GameState(const GameState& gs);

	//Destructor
	~GameState();

private:

	//Variables
	Player* currentPlayer;
};