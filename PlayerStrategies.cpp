/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <string>
#include "PlayerStrategies.h"

std::string GreedyComputer::selectAction(GameState& state, std::vector<Cards*>& cards, int index, int turn)
{
	std::string action = *(state.players->at(index)->gethand()->at(turn)->getAction());
}

std::string HumanPlayer::selectAction(GameState& state, std::vector<Cards*>& cards, int index, int turn)
{
	std::string action = *(state.players->at(index)->gethand()->at(turn)->getAction());
}

std::string ModerateComputer::selectAction(GameState& state, std::vector<Cards*>& cards, int index, int turn)
{
	std::string action = *(state.players->at(index)->gethand()->at(turn)->getAction());
}


