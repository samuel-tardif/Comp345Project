/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 18/04/2021
For COMP 345 -Assignment 3
------------------------------------------------------------------------------------------------*/
//Implementation file of Game state, an observable that keeps track of current player

#include "GameState.h"
#include <utility>


//Operator = overload
GameState& GameState::operator=(const GameState& gs)
{
	currentPlayer = gs.getCurrentPlayer();
	return *this;
}


//Getter
Player* GameState::getCurrentPlayer() const
{
	return currentPlayer;
}

//Setter
void GameState::setCurrentPlayer(Player* p)
{
	currentPlayer = p;
	Notify();
}

//Default constructor
GameState::GameState()
{
	Player* currentPlayer = new Player();
}

//Copy constructor
GameState::GameState(const GameState& gs)
{
	Player* currentPlayer = new Player();
	currentPlayer = gs.getCurrentPlayer();
}

//Destructor
GameState::~GameState()
{
	delete currentPlayer;
}

//Stream insertion overload 
std::ostream& operator<<(std::ostream& output, const GameState& gs)
{
	cout << gs.getCurrentPlayer()->getName();
	return output;
}
