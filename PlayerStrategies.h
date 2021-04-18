/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#pragma once
#include "MapLoader.h"
#include "Player.h"
#include <string>
#include <iostream>
#include "GameState.h"

class PlayerStrategies {
public:
    virtual std::string selectAction(GameState& state, std::vector<Cards*>& cards, int index, int turn) = 0;
};

//Greedy Computer
class GreedyComputer : public PlayerStrategies {
public:
    virtual std::string selectAction(GameState& state, std::vector<Cards*>& cards, int index, int turn) = 0;
};

//Human Player
class HumanPlayer : public PlayerStrategies {
public:
    virtual std::string selectAction(GameState& state, std::vector<Cards*>& cards, int index, int turn) = 0;
};

//Moderate Computer
class ModerateComputer : public PlayerStrategies {
public:
    virtual std::string selectAction(GameState& state, std::vector<Cards*>& cards, int index, int turn) = 0;
};
