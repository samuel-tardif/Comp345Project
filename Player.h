/*-------------------------------------------------------------------------------------------
Code by Aman Vasani
ID: 40111703
Date : 21/02/2021
For COMP 345 -Assignment 1
------------------------------------------------------------------------------------------------*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Cards.h"
#include "Map.h"
#include "BidingFacility.h"


class Cards;
//class BiddingFacility;

class Player {

	private:
		int *coins;
		int *birthday;
		Hand *hand;

		int *cubes; //Armies
		int *disks; //Cities

		int *tokens;
		int* countries;
		std::string* name;
		BidingFacility *playerBid;

public:

	//Default constructor
	Player();

	//Parameterized constructor
	Player(std::string name);

	//Actions
	bool payCoin(int cost);
	void placeNewArmies(Map m, int numArmies, int index, int player);
	void MoveArmies(int nbarmy, Map &start, Map &stop);
	void MoveOverLand(int nbarmies, Map& start, Map& stop);
	void BuildCity(Map& cityplace);
	void DestroyArmy(Map &armyplace, Player& armyowner);
	void initializeHand();
	void printHand();
	//mutators
	void setName(std::string name);
	void SetCubes(int cubes);
	void SetDisks(int disks);
	void SetTokens(int tokens);
	void setCountries(int countries);
	void setCoins(int coins);
	void setBid();
	void setHand(vector<Cards> v);
	//accessors
	int getCoins();
	vector<Cards> getHand();
	void setHand(vector<Cards> v);
	int getCubes() const;
	int getDisks() const;
	int getTokens() const;
	std::string getName() const;
	int getPlayerID();
	//BiddingFacility* getBiddingFacility() const;
	~Player();
	//BiddingFacility *biddingFacility;
	
		
	

};
