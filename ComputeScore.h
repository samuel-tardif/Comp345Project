/*-------------------------------------------------------------------------------------------
Code by Samuel Tardif
ID: 40051573
Date : 228/03/2021
For COMP 345 -Assignment 2
------------------------------------------------------------------------------------------------*/

#pragma once
//Code for part 6, computeScore
//Includes
#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Cards.h"
#include "Map.h"


using namespace std;

//Main class for this portion of the work
class ComputeScore {
public:

	//Default constructor
	ComputeScore();

	//Copy constructor
	ComputeScore(const ComputeScore& copied);

	//Constructor with parameters
	ComputeScore(Player* p1, Player* p2, Map* m); //Changed from pointer to references

	//operator overloads =
	ComputeScore& operator= (const ComputeScore& bF);

	//operator overloads <<
	friend std::ostream& operator<< (std::ostream& output, const ComputeScore& m);

	//Destructor
	~ComputeScore();

	//Computes the scores and determines the winner
	Player* determineWinner();

	void tallyGameHand(std::vector<Cards*> p1GameHand, int* player1CardScore, int* playerElixir, Player* player);

	void tallyContinent(int contIndex, int* player1Continent, int* player2Continent, int* player1Territories, int* player2Territories, int* player1TotalArmies, int* player2TotalArmies);

	void DFS(int visiting, vector<bool>* visited, int* player1Territories, int* player2Territories, int* player1TotalArmies, int* player2TotalArmies);

	

	//Getters
	Player* getPlayer1() const;
	Player* getPlayer2() const;
	Map* getMap() const;

	//Setters
	void setPlayer1(Player* player1);
	void setPlayer2(Player* player2);
	void setMap(Map* map);
	

private:

	//Players 
	Player* player1;
	Player* player2;
	//Map
	Map* map;

};